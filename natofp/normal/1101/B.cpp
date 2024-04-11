#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s; cin>>s;
  int n=s.length();
  int x,y;
  int i;
  for(i=0;i<n;i++)
  {
      if(s[i]=='[') break;
  }
  for(i;i<n;i++)
  {
      if(s[i]==':') break;
  }
  x=i;
  for(i=n-1;i>=0;i--)
  {
      if(s[i]==']') break;
  }
  for(i;i>=0;i--)
  {
      if(s[i]==':') break;
  }
  y=i;
  if(x>=y) {cout<<-1; return 0;}
  int ile=0;
  for(int i=x+1;i<y;i++)
  {
      if(s[i]=='|') ile++;
  }
  cout<<ile+4;
    return 0;
}