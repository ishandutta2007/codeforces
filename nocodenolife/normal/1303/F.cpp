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

const int maxn = 2e6 + 13;
const int N = 305*305;
const ll inf = 1e9 + 7;
int n,m,q;
int board[305][305];
vector<pair<pii,int>> add[maxn];
vector<pair<pii,int>> del[maxn];

int ans[maxn];
int pare[N];
int siz[N];
int val(int r, int c)
{
    return (c-1)*n + r;
}
int _find(int x)
{
    if(pare[x] == -1)
        return x;
    pare[x]  = _find(pare[x]);
    return pare[x];
}
int _union(int x, int y)
{
    x = _find(x);
    y = _find(y);
    if(x==y)
        return 0;
    if(siz[y]<siz[x])
        swap(x,y);
    siz[y]+=siz[x];
    pare[x] = y;
    return 1;
}

void colFun(int col)
{
    int x = n*m;
    for(int i=0;i<=x;i++)
    {
        siz[i] = 1;
        pare[i] = -1;
    }
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            board[i][j] = -1;
        }
    }
    dbg(cout<<col<<"------------"<<endl;)
    int a,b,r,c,u,v,w,y,z,idx;
    for(auto ev: add[col])
    {
        r = ev.first.first;
        c = ev.first.second;
        idx = ev.second;

        u = 1;
        board[r][c] = col;

        if(board[r-1][c]==col)
            u -= _union(val(r,c),val(r-1,c));
        if(board[r+1][c]==col)
            u -= _union(val(r,c),val(r+1,c));
        if(board[r][c+1]==col)
            u -= _union(val(r,c),val(r,c+1));
        if(board[r][c-1]==col)
            u -= _union(val(r,c),val(r,c-1));
        dbg(cout<<u<<"->"<<r<<" "<<c<<endl;)
        ans[idx] += u;
    }

    for(int i=0;i<=x;i++)
    {
        siz[i] = 1;
        pare[i] = -1;
    }
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            board[i][j] = -1;
        }
    }
    reverse(all(del[col]));
    for(auto ev: del[col])
    {
        r = ev.first.first;
        c = ev.first.second;
        idx = ev.second;

        u = 1;
        board[r][c] = col;

        if(board[r-1][c]==col)
            u -= _union(val(r,c),val(r-1,c));
        if(board[r+1][c]==col)
            u -= _union(val(r,c),val(r+1,c));
        if(board[r][c+1]==col)
            u -= _union(val(r,c),val(r,c+1));
        if(board[r][c-1]==col)
            u -= _union(val(r,c),val(r,c-1));
        dbg(cout<<">"<<u<<"->"<<r<<" "<<c<<endl;)
        ans[idx] -= u;
    }
}

void solve()
{
    memset(board,0,sizeof(board));
    memset(ans,0,sizeof(ans));
    cin>>n>>m>>q;

    int a,b,c;
    int cols = 0;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b>>c;
        cols = c;
        if(board[a][b]==c)
            continue;
        add[c].pb({{a,b},i});
        del[board[a][b]].pb({{a,b},i});
        board[a][b] = c;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            del[board[i][j]].pb({{i,j},q});
    }

    for(int i=0;i<=cols;i++)
    {
        colFun(i);
    }

    c = 1;
    for(int i=0;i<q;i++) {
        c += ans[i];
        cout << c << endl;
    }
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