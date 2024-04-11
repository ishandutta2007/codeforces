#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
  int n,i;
  string s,t;
  cin>>s>>t;
  for(i=0;i<s.size();i++){
    s[i]=tolower(s[i]);
    t[i]=tolower(t[i]);
  }
  if(s==t)n=0;
  if(s<t)n=-1;
  if(s>t)n=1;
  cout<<n<<endl;


  return 0;
}