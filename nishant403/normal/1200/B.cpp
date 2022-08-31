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

void solve()
{
  int n,m,k;
  cin >> n >> m >> k;
    
  int h[n];
    
  f(i,n) cin >> h[i];
    
  int ans = 0;  
  int id = 0;  
    
  while(id < n - 1)
  {
    int reqheight = h[id+1] - k;
    
    reqheight = max(reqheight,(int)0);  
      
    int blocks = h[id] - reqheight;
     
    if(blocks >= 0)  m+=blocks;  
    else if(m < (-blocks)) { cout << "NO\n"; return; }
    else { m+=blocks; } 
      
    id++;  
  }  
    
    cout << "YES\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}