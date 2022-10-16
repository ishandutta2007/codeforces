#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,k; cin>>n>>k;
  int * a=new int[n];
  for(int i=0;i<n;i++) cin>>a[i];
  vector<int> s[5555];
  for(int i=0;i<n;i++)
  {
      int t=a[i];
      s[t].push_back(i);
  }
  int akt=1;
  vector<int> ans(n,-1);
  for(int i=0;i<5111;i++)
  {
      for(int j=0;j<s[i].size();j++)
      {
          ans[s[i][j]]=akt%k;
          akt++;
      }
  }
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          if(i!=j && a[i]==a[j] && ans[i]==ans[j]) {cout<<"NO"; return 0;}
      }
  }
  cout<<"YES"<<endl;
  for(int i=0;i<n;i++) cout<<ans[i]+1<<" ";
    return 0;
}