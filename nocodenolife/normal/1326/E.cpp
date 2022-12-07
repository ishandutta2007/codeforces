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

const int maxn = 3e5 + 7;

const ll inf = 1e9 + 7;

ll seg[maxn*4];
ll lazy[maxn*4];

void update(int idx, int l,int r, int ql, int qr, int val)
{
    if(r<ql||l>qr)
        return;
    if(r<=qr && l>=ql)
    {
        lazy[idx]+=val;
        seg[idx]+=val;
        return;
    }
    if(lazy[idx])
    {
        seg[idx<<1]+=lazy[idx];
        seg[idx<<1|1]+=lazy[idx];
        lazy[idx<<1]+=lazy[idx];
        lazy[idx<<1|1]+=lazy[idx];
        lazy[idx] = 0;
    }
    int m = l+r;
    m/=2;
    update(idx<<1,l,m,ql,qr,val);
    update(idx<<1|1,m+1,r,ql,qr,val);
    seg[idx] = max(seg[idx<<1],seg[idx<<1|1]);
    dbg(if(idx==1)
            cout<<seg[idx]<<" "<<ql<<"->"<<qr<<" by "<<val<<endl;)
}

int findMax(int idx, int l,int r, int ql, int qr)
{
    if(r<ql||l>qr)
        return -inf;
    if(r<=qr && l>=ql)
    {
        return seg[idx];
    }
    //assert(false);
    if(lazy[idx]>0)
    {
        seg[idx<<1]+=lazy[idx];
        seg[idx<<1|1]+=lazy[idx];
        lazy[idx<<1]+=lazy[idx];
        lazy[idx<<1|1]+=lazy[idx];
        lazy[idx] = 0;
    }
    int m = l+r;
    m/=2;
    int ans = -inf;
    ans = max(ans,findMax(idx<<1,l,m,ql,qr));
    ans = max(ans,findMax(idx<<1|1,m+1,r,ql,qr));
    seg[idx] = max(seg[idx<<1],seg[idx<<1|1]);
    return ans;
}

int n;
int p[maxn];
int q[maxn];
int pos[maxn];

void solve()
{
    memset(seg,0, sizeof(seg));
    memset(lazy,0,sizeof(lazy));

    cin>>n;
    for(int i=1;i<=n;i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for(int i=1;i<=n;i++)
        cin>>q[i];
    int ans = n;
    update(1,1,n,1,pos[n],1);
    cout<<ans<<" ";
    for(int i=1;i<n;i++)
    {
        update(1,1,n,1,q[i],-1);
        //dbg(cout<<"up1"<<endl;)
        while(findMax(1,1,n,1,n)<=0 && ans>1)
        {
            ans--;
            //dbg(cout<<findMax(1,1,n,1,n)<<" Ans Dec "<<ans<<endl;)
            update(1,1,n,1,pos[ans],1);
        }
        dbg(cout<<"findMax: "<<findMax(1,1,n,1,n)<<endl;)
        cout<<ans<<" ";
    }
    cout<<endl;
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