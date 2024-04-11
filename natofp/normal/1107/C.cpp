#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool por(int a,int b)
{
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  int n,k; cin>>n>>k;
  int * a=new int[n];
  for(int i=0;i<n;i++) cin>>a[i];
  long long ans=0;
  string s; cin>>s;
  int akt=1;
  for(int i=1;i<n;i++)
  {
      if(s[i]==s[i-1]) akt++;
      else
      {
            vector<int> res;
            for(int j=i-akt;j<i;j++)
            {
                res.push_back(a[j]);
            }
            sort(res.begin(),res.end());
            for(int t=0;t<min((int)res.size(),k);t++)
            {
                ans+=res[res.size()-1-t];
            }
            akt=1;
      }
  }
  vector<int> res;
  for(int i=n-akt;i<n;i++) res.push_back(a[i]);
  sort(res.begin(),res.end(),por);
  for(int i=0;i<min((int)res.size(),k);i++) ans+=res[i];
  cout<<ans;

    return 0;
}