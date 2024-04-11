#include<iostream>
#include<cstdio>
using namespace std;
bool check(int a,int b){
  int t;
  t=b%10;
  b/=10;
  b+=t*10;
  return (a==b);
}

int main(){
  int a,b,i;
  char c;
  bool f;
  cin>>a>>c>>b;
  f=true;
  b++;
  for(;f;a++){
    if(a>23)a=0;
    for(;b<59;b++){
      f=!check(a,b);
      if(!f)break;
    }
    if(!f)break;
    b=0;
  }
  printf("%02d:%02d\n",a,b);
  return 0;
}