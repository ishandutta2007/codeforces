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

void solve()
{
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin >> a[i];
   
   sort(a,a+n);
    
   vi vis(n,0);
    vis[n-1] = 1;
    
   vi res;
    res.pb(a[n-1]);
    
    int gc = a[n-1];
    
   for(int i=1;i<n;i++)
   {
       //find elm that gives maximum gcd
       int val = -1;
       int id = -1;
       
       f(j,n) if(vis[j] == 0 && __gcd(gc,a[j]) > val)
       {
           val = __gcd(gc,a[j]);
           id = j;
       }
       
       vis[id] = 1;
       res.pb(a[id]);
       gc = __gcd(gc,res.back());
   }
    
   for(auto x : res) cout << x << ' ';
    cout << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}