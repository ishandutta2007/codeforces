#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;

LL step(LL n,LL x,LL d){
  if(d>0)return (n-x)/d;
  if(d<0)return (1-x)/d;
  return 1LL<<62;
}

int main(){
  LL n,m,x,y,dx,dy;
  LL t,k,a=0;
  cin>>n>>m>>x>>y>>k;
  for(;k--;){
    cin>>dx>>dy;
    t=min(step(n,x,dx),step(m,y,dy));
    x+=t*dx;
    y+=t*dy;
    a+=t;
  }
  cout<<a<<endl;
  return 0;
}