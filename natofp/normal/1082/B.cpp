#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n; cin>>n;
  string s; cin>>s;
  vector<int> ile;
  int akt=1;
  for(int i=1;i<s.length();i++)
  {
      if(s[i-1]==s[i]) akt++;
      else
      {
          ile.push_back(akt);
          akt=1;
      }
  }
  ile.push_back(akt);
  int t=0;
  int ans=0;
  if(s[0]=='G') t=1;
  int ilejedynek=(ile.size()+t)/2;
  for(int i=1;i<ile.size();i++)
  {
      if(i%2==t%2)
      {
          if(i==ile.size()-1) continue;
          if(ile[i]==1)
          {
              ans=max(ans,ile[i-1]+ile[i+1]+1);
          }
      }
  }
  if(ilejedynek==1)
  {
      if(t==1) cout<<ile[0];
      else cout<<ile[1];
      return 0;
  }
  if(ilejedynek==2)
  {
      if(t==1)
      {
          if(ile[1]==1) cout<<ile[0]+ile[2];
          else cout<<max(ile[0],ile[2])+1;
          return 0;
      }
      else
      {
          if(ile[2]==1) cout<<ile[1]+ile[3];
          else cout<<max(ile[1],ile[3])+1;
          return 0;
      }
  }
if(ilejedynek==0) {cout<<0; return 0;}
  int ans2=0;
  for(int i=0;i<ile.size();i++)
  {
      if(t%2!=i%2) ans2=max(ans2,ile[i]);
  }
  cout<<max(ans,ans2+1)<<endl;
    return 0;
}