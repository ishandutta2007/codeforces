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

const int maxn = 26;

const ll inf = 1e9 + 7;
string s;
int dp[maxn][maxn];
int coun[maxn];
int len;
int vis[maxn];
int isone[maxn];

void addEdge(int u, int v)
{
    if(dp[u][v]==0)
        coun[u]++;
    dp[u][v] = 1;
}


int AddNext(int st)
{
    int u= -1,v = -1;
    for(int i=0;i<maxn;i++)
    {
        if(dp[i][st])
        {
            if(u==-1)
                u = i;
            else
                v = i;
        }
    }
    if(u==-1)
        return -1;
    if(vis[u])
    {
        return v;
    }
    return u;
}
void solve()
{
    memset(dp,0,sizeof(dp));
    memset(coun,0,sizeof(coun));
    memset(vis,0,sizeof(vis));
    memset(isone,0,sizeof(isone));
    cin>>s;
    len = s.length();

    int u,v;
    for(int i=0;i<len-1;i++)
    {
        u = s[i] - 'a';
        v = s[i+1] - 'a';
        addEdge(u,v);
        addEdge(v,u);
    }
    stack<int> x;
    for(int i=0;i<maxn;i++)
    {
        if(coun[i]>2)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(coun[i]==1) {
            isone[i] = 1;
            x.push(i);
        }
    }

    int st;
    string ans = "";
    while(x.size()>0)
    {
        st = x.top();
        x.pop();
        if(vis[st])
            continue;
        ans.pb('a'+st);
        vis[st] = 1;
        u = st;
        while(true)
        {
            v = AddNext(u);
            if(v==-1)
                break;
            if(vis[v])
            {
                cout<<u<<endl;
                cout<<"NO"<<endl;
                return;
            }
            ans.pb('a'+v);
            vis[v] = true;
            u = v;
        }
    }

    for(int i=0;i<maxn;i++)
    {
        if(vis[i])
            continue;
        if(coun[i]>0)
        {
            cout<<"NO"<<endl;
            return;
        }
        ans.pb('a'+i);
    }
    cout<<"YES"<<endl;
    cout<<ans<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}