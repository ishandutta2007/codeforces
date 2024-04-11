#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  cin>>s;
  int i,j;
  for(i=0;s[i]!='.';i++);
  
  if(s[i-1]=='9')cout<<"GOTO Vasilisa.";
  else{
    if(s[i+1]>'4')s[i-1]++;
    for(j=0;j<i;j++)cout<<s[j];
  }
  cout<<endl;
  return 0;
}