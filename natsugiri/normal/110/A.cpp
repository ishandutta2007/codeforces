#include<iostream>
#include<string>
using namespace std;
int main(){
  int i,n;
  string str;
  cin>>str;
  n=0;
  for(i=0;i<str.size();i++){
    if(str[i]=='7'||str[i]=='4')n++;
  }
  if(n==7||n==4)cout<<"YES";
  else cout<<"NO";
  cout<<endl;
  return 0;
}