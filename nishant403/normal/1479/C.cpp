#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

signed main()
{
  fast;
  
  vector<pair<int,pii> > ed; 
    
  int l,r;
  cin >> l >> r;
   
  for(int i=31;i>=12;i--)
  {
      ed.push_back({1,{i,32}});
      
      for(int j=i+1;j<=31;j++)
      {
          ed.push_back({1LL<<(31-j),{i,j}});
      }
  }
    
  int st = 1;
    
  if(l > 1)
  {
      ed.push_back({l-1,{1,2}});
      st = 2;
  }
    
  int dis = r - l + 1;  
  ed.push_back({1,{st,32}});  
 
  dis--;
    
  int wt = 1; 
    
  for(int i=19;i>=0;i--)
  {
      if(dis & (1LL<<i))
      {
          ed.push_back({wt,{st,31-i}});
          wt += (1LL<<i);
      }
  }
    
  cout << "YES\n";
  cout << 32 <<' ' << ed.size() << '\n';
  for(auto x : ed) cout << x.S.F << ' ' << x.S.S << ' ' << x.F << '\n'; 
}