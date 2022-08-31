#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pb push_back

void solve()
{
    int u,v;
    cin >> u >> v;
    
    vector<int> pos1,pos2;
    
    f(i,30) if((u >> i) & 1) pos1.pb(i);
    f(i,30) if((v >> i) & 1) pos2.pb(i);
        
    reverse(pos1.begin(),pos1.end());
    reverse(pos2.begin(),pos2.end());
    
    while(!pos2.empty())
    {
        if(u > v || pos1.empty() || pos1.back() > pos2.back())
        {
            cout << "NO\n";
            return;
        }
        
        pos1.pop_back();
        pos2.pop_back();
    }
    
    cout <<"YES\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}