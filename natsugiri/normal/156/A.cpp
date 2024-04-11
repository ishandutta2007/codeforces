#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string s,u;

int main(){
  int n,ans,i,j;

  cin>>s>>u;
  ans=n=u.size();
  s=string(n,'_')+s+string(n,'_');
  for(i=0;i<(int)s.size();i++){
    n=0;
    for(j=0;j<(int)u.size();j++){
      if(s[i+j]==u[j])n++;
    }
    if(ans>(int)u.size()-n)ans=(int)u.size()-n;
  }
  printf("%d\n",ans);
  return 0;
}