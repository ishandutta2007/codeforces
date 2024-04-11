#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
  int n,k; cin>>n>>k;
  vector<int> ans(k,1);
  int sum=k;
  int akt=0;

  while(sum<n)
  {
      while(akt<k && ans[akt]+sum>n) akt++;
      if(akt==k) {cout<<"NO"; return 0;}
      ans[akt]*=2; sum+=ans[akt]/2;
  }
  if(sum!=n) {cout<<"NO"; return 0;}
  cout<<"YES"<<endl;
  for(int i=0;i<k;i++) cout<<ans[i]<<" ";
    return 0;
}