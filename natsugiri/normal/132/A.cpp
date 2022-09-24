#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int rev(int n){
  int r=0,i;
  for(i=0;i<8;i++){
    r=r*2+n%2;
    n/=2;
  }
  return r;
}

int main(){
  int n=0,i,t,m=0;
  string s;
  getline(cin,s);
  for(i=0;i<s.size();i++){
    t=rev(s[i]);
    n=-t+m;
    for(;n<0;)n+=256;
    printf("%d\n",n);
    m=t;
  }
  return 0;
}