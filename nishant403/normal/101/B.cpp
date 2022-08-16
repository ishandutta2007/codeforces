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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        ret %= MOD;
        return ret;
    }

    int sum(int l, int r) {
        return (sum(r) - sum(l - 1) + MOD)%MOD;
    }

    void add(int idx, int delta) {
        
        delta %= MOD;
        
        for (; idx < n; idx = idx | (idx + 1))
        {
            bit[idx] += delta;
            if(bit[idx] >= MOD) bit[idx] -= MOD;
        }
    }
};


void solve()
{
   int m,n;
   cin >> m >> n;
    
   pii a[n];
    f(i,n) cin >> a[i].F >> a[i].S;
    
   vector<int> go;
    f(i,n) go.pb(a[i].F), go.pb(a[i].S);
    go.pb(0);
    go.pb(m);
    
    sort(all(go));
    
    f(i,n) a[i].F = lower_bound(all(go),a[i].F) - go.begin();
    f(i,n) a[i].S = lower_bound(all(go),a[i].S) - go.begin();
    
   FenwickTree ft(n+n+10);
   ft.add(0,1);
    
   f(i,n) swap(a[i].F,a[i].S);
   sort(a,a+n);
   f(i,n) swap(a[i].F,a[i].S); 
    
   f(i,n)
   {
       ft.add(a[i].S , ft.sum(a[i].F,a[i].S - 1));
   }
    
   int idd = lower_bound(all(go),m) - go.begin();
    
   cout << ft.sum(idd,idd);
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}