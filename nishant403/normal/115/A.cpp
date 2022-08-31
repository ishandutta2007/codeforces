#include <bits/stdc++.h>
using namespace std;

#define int long long 
vector<int> graph[2001];

int  geth(int n)
{
 int h = 0;   
    
  for(auto x : graph[n])
  {
   h = max(h,geth(x) );   
  }
    
  return h+1;  
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    int n,i,j;
    cin >> n;
    
    vector<bool> isroot(n+1,1);
    
    for(i=0;i<n;i++) 
    {
     cin >> j;
      if(j==-1) continue;
      graph[j].push_back(i+1);  
      isroot[i+1]=0;
    }
    
    int h = 0;
    
    for(i=1;i<=n;i++)
    {
     if(isroot[i]) h=max(h,geth(i) );    
    }
    
    cout << h;
}