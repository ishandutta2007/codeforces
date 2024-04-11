#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
  int i,s,f;
  string a,b;
  cin>>a>>b;
  s=f=0;
  for(i=0;i<(int)a.size();i++){
    if(a[i]!=b[i]){
      if(a[i]=='7')s++;
      else f++;
    }
  }
  
  printf("%d\n",s<f?f:s);
  return 0;
}