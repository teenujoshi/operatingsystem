//==linux kernal using kernal version,cpu type and model

// #include <iostream>
// #include <stdlib.h>
// #include <stdio.h>
// using namespace std;
// int main(){
// 	cout << endl << "The kernel version is : " << endl;
// 	system("cat /proc/sys/kernel/osrelease");
// 	cout << endl << "The cpu space :  "<< endl;
// 	system("cat /proc/cpuinfo | awk 'NR==3,NR==4{print}'\n");
// 	cout << endl << "amount of cpu time since system was last booted"<<endl;
// 	system("cat /proc/uptime");
// 	cout << endl << "the configured memory is "<< endl;
// 	system("cat /proc/meminfo | awk 'NR==1 {print $2}' \n");
// 	cout << endl << "Amount of free memory is :" << endl;
// 	system("cat /proc/meminfo | awk 'NR==2 {print $2}' \n");
// 	cout << endl << "Amount of used memory: "<< endl;
// 	system("cat /proc/meminfo | awk '{if(NR==1) a = $2 ; if(NR==2) b = $2;} END {print a-b}' \n");
// 	return 0;
// }

// #include <iostream>
// using namespace std;
// void findWaitingTime(int processes[] , int n , int bt[] , int wt[] , int at[] , int tat[]){
// 		int t = 0;
//         bool done[n];
// 		for(int i =0  ; i<n ; i++) done[i] = false;
// 		for(int j = 0 ; j<n ; j++){
// 				if(at[j] <= t  && done[j] == false){
// 					done[j] = true;
// 					t += bt[j];
// 					wt[j] = t - at[j] - bt[j];
// 					tat[j] = bt[j] + wt[j];
// 					j = -1;
// 				}
// 		}
// }
// void sort(int processes[] , int at[] , int bt[] , int n){
// 		for(int i = 0 ; i<n-1 ; i++){
// 			for(int j = 0 ; j<n-i-1 ; j++){
// 				if(bt[j] > bt[j+1]){
					
// 					int temp = at[j];
// 					at[j] = at[j+1];
// 					at[j+1] = temp;
					
// 					temp = bt[j];
// 					bt[j] = bt[j+1];
// 					bt[j+1] = temp;
					
// 					temp = processes[j];
// 					processes[j] = processes[j+1];
// 					processes[j+1] = temp;
// 				}
// 			}
// 		}
// }
// void findAverageTime(int processes[] , int n , int bt[] , int at[]){
// 		int wt[n] , tat[n] , total_wt = 0 , total_tat = 0;
// 		findWaitingTime(processes , n , bt ,wt , at , tat);
// 		cout << "Processes  " <<" Arrival Time " <<  "  Burst Time  " << "  Waiting Time  "<< "Turn Around Time" << endl;
// 		for(int i = 0 ; i<n ; i++){
// 				total_wt += wt[i];
// 				total_tat += tat[i];
// 				cout << "  " << processes[i] << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] <<"\t\t"<< tat[i] << endl; 
// 		}
// 		cout << "average waiting time = " << (float)total_wt/n << endl;
// 		cout << "average turn around time = " << (float)total_tat/n << endl;
// }
// int main(){
// 	int n;
// 	cout << "enter the number of processes : ";
// 	cin >>  n;
// 	int processes[n];
// 	for(int i =0  ; i<n ; i++) processes[i] = i+1;
// 	int bt[n] , at[n] , priority[n];
// 	for(int i =0 ; i<n ; i++){
// 		cout << "Enter the burst time for " << i+1 << " process: ";
// 		cin >> bt[i];
// 	}
// 	for(int i =0 ; i<n ; i++){
// 		cout << "Enter the arrival time for " << i+1 << " process: ";
// 		cin >> at[i];
// 	}
// 	sort(processes , at , bt  , n);
// 	findAverageTime(processes , n , bt , at );
// 	return 0;
	
// }



//====fitsss

