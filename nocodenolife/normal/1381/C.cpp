//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)))
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
    x = x%mod;
    ex = ex % (mod-1);
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
int n,x,y,u,v;
vector<int> changedTo[maxn];
int initColours[maxn];
int countColors[maxn];
int leftColour;
vector<int>sizOrder;
priority_queue<pii> pq;
pii pai;
vector<int> cols[2];

void solve()
{
    cin>>n>>x>>y;
    y = y - x;
    for(int i=1;i<=n+1;i++)
    {
        countColors[i] = 0;
        changedTo[i].clear();
    }

    for(int i=1;i<=n;i++)
    {
        cin>>initColours[i];
        countColors[initColours[i]]++;
    }

    while(!pq.empty())
        pq.pop();
    for(int i=1;i<=n+1;i++)
    {
        if(countColors[i]==0)
            leftColour = i;
        pq.push({countColors[i],i});
    }

    for(int i=0;i<x;i++)
    {
        pai = pq.top();
        pq.pop();
        countColors[pai.sc]--;
        changedTo[pai.sc].pb(pai.sc);
        pq.push({countColors[pai.sc],pai.sc});
    }

    sizOrder.clear();
    while(!pq.empty())
    {
//        cout<<pq.top().sc<<endl;
        sizOrder.pb(pq.top().sc);
        pq.pop();
    }
    assert(sizOrder.size() == n+1);
    cols[0].clear();
    cols[1].clear();

    for(int i=0;i<=n;i++)
    {
        u = sizOrder[i];
        for(int j=0;j<countColors[u];j++)
        {
            cols[0].pb(u);
//            cout<<u<<" ";
        }
    }
//    cout<<endl;

    for(int i=n;i>=0;i--)
    {
        u = sizOrder[i];
        for(int j=0;j<countColors[u];j++)
        {
            cols[1].pb(u);
//            cout<<u<<" ";
        }
    }
//    cout<<endl;
    int en = cols[0].size()-1;
    int st = 0;
    for(int i=0;i<cols[0].size();i++)
    {
        if(cols[0][i]==cols[1][i]) {
            if(cols[1][st]!=cols[1][i] && cols[0][st]!=cols[0][i])
            {
                swap(cols[1][st],cols[1][i]);
                st++;
                continue;
            }
            if(cols[1][en]!=cols[1][i] && cols[0][en]!=cols[0][i])
            {
                swap(cols[1][en],cols[1][i]);
                en--;
                continue;
            }
        }
    }

    int maxi = 0;
    for(int i=0;i<cols[0].size();i++)
    {
        if(cols[0][i]==cols[1][i]) {
            cols[1][i] = leftColour;
        } else {
            maxi++;
            if (maxi == y + 1) {
                maxi--;
                cols[1][i] = leftColour;
            }
        }
        changedTo[cols[0][i]].pb(cols[1][i]);
    }

    if(maxi<y)
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(int i=0;i<=n+1;i++)
    {
        countColors[i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        u = initColours[i];
        v = countColors[u];
        countColors[u]++;
        cout<<changedTo[u][v]<<" ";
    }
    cout<<endl;
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