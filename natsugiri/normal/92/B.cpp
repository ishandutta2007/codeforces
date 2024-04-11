#include<iostream>
#include<string>
using namespace std;
int main(){
  int m,i,t;
  string str;
  cin>>str;
  m=str.size()-1;
  t=0;
  for(i=1;i<str.size();i++){
    if(str[i]=='1'){
      m++;
      break;
    }
  }
  for(i=str.size()-1;i>0;i--){
    if(t==0&&str[i]=='1')t=1,m++;
    if(t==1&&str[i]=='0')m++;
  }
  cout<<m<<endl;
  return 0;
}