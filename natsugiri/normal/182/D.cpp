#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int gcd(int a, int b){return b?gcd(b, a%b):a;}

bool check(string s, int p){
  for(int i=0; i<(int)s.size(); i+=p)
    for(int k=0; k<p; k++)
      if(s[k]!=s[i+k])
	return 0;

  return 1;
}
  
string s, t;

int main(){
  cin>>s>>t;

  int g=gcd(s.size(), t.size());
  int m=g;
  int ans=0;

  for(int i=1; i<=g; i++){
    if(g%i==0){
      bool f=1;
      for(int j=0; f && j<i; j++)if(s[j]!=t[j])f=0;
      
      if(f)f=check(s, i);
      if(f)f=check(t, i);
      ans+=f;
    }
  }
	
  
  printf("%d\n",ans);
  return 0;
}