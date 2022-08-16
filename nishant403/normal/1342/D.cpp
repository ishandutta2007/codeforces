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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 2e5 + 10;
int fre[N];
vector<int> res[N];

void solve()
{
   int n,m;
    cin >> n >> m;
    
   int a[n];
    f(i,n) cin >> a[i];
    f(i,n) fre[a[i]]++;
    
   int b[m+1];
    f(i,m) cin >> b[i+1];
    
   int req = 0;
   for(int i=m-1;i>=1;i--) fre[i] += fre[i + 1]; 
   f(i,m) req = max(req ,(fre[i + 1] + b[i + 1] - 1)/b[i + 1]);
    
   cout << req << '\n';
   
   sort(a,a+n);
   reverse(a,a+n);
    
   f(i,n) res[i % req].pb(a[i]);
    
   f(i,req)
   {
       cout << res[i].size() << ' ';
       for(auto x :  res[i]) cout << x << ' ';
       cout << '\n';
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