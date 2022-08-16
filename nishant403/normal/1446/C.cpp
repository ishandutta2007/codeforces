#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

int go(vector<int> & v,int bt = 30)
{
    if(bt < 0) return 0;
    
    vector<int> arr[2];
    
    for(auto x : v)
        arr[(x>>bt) & 1].pb(x);
        
    int s1 = arr[0].size();
    int s2 = arr[1].size();
    
    if(s1 == 0) return go(arr[1],bt-1);
    else if(s2 == 0) return go(arr[0],bt-1);
        
    return min(go(arr[0],bt-1) + s2 - 1, go(arr[1],bt-1) + s1 - 1);
}

void solve()
{
    int n;
    cin >> n;
    
    vi a(n);
    f(i,n) cin >> a[i];
    cout << go(a);
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}