#include<cstdio>
#include<string>
#include<bitset>
#include<iostream>
using namespace std;

int main(){
  int n,z,o,q,i,d[4]={0};
  string str;
  cin>>str;
  n=str.size();
  z=o=q=0;
  for(i=0;i<n;i++){
    if(str[i]=='0')z++;
    if(str[i]=='1')o++;
    if(str[i]=='?')q++;
  }
  if(z+q>o)d[0]=1;
  if(z+1<o+q)d[3]=1;
  int p=n/2;
  int t=p-z;
  if(t<0 || q<t);//
  else{
    if(str[n-1]=='1')d[1]=1;
    if(str[n-1]=='0')d[2]=1;
    if(str[n-1]=='?'){
      if(t==q)d[2]=1;
      else if(t==0)d[1]=1;
      else d[1]=d[2]=1;
    }
  }
  for(i=0;i<4;i++){
    if(d[i]){
      cout<<bitset<2>(i)<<endl;
    }
  }
  
  return 0;
}