#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
  double nu,de;
  int n,m,h,i,j,t,sum,d;
  vector<int>s;
  cin>>n>>m>>h;
  sum=0;
  d=0;
  for(i=0;i<m;i++){
    cin>>t;
    s.push_back(t);
    if(i!=h-1)d+=t;
    sum+=t;
  }
  
  if(sum<n){
    cout<<-1<<endl;
    return 0;
  }
  if(n-1>d){
    cout<<1<<endl;
    return 0;
  }
  nu=1;
  de=1;
  for(i=1;i<n;i++){
    nu*=(d-i+1);
    nu/=i;
    de*=sum-i;
    de/=i;
  }
  printf("%.9f\n",1.0-nu/de);
  return 0;
}