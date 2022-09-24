#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main(){
  int n,i;
  string s,v="aoyeui";
  cin>>s;
  for(n=0;n<s.size();n++){
    for(i=0;i<6;i++){
      if(tolower(s[n])==v[i])break;
    }
    if(i==6)cout<<'.'<<(char)tolower(s[n]);
  }
  cout<<endl;
  return 0;
}