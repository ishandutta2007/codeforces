#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool por(pair<int,int> a,pair<int,int> b)
{
     if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main()
{
  int n; cin>>n;
  int * a=new int[n+1];
  for(int i=1;i<=n;i++) cin>>a[i];
  map<int,int> f;
  map<int,int> l;
  for(int i=1;i<=n;i++)
  {
      if(f[a[i]]==0) f[a[i]]=i;
      l[a[i]]=i;
  }
  int mod=998244353;
  long long int ans=1;
  int akt=0;
  for(int i=1;i<=n;i++)
  {
      int t=a[i];
      if(i>1 && akt<i) ans*=2;
      akt=max(akt,l[t]);
     ans%=mod;

  }
  cout<<ans;
    return 0;
}