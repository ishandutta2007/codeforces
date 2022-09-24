#include<cstdio>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int F(char c){
  if(isdigit(c))return c-'0';
  if(isupper(c))return c-'A'+10;
  return 99;
}

int toi(string s,int b){
  int r=0,i;
  for(i=0;i<(int)s.size();i++){
    r=r*b+F(s[i]);
    if(b<=F(s[i]))return 99;
  }
  return r;
}

int main(){
  int n,i,x=1,m;
  string s,t;
  cin>>s;
  for(i=0;;i++){if(s[i]==':')break;}
  t=s.substr(i+1);
  s=s.substr(0,i);

  n=toi(s,66);
  m=toi(t,66);
  if(n<24&&m<60){
    printf("-1");
    x=0;
  }
  if(x){
    for(i=2;i<66;i++){
      n=toi(s,i);
      m=toi(t,i);
      if(n<24&&m<60){
	printf("%s%d",x?"":" ",i);
	x=0;
      }
    }
  }
  if(x){
    printf("%d",0);
  }
  puts("");
  return 0;
}