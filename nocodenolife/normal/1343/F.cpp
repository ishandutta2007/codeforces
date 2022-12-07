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

const int maxn = 2e3 + 7;

const ll inf = 1e9 + 7;

int n;
int arr[maxn];
int pos[maxn];
int used[maxn];
vector<int> seg[maxn];

int findNextNum(int idx)
{
    int val;
    int min;
    int coun;
    int poss;
    for(int i=1;i<n;i++)
    {
        if(used[i]!=-1)
            continue;
        coun = 0;
        val = -1;
        min = idx - seg[i].size() + 1;
        poss = 1;
        for(auto v:seg[i])
        {
            if(pos[v]==-1)
            {
                coun++;
                val = v;
            } else{
                if(pos[v]>=min)
                    continue;
                poss = 0;
            }
        }

        if(poss==0 || coun!=1)
            continue;
        arr[idx] = val;
        pos[val] = idx;
        used[i] = 1;
        return 1;
    }

    return 0;
}

int solveSt(int st)
{
    for(int i=0;i<=n;i++)
    {
        arr[i] = pos[i] = used[i] = -1;
    }

    arr[1] = seg[st][0];
    arr[2] = seg[st][1];
    pos[arr[1]] = 1;
    pos[arr[2]] = 2;
    used[st] = 1;

    for(int idx=3;idx<=n;idx++)
    {
        if(findNextNum(idx)==0)
            return 0;
    }

    return 1;
}

void solve()
{
    cin>>n;
    int siz;
    int x;
    for(int i=1;i<n;i++)
    {
        seg[i].clear();
        cin>>siz;
        for(int j=0;j<siz;j++)
        {
            cin>>x;
            seg[i].pb(x);
        }
    }

    for(int i=1;i<n;i++)
    {
        if(seg[i].size()==2)
        {
            if(solveSt(i)==1)
            {
                for(int j=1;j<=n;j++)
                {
                    cout<<arr[j]<<" ";
                }
                cout<<endl;
                return;
            }
            reverse(all(seg[i]));
            if(solveSt(i)==1)
            {
                for(int j=1;j<=n;j++)
                {
                    cout<<arr[j]<<" ";
                }
                cout<<endl;
                return;
            }
            reverse(all(seg[i]));
        }
    }


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