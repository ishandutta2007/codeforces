#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 2e5+10;
int a[N];
int b[N];
int n,k;

//no of values less than x
int cnt(int x)
{
   return lower_bound(a,a+n,x)-a;
}

void solve()
{
    cin >> n >> k;
    
    f(i,n) cin >> a[i];
    
    sort(a,a+n);
    
    f(i,n) b[i] = a[i];
    f(i,n-1) b[i+1]+=b[i];
    
    map<int,int> mp;
    f(i,n) mp[a[i]]++;
    
    for(auto x : mp)
        if(x.S >= k)
    {
        cout<< 0;
        return;
    }
    
    vector<int> vs;
    
    for(auto x : mp)
    {
        vs.pb(x.F);
    }
    
    int res = 1e16;
    
    //case 1 : occur at boundaries
    for(auto x : vs)
    {
        int need = k - mp[x];
       
        //if only left are needed
        int tot = cnt(x);
        
        int psum = 0;
        if(tot>0) psum = b[tot-1];
        
        if(tot >= need)
        {
        res = min(res,(tot*(x-1))-psum+need);
        }
        //if only right are needed

        int rtot = n - tot - mp[x];
        int ssum = b[n-1] - psum - (mp[x]*x);
        
        if(rtot >= need)
        {
        res = min(res,(ssum)-(rtot*(x+1))+need);
        }

        //both are needed
        res = min(res,(ssum)-(rtot*(x+1)) + (tot*(x-1)) - psum + need);
 
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