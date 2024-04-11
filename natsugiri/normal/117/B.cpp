#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
int a,b,mod;
int main(){
  cin>>a>>b>>mod;
  LL t;
  int i;
  if(mod<b+2){
    cout<<2<<endl;
    return 0;
  }
  t=(int)(1e9)%mod;
  for(i=1;i<=a&&i<mod;i++){
    int x=(t*i)%mod;
    if(0<x&&x+b<mod){
      printf("1 %09d\n",i);
      return 0;
    }
  }
  cout<<2<<endl;
  return 0;
}