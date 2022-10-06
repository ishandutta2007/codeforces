#include<cstdio>
#include<iostream>

using namespace std;

int main(){
  int i,j,k,n,t;
  cin>>n>>t;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      cout<<(i==j)*t<<" ";
    cout<<endl;
  }
  return 0;
}