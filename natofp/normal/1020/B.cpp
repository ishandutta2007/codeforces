#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n; cin>>n;
  int * a=new int[n+1];
  for(int i=1;i<=n;i++) cin>>a[i];
  vector<bool> czy(n+1,false);
  for(int i=1;i<=n;i++)
  {
      czy[i]=true;
      int k=a[i];
      while(czy[k]==false)
      {
          czy[k]=true;
          k=a[k];
      }
      cout<<k<<" ";
      for(int j=1;j<=n;j++) czy[j]=false;
  }
    return 0;
}