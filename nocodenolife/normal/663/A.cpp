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
int n;
bool checkPossible(int pos, int neg, int val)
{
    int maxi = pos*n - neg*1;
    int mini = 1*pos - n*neg;
    return val >= mini && val <= maxi;
}
vector<int> posNeg;

void solve()
{
    char c;
    posNeg.pb(1);
    int pos = 1;
    int neg = 0;
    while(true)
    {
        cin>>c;
        if(c=='?')
            continue;
        if(c=='+')
        {
            pos++;
            posNeg.pb(1);
        }
        else if(c=='-')
        {
            neg++;
            posNeg.pb(0);
        }
        else if(c=='=')
        {
            break;
        }
    }
    cin>>n;

    if(!checkPossible(pos,neg,n))
    {
        cout<<"Impossible"<<endl;
        return;
    }

    cout<<"Possible"<<endl;
    int u,v,w;
    w = n;
    for(int i=0;i<posNeg.size();i++)
    {
        u = posNeg[i];
        //u = 1 => positive;
        if(u==1)
        {
            pos--;
        }
        if(u==0)
        {
            neg--;
            u = -1;
        }

        for(int val=1;val<=n;val++)
        {
            if(checkPossible(pos,neg,w-(val*u)))
            {
                cout<<val<<" ";
                w = w - (val*u);

                break;
            }
        }

        if(i!= posNeg.size() - 1)
        {
            c = '+';
            if(posNeg[i+1]==0)
                c = '-';
            cout<<c<<" ";
        }

    }
    cout<<"= "<<n<<endl;

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