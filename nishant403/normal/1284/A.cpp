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
   
  string a[n],b[m];
    f(i,n) cin >> a[i];
    f(i,m) cin >> b[i];
    
    int q;
    cin >> q;
    
    map<int,pii> mp;
    
    int a1 =0,b1 = 0;
    
    for(int i=1;i<=m*n;i++)
    {
        mp[i] = {a1,b1};
        a1++;
        b1++;
        a1%=n;
        b1%=m;
    }
    
    while(q--)
    {
        int y;
        cin >> y;
        
        y--;
        y%=(m*n);
        y++;
        
        cout << a[mp[y].F] + b[mp[y].S] << "\n";
        
    }
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}