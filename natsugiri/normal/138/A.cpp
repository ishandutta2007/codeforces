#include<string>
#include<iostream>

using namespace std;

string vowels="aoeui",r[]={"aabb","abab","abba"};

string cut(string s,int k){
  int n=s.size(),i;

  for(;n--;){
    for(i=0;i<5;i++){
      if(s[n]==vowels[i])k--;
      if(k==0)break;
    }
    if(k==0)break;
  }
  if(n<0){
    return "";
  }
  return s.substr(n);
}
  
int main(){
  int n,k,i,j;
  string s[4];
  bool b[3]={0};
  cin>>n>>k;
  for(i=0;i<n;i++){
    for(j=0;j<4;j++){
      cin>>s[j];
      s[j]=cut(s[j],k);
      if(s[j]==""){
	goto EXIT;
      }
    }
    if(s[0]!=s[1] || s[2]!=s[3])b[0]=1;
    if(s[0]!=s[2] || s[1]!=s[3])b[1]=1;
    if(s[0]!=s[3] || s[1]!=s[2])b[2]=1;
  }

  if(!b[0] && !b[1]){
    cout<<"aaaa"<<endl;
    return 0;
  }
  for(i=0;i<3;i++){
    if(b[i]==0){
      cout<<r[i]<<endl;
      return 0;
    }
  }
  EXIT:;
  cout<<"NO"<<endl;
  return 0;
}