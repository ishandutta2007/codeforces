#include<iostream>
using namespace std;
int main(){
  int n,i,m,t,ma;
  m=0;
  ma=0;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>t;
    m-=t;
    cin>>t;
    m+=t;
    if(ma<m)ma=m;
  }
  cout<<ma<<endl;
  return 0;
}