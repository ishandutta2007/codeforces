#include<string>
#include<iostream>
using namespace std;
int main(){
  int i,m,k;
  string s;
  cin>>s;
  m=0;
  k=1;
  for(i=1;i<s.size();i++){
    if(k==5 || s[i]!=s[i-1]){
      m++;
      k=1;
    }else{
      k++;
    }
  }
  m++;
  cout<<m<<endl;
}