// #include <iostream>
// #include <time.h>
// using namespace std;
// class Hole{
//     public:
//         int size;
//         int starting_location;
//         int ending_location;
//         Hole(){
//             size = 0;
//             starting_location = 0;
//             ending_location = 0;
//         }
//         Hole(int sz ,int sl ,int el){
//             size = sz;
//             starting_location = sl;
//             ending_location = el;
//         }
// };
// class Findhole{
//     public:
//         Hole * holes;
//         int n;
//         //constructor to initialize the holes array and the data members of each hole
//         Findhole(){
//             cout << "Enter the number of holes : ";
//             cin >> n;
//             holes = new Hole[n];
//             for(int i = 0 ; i < n ; i++){
//                 cout << "Enter the size of " << i+1 << " hole " ;
//                 int sz;
//                 cin >> sz;
//                 // generating a random starting location of hole
//                 int starting_mem = rand()%30;
//                 if(i != 0) starting_mem = holes[i-1].ending_location + starting_mem;
//                 holes[i] = Hole(sz , starting_mem , starting_mem + sz);
//             }
//         }
//         //function to display only those holes whose size is greater than 0
//         void displayHoles(){
//             cout << endl;
//             for(int i = 0 ; i < n ; i++){
//                 if(holes[i].size != 0){
//                     cout << i+1 << " hole of size " << holes[i].size <<  "  available from memory " << holes[i].starting_location << " to " << holes[i].ending_location << endl;
//                 }
//             }
//             cout << endl;
//         }
//         void firstFit(int process){
//             for(int i = 0  ; i < n ; i++){
//                 if(holes[i].size >= process){
//                     cout << "First fit of size " << holes[i].size << " found, allocating memory " << holes[i].starting_location << " till " << holes[i].starting_location + process << " to the process " << endl;
//                     //changing the corresponding hole attributes
//                     holes[i].starting_location += process; 
//                     holes[i].size -= process;
//                     return;
//                 }
//             }
//             cout << "Cannot find the space to allocate the process" << endl;
//         }
//         void bestfit(int process){
//             int index = -1;
//             //finding an initial fit for process
//             for(int i = 0  ; i < n ; i++){
//                 if(holes[i].size >= process){
//                    index = i;
//                    break;
//                 }
//             }
//             int currsize = holes[index].size;
//             int ansindex = index;
//             //finding the best fit for process
//             for(int i = index+1 ; i<n ; i++){
//                 if(holes[i].size >= process && holes[i].size < currsize){
//                     currsize = holes[i].size;
//                     ansindex = i;
//                 }
//             }
//             if(index == -1){
//                 cout << "Cannot find the space to allocate the process: " << endl;
//             }
//             else{
//                 cout << "best fit of size " << holes[ansindex].size << " found, allocating  memory " << holes[ansindex].starting_location << " till " << holes[ansindex].starting_location + process << " to the process " << endl;
//                 //updating corresponding hole attributes
//                 holes[ansindex].starting_location += process; 
//                 holes[ansindex].size -= process;
//             }
//         }
//         void worstfit(int process){
//             int maxi = 0;
//             int index;
//             //finding the maximum hole
//             for(int i = 0 ; i < n ; i++){
//                 if(holes[i].size >= maxi){
//                     maxi = holes[i].size;
//                     index = i;
//                 }
//             }
//             if(maxi == 0){
//                 cout << "Cannot find the space to allocate the process: " << endl;
//             }
//             else{
//                 cout << "worst fit of size " << holes[index].size << " found, allocating  memory " << holes[index].starting_location << " till " << holes[index].starting_location + process << " to the process " << endl;
//                 //changing the corresponding hole attributes
//                 holes[index].starting_location += process; 
//                 holes[index].size -= process; 
//             }
//         }
// };
// int main(){
//     srand(time(NULL));
//     Findhole f;
//     cout << "Dispaying all holes : ";
//     f.displayHoles();
//     int n; 
//     cout << "enter the number of processes: "; cin >> n;
//     for(int i = 0 ; i < n ; i++){
//         cout << "Enter the process size for " << i+1 << " process: ";
//         int sz; cin >> sz;
//         cout << "choose memory allocation method : \n1.First Fit\n2.Best Fit\n3.Worst Fit" << endl;
//         cout << "Your choice : ";
//         int choice; cin >> choice;
//         cout << endl;
//         //taking user choice to choose the fit
//         if(choice == 1){
//             f.firstFit(sz);
//         }
//         else if(choice == 2){
//             f.bestfit(sz);
//         }
//         else if(choice == 3){
//             f.worstfit(sz);
//         }
//         else{
//             cout << "Wrong choice entered , exiting program ";
//             exit(100);
//         }
//         //displaying all holes after assigning process to memory
//         f.displayHoles();
//     }
// }

// #include <iostream>
// #include <stdlib.h>
// #include <stdio.h>
// using namespace std;
// int main(){
//     cout<<endl<<"the kernel version is: "<<endl;
//     system("cat/proc/sys/kernel/osrelease");
//     cout<<"the cpu space: "<<endl;
//     system("cat/proc/cpuinfo|awk 'NR==3,NR==4{print}'\n");
//     cout<<"amount of cpu time since system was last booted"<<endl;
//     system("cat/proc/uptime");
//     cout<<"configured memory is: "<<endl;
//     system("cat/proc/meminfo|awk 'NR==1{print $2}'\n");
//     cout<<"free memory is: "<<endl;
//     system("cat/proc/meminfo|awk 'NR==2{print $2}'\n");
//     cout<<"Amount of used memory is: "<<endl;
//     system("cat/proc/meminfo|awk '{if(NR==1)a=$2;if(NR==2)b=$2;}END{print a-b}'\n");
//     return 0;
// }

// #include <sys/types.h>
// #include <iostream>
// #include <stdio.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <stdlib.h>
// using namespace std;

// int main(int argc , char * argv[]){
// 		int i;
// 		struct stat s;
// 		if(argc < 2){
// 				cout << "Enter the file name: " << endl;
// 				exit(0);
// 		}
// 		for(int i = 1 ; i<argc ;i++){
// 				cout << "file is: " << argv[i] << endl;
// 				if(stat(argv[i],&s)<0){
// 							cout << "error in obtaining stats" << endl;
// 				}
// 				else{
// 						cout << "owner UID :" << s.st_uid << endl;
// 						cout << "group ID: " << s.st_gid << endl;
// 						cout << "Access permissions : " << s.st_mode << endl;
// 						cout << "Access time: " << s.st_atime << endl;
// 						cout << "File size: " << s.st_size << endl;
// 						// cout << "File size in blocks: " << s.st_blksize << endl;
// 				}
// 		}
// 		return 0;
// }

// #include <iostream>
// #include <stdlib.h>
// #include <fstream>
// using namespace std;
// int main(int argc , char*argv[]){
// 		if(argc!=3) exit(0);
// 		ifstream in;
// 		ofstream out;
// 		in.open(argv[1]);
// 		if(!in) exit(1);
// 		out.open(argv[2]);
// 		if(!out)exit(1);
// 		while(!in.eof()){
// 				char ch = in.get();
// 				if(!in.eof())
// 				out << ch ;
// 		}
// 		in.close();
// 		out.close();
// }

// #include <iostream>
// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// using namespace std;
// int main(int argc,char * argv[]){
//     int i;
//     struct stat s;
//     if(argc<2){
//         cout<<"enter file name: "<<endl;
//         exit(0);
//     }
//     for(int i=1;i<argc;i++){
//         cout<<"file is: "<<argv[i]<<endl;
//         if(stat(argv[i],&s)<0){
//             cout<<"error in obtaining stats"<<endl;
//         }
//         else  
//             cout<<"owner uid"<<s.st_uid<<endl;
//             cout<<"group id"<<s.st_gid<<endl;
//             cout<<"Access permission"<<s.st_mode<<endl;
//             cout<<"access time"<<s.st_atime<<endl;
//             // cout<<"file size in blocks"<<s.st_blksize<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <stdlib.h>
// #include <fstream>
// using namespace std;

// int main(int argc,char * argv[]){
//     if(argc!=3)
//     exit(0);
//     ifstream in;
//     ofstream out;
//     in.open(argv[1]);
//     if(!in)
//     exit(1);
//     out.open(argv[2]);
//     if(!out)
//     exit(1);
//     while(!in.eof()){
//         char ch=in.get();
//         if(!in.eof())
//         out<<ch;
//     }
//     in.close();
//     out.close();
// }

#include <iostream>
using namespace std;
void findWT(int processes[],int n,int bt[],int wt[],int tat[],int at[]){
    wt[0]=0;
    tat[0]=bt[0];
    for(int i=1;i<n;i++){
        int sum=tat[i-1]+at[i-1];
        if(sum-at[i]<=0)
        wt[i]=0;
        else
        wt[i]=sum-at[i];
        tat[i]=wt[i]+bt[i];
    }
}
void sort(int processes[],int n,int bt[],int at[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(at[j]>at[j+1]){
                int temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
            
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
    }
}
// void findTAT(int processes[],int n,int bt[],int wt[],int tat[]){
//     for(int i=0;i<n;i++){
//         tat[i]=bt[i]+wt[i];
//     }
// }
void findAvgTime(int processes[],int n,int bt[],int at[]){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    findWT(processes,n,bt,wt,tat,at);
    // findTAT(processes,n,bt,wt,tat);
    cout<<"Processes  "<<"Burst time  "<<"Arrival time  "<<"Waiting time  "<<"Turn around time  "<<endl;
    for(int i=0;i<n;i++){
        total_wt+=wt[i];
        total_tat+=tat[i];
        cout<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    cout<<"Average wt "<<(float)total_wt/n<<endl;
    cout<<"Average tat "<<(float)total_tat/n<<endl;
}
int main(){
    int n;
    cout<<"Enter number of processes"<<endl;
    cin>>n;
    int processes[n];
    for(int i=0;i<n;i++)
    processes[i]=i+1;
    int bt[n],at[n];
    cout<<"enter burst time for processes: "<<endl;
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }
    cout<<"enter arrival time for processes: "<<endl;
    for(int i=0;i<n;i++){
        cin>>at[i];
    }
    findAvgTime(processes,n,bt,at);
    return 0;
}