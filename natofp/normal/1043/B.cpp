#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> a(1001,0);

bool zrob(int k,int n)
{
    for(int i=0;i<k;i++)
    {
        for(int j=i;j<n-k;j+=k) if(a[j]!=a[j+k]) return false;
    }
    return true;
}

int main()
{
  int n; cin>>n;
  vector<int> b(1001,0);
  for(int i=0;i<n;i++) cin>>b[i];
  for(int i=1;i<n;i++) a[i]=b[i]-b[i-1];
  a[0]=b[0];
  int ans=0;
  vector<int> res;
  for(int i=1;i<=n;i++)
  {
      if(zrob(i,n)) {ans++; res.push_back(i);}
  }
  cout<<ans<<endl;
  for(int i=0;i<ans;i++) cout<<res[i]<<" ";
    return 0;
}