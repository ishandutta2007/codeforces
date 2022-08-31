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

const int MOD = 998244353;

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
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve()
{
    int n;
    cin >> n;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    int empty = 0;
    f(i,n) empty += (a[i] == -1);
    
    int res = 0;
    
    //inversions of only fixed cells
    FenwickTree go(n+2);
    
    int c1 = 0;
    
    f(i,n) 
    {
        if(a[i] == -1) continue;
        c1 += go.sum(a[i]+1,n);
        c1 %= MOD;
        go.add(a[i],1);
    }
    
    res += c1;
    
    //inversions of only non-fixed cells
    int c2 = (empty*(empty - 1))%MOD;
    c2 = (c2*mod_pow(4,MOD-2))%MOD;
    res += c2;
    
    //inversion where first cell is fixed, second cell is non-fixed
    vector<int> ed;
    
    for(int i=1;i<=n;i++)
        if(go.sum(i,i) == 0) ed.pb(i);
    
    int c3 = 0;
    int temp = 0;
    
    f(i,n)
    {
        if(a[i] != -1) 
        {
            temp += (lower_bound(all(ed),a[i]) - ed.begin());
        }
        else c3 += temp;
    }
    
    c3 %= MOD;
    c3 = (c3*mod_pow(empty,MOD-2))%MOD;
    res += c3;
    
    //inversion where first cell is non-fixed, second cell is fixed
    int c4 = 0;
    temp = 0;
    
    for(int i=n-1;i>=0;i--)
    {
        if(a[i] != -1) 
        {
            temp += (int)ed.size();
            temp -= (lower_bound(all(ed),a[i]) - ed.begin());
        }
        else c4 += temp;
    }
    
    c4 %= MOD;
    c4 = (c4*mod_pow(empty,MOD-2))%MOD;
    res += c4;
    res %= MOD;
    
//    cout << c1 << ' ' << c2 << ' ' << c3 << ' '<< c4 << '\n';
    
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