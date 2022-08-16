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

const int N  = 1e5+10;

vi g[N];

void solve()
{
  int n,a,b;
    cin >> n;
    
  f(i,n-1)
  {
   cin >> a >> b;
      
   g[a].pb(b);
    g[b].pb(a);
  }
  
    f(i,n+1) if(g[i].size()==2) { cout << "NO"; return; }  
    
  cout << "YES";  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}