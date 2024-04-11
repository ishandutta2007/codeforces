#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(){
  long long n,i;
  vector<long long>v;
  cin>>n;
  for(i=2;i*i<=n;i++){
    for(;n%i==0;n/=i)v.push_back(i);
  }
  if(n>1)v.push_back(i);
  if(v.size()<2)puts("1\n0");
  else if(v.size()==2)puts("2");
  else printf("1\n%lld\n",v[0]*v[1]);

  return 0;
}