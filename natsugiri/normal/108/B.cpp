#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,i,t,j;
  vector<int>v;
  bool f;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>t;
    v.push_back(t);
  }
  sort(v.begin(),v.end());
  f=true;
  //if(v[0]==1)f=false;
  for(i=0;i<n-1;i++){
    if(v[i+1]==v[i])continue;
    if(v[i+1]<v[i]*2)f=false;
  }
  cout<<(f?"NO":"YES")<<endl;
  return 0;
}