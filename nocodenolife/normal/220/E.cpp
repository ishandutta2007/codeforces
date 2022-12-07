#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define F first
#define S second 
#define pb push_back
#define endl "\n"

#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }

#ifdef DEBUG
    #define dbg(s) {s;}
#endif

#ifndef DEBUG
    #define dbg(s)
#endif

using namespace std;

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int getInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;

vector<ll> seg[maxn];
ll arr[maxn];

void build(int idx, int l, int r)
{
    //cout<<idx<<" "<<l<< " -> "<<r<<endl;
    if(l==r)
    {
        seg[idx].pb(arr[l]);
        return;
    }
    int m  = l+r;
    m/=2;
    
    build(idx+idx,l,m);
    build(idx+idx+1,m+1,r);

    merge(seg[idx+idx].begin(), seg[idx+idx].end(), seg[idx+idx+1].begin(), seg[idx+idx+1].end(), back_inserter(seg[idx]));
    return;
}

int findSmaller(int idx, int l, int r, int ql, int qr, int val)
{
    if(l>qr || r<ql)
        return 0;
    if(l>=ql && r<=qr)
    {
        return lower_bound(all(seg[idx]),val) - seg[idx].begin();
    }
    
    int m = l+r;
    m/=2;

    return findSmaller(idx+idx,l,m,ql,qr,val) + findSmaller(idx+idx+1,m+1,r,ql,qr,val);
}

int findLarger(int idx, int l, int r, int ql, int qr, int val)
{
    if(l>qr || r<ql)
        return 0;
    if(l>=ql && r<=qr)
    {
        return seg[idx].end() - upper_bound(all(seg[idx]),val);
    }
    
    int m = l+r;
    m/=2;

    return findLarger(idx+idx,l,m,ql,qr,val) + findLarger(idx+idx+1,m+1,r,ql,qr,val);
}

int n,k;

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>arr[i];

    build(1,1,n);
    
    int l = 1;
    int r = 2;
    int curk = 0;
    
    for(int i=1;i<n;i++)
    {
        curk+= findSmaller(1,1,n,i+1,n,arr[i]);
    }

    int ans = 0;

    while(r<=n)
    {
        if(curk>k || r==l)
        {
            curk -= findSmaller(1,1,n,r+1,n,arr[r]);
            curk -= findLarger(1,1,n,1,l,arr[r]);
            r++;
            continue;
        }

        ans+= n-r+1;
        curk += findLarger(1,1,n,1,l,arr[l+1]);
        curk += findSmaller(1,1,n,r,n,arr[l+1]);
        l++;
    }
    cout<<ans<<endl; 
}