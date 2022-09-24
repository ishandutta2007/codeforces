#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int S(string s,string t){
  int a=0;
  if(s[1]==t[0])a=100;
  if(isdigit(s[0]))a+=s[0]-'0';
  else{
    if(s[0]=='T')a+=10;
    if(s[0]=='J')a+=11;
    if(s[0]=='Q')a+=12;
    if(s[0]=='K')a+=13;
    if(s[0]=='A')a+=14;
  }
  return a;
}
 
int main(){
  int n,m;
  string a,b,t;
  bool f;
  cin>>t>>a>>b;
  n=S(a,t);
  m=S(b,t);
  f=false;
  if(n>99)f=true;
  if(a[1]==b[1])f=n>m;
  cout<<(f?"YES":"NO")<<endl;
  return 0;
}