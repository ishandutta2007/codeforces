#include<iostream>
#include<string>
using namespace std;
int main(){
  string str,s[10];
  int i,j;
  cin>>str;
  for(i=0;i<10;i++)cin>>s[i];
  for(j=0;j<8;j++){
    for(i=0;i<10;i++){
      if(str.find(s[i])==0){
    cout<<i;
    str=str.substr(10);
    break;
      }
    }
  }
  return 0;
}