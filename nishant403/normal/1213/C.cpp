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
 int n,m;
    cin >> n >> m;
    
 int sum = 0;
    
    if(m%10==0) { cout << 0 <<"\n"; return;}
    
    vi s;
    
    s.pb(0);
    
    int t=m;
    
    while((t%10) != s.front())
    {
      s.pb(t%10); t=t+m;   
    }
    
    n=(n/m)*m;
    
    int add = (int)(s.size());
    add*=m;
    
    int ans =0;
    
    for(int i=0;i<(int)s.size();i++)
    {
      int tt = (i*m)%10;   
      int num = (n-(i*m)+add)/(add);   
      ans+=(tt*num);
    }
    
    cout << ans  << "\n";
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}