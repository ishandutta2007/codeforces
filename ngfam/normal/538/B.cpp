#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("TEST.INP");
ofstream fo("TEST.OUT");
const int maxN=1e6+6;
int F[maxN],n,s,A[101],np[60];
void next(int tt){
    int i=7;
    for(;i>0 && np[i]==1;i--);
    if(!i)return;
    np[i]=1;
    for(int j=i+1;j<=7;j++)
        np[j]=0;
    for(int j=1;j<=7;j++)
        A[tt]=A[tt]*10+np[j];
  //  for(int i=1;i<=7;i++)
  //      fo<<A[tt];
    if(A[tt]>s)return;
  //  fo<<endl;
    next(tt+1);
}
void solve(){
    for(int i=1;i<=s;i++){
        F[i]=i+1;
        for(int j=1;j<=64 && A[j]<=i && A[j]!=0;j++)
            F[i]=min(F[i-A[j]]+1,F[i]);
    }
    cout<<F[s]<<endl;
}
void tv(int s,int sl){
    for(int j=1;j<=65 && A[j]<=s && A[j]!=0;j++)
         if(F[s-A[j]]==F[s]-1){
               cout<<A[j]<<" ";
               tv(s-A[j],sl-1);
               return;
         }
}
void enter(){
    cin>>s;
  //  fo<<A[2];
}
int main(){
    //next(1);
    enter();
    next(1);
    solve();
    tv(s,F[s]);
  //  fo<<F[8];
}