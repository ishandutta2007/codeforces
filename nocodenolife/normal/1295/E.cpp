//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)));
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))

#define fi first
#define sc second 
#define pb push_back


#ifdef DEBUG
    #define dbg(s) {s;}
    #define PRELUDE
#endif

#ifndef DEBUG 
    #define PRELUDE { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define dbg(s)
    #define endl "\n"
#endif

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
// Ordered set docs:
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

// To remove randomization use 0 below:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

inline ld rf() { // from [0, 1]
    return uniform_real_distribution<ld>(0, 1)(rng);
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

const ll inf = 1e16 + 7;

int sum[maxn];
int mini[maxn];
int lazy[maxn];
int arr[maxn];
int a[maxn];
int p[maxn];
int inv[maxn];
int n;

void init(int idx, int l, int r)
{
    if(l==r)
    {
        sum[idx] = mini[idx] = arr[l];
        lazy[idx] = 0;
        return;
    }
    int m = l+r;
    m/=2;

    init(idx+idx,l,m);
    init(idx+idx+1,m+1,r);
    sum[idx] = sum[idx+idx] + sum[idx+idx+1];
    lazy[idx] = 0;
    mini[idx] = min(mini[idx+idx],mini[idx+idx+1]);
}

void updateRange(int idx, int l, int r, int ql, int qr, int add)
{
    if(lazy[idx]!=0)
    {
        mini[idx]+=lazy[idx];
        sum[idx]+=lazy[idx];
        if(l!=r) {
            lazy[idx + idx] += lazy[idx];
            lazy[idx + idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(r<ql || l>qr)
        return;
    if(l>=ql && r<=qr)
    {
        lazy[idx]+=add;
        if(lazy[idx]!=0)
        {
            mini[idx]+=lazy[idx];
            sum[idx]+=lazy[idx];
            if(l!=r) {
                lazy[idx + idx] += lazy[idx];
                lazy[idx + idx + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        return;
    }
    int m = l+r;
    m/=2;

    updateRange(idx+idx,l,m,ql,qr,add);
    updateRange(idx+idx+1,m+1,r,ql,qr,add);
    sum[idx] = sum[idx+idx] + sum[idx+idx+1];
    lazy[idx] = 0;
    mini[idx] = min(mini[idx+idx],mini[idx+idx+1]);
}

int findMin(int idx, int l, int r, int ql, int qr)
{
    if(lazy[idx]!=0)
    {
        mini[idx]+=lazy[idx];
        sum[idx]+=lazy[idx];
        if(l!=r) {
            lazy[idx + idx] += lazy[idx];
            lazy[idx + idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(r<ql || l>qr)
        return inf;
    if(l>=ql && r<=qr)
    {
        return mini[idx];
    }
    int m = l+r;
    m/=2;

    int cv = findMin(idx+idx,l,m,ql,qr);
    cv = min(cv,findMin(idx+idx+1,m+1,r,ql,qr));
    mini[idx] = min(mini[idx+idx],mini[idx+idx+1]);
    sum[idx] = sum[idx+idx] + sum[idx+idx+1];
    return cv;
}

void solve()
{
    cin>>n;
    for (int i = 1; i <=n ; ++i) {
        cin>>p[i];
        inv[p[i]] = i;
    }
    arr[0] = 0;
    int totsum = 0;
    for (int i = 1; i <=n ; ++i) {
        cin>>a[i];
        totsum+=a[i];
    }

    for(int i=1;i<=n;i++)
    {
        arr[i] =a[inv[i]] + arr[i-1];
        //cout<<arr[i]<<" ";
    }
    //cout<<endl;
    init(1,1,n);

    int ans = min(a[1],a[n]);

    for(int i=1;i<n;i++)
    {
        if(p[i]>1)
            updateRange(1,1,n,1,p[i]-1,a[i]);
        updateRange(1,1,n,p[i],n,-a[i]);
        ans = min(ans,findMin(1,1,n,1,n));

        //cout<<i<<" "<<ans<<endl;
    }

    cout<<ans<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}