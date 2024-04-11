#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

  
int main(){
  int n,i,j;
  string str,ans;
  cin>>str;
  if(str[0]>'7')str="0"+str;
  n=str.size();
  if(n&1){
    for(i=0;i<(n+1)/2;i++)cout<<4;
    for(i=0;i<(n+1)/2;i++)cout<<7;
    cout<<endl;
    return 0;
  }
  
  n/=2;
  ans="";
  
  for(i=0;i<n;i++){
    ans="7"+ans+"4";
  }
  if(ans<str){
    for(i=0;i<=n;i++)cout<<4;
    for(i=0;i<=n;i++)cout<<7;
    cout<<endl;
    return 0;
  }
  
  if(str[0]>'7'){
    //n/2;
    n++;
    for(i=0;i<n;i++)cout<<4;
    for(i=0;i<n;i++)cout<<7;
    cout<<endl;
    return 0;
  }
  
  //n/=2;
  ans="";
  for(i=0;i<n;i++){
    ans="4"+ans+"7";
  }
  
  for(;ans<str;){
    n=0;
    for(i=ans.size()-1;ans[i]=='4';i--);
    ans[i]='4';
    for(j=i-1;ans[j]=='7';j--);
    ans[j]='7';
    sort(ans.begin()+j+1,ans.end());
  }

  cout<<ans<<endl;

  return 0;
}