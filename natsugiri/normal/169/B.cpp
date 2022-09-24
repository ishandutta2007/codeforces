#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n,m;
string a,s;

int main(){
  cin>>a>>s;
  sort(s.begin(),s.end());
  reverse(s.begin(),s.end());
  int p,q;
  p=q=0;

  for(;a[p]!=0 && s[q]!=0;p++)
    if(a[p]<s[q])a[p]=s[q++];

  cout<<a<<endl;
  return 0;
}