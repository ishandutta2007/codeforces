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
int a[N],b[N];
int n,k;

int charge[N];
vector<int> pq[N];

int check(int x)
{
    f(i,n) charge[i] = a[i];
    
    f(i,k) pq[i].clear();
    
    f(i,n) 
    {
        if(charge[i]/b[i] < k) pq[charge[i]/b[i]].pb(i);
    }
    
    int ptr = 0;
    
    f(i,k)
    {
        while(ptr < k && pq[ptr].empty()) ptr++;
        
        if(ptr == k) return 1;
        
        auto z = pq[ptr].back(); pq[ptr].pop_back();
        
        int cur_charge = charge[z] - (i*b[z]);
        
        if(cur_charge < 0) return 0;
        
        charge[z] += x;
        
        if(charge[z]/b[z] < k) pq[charge[z]/b[z]].pb(z);
    }
    
    f(i,n) assert(charge[i] >= (k-1)*b[i]);
    
    return 1;
}

void solve()
{
   cin >> n >> k;
    
   f(i,n) cin >> a[i];
   f(i,n) cin >> b[i];
    
   int l = 0;
   int r = 1e13;
   int res = -1;
    
   while(l <= r)
   {
       int mid = (l + r)/2;
       
       if(check(mid))
       {
           res = mid;
           r = mid - 1;
       }
       else 
       {
           l = mid + 1;
       }
   }
    
   cout << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}