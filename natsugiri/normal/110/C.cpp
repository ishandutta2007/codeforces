#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
  int i,n,t;
  cin>>n;
  for(t=0;t*4<n;t++){
    if((n-t*4)%7==0)break;
  }
  if((n-t*4)%7==0){
    for(i=0;i<t;i++)printf("4");
    for(i=0;i<(n-t*4)/7;i++)printf("7");
  }else{
    cout<<-1;
  }
  cout<<endl;   
  return 0;
}