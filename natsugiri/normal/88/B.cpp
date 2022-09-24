#include<iostream>
#include<cctype>
#include<string>
#include<cstdio>
using namespace std;
bool b[30][30];
char s[30][31];
int main(){
  int n,m,x,i,j,k,l,ans,S;
  char c;
  bool f;
  cin>>n>>m>>x;
  S=0;
  for(i=0;i<n;i++)scanf("%s",s[i]);
  for(j=0;j<n;j++){
    for(i=0;i<m;i++){
      if(s[j][i]=='S'){
    S=2;
    for(l=0;l<n;l++){
      for(k=0;k<m;k++){
        if(x*x>=(i-k)*(i-k)+(j-l)*(j-l))b[l][k]=1;
      }
    }
      }
    }
  }
  cin>>x;
  ans=0;
  for(k=0;k<x;k++){
    cin>>c;
    l=0;
    if(islower(c)){
      f=0;
    }else{
      c=tolower(c);
      f=1;
    }
    for(j=0;j<n;j++){
      for(i=0;i<m;i++){
    if(s[j][i]==c){
      if(f){
        if(b[j][i]==1)l=1;
        else l=l==0?S:l;
      }
      else l=1;
    }
    if(l==1)break;
      }
      if(l==1)break;
    }
    if(l==2)ans++;
    if(l==0){
      ans=-1;
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}