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

int n,m,k;

int dp[105][105][12];
int mov[105][105][12];
int peas[105][105];

void solve()
{
    cin>>n>>m>>k;
    k++;
    memset(dp,-1, sizeof(dp));
    char c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c;
            peas[i][j] = c - '0';
            //cout<<peas[i][j]<<" ";
        }
        //cout<<endl;
    }

    for(int j=1;j<=m;j++)
    {
        dp[n][j][peas[n][j]%k] = peas[n][j];
    }

    int p,r;
    for(int i=n;i>=2;i--)
    {
        for(int j=1;j<=m;j++)
        {
            for(int rem=0;rem<k;rem++)
            {
                //move left;
                if(dp[i][j][rem]==-1)
                    continue;
                if(j>1) {
                    p = dp[i][j][rem] + peas[i - 1][j - 1];
                    r = p%k;
                    if(dp[i-1][j-1][r]==-1 || (dp[i-1][j-1][r]>=0 && p>dp[i-1][j-1][r]))
                    {
                        dp[i-1][j-1][r] = p;
                        mov[i-1][j-1][r] = 0;
                    }
                }
                if(j<m) {
                    p = dp[i][j][rem] + peas[i - 1][j + 1];
                    r = p%k;
                    if(dp[i-1][j+1][r]==-1 || (dp[i-1][j+1][r]>=0 && p>dp[i-1][j+1][r]))
                    {
                        dp[i-1][j+1][r] = p;
                        mov[i-1][j+1][r] = 1;
                    }
                }
            }
        }
    }

    int idx = 1;
    for(int i=1;i<=m;i++)
    {
        if(dp[1][i][0] > dp[1][idx][0])
            idx = i;
    }

    if(dp[1][idx][0]==-1)
    {
        cout<<-1<<endl;
        return;
    }

    cout<<dp[1][idx][0]<<endl;
    string s = "";
    int cur = dp[1][idx][0];
    int ro = 1;
    int co = idx;

    while(ro<n)
    {
        assert(cur == dp[ro][co][cur%k]);
        //cout<<cur<<" -> "<<ro<<" "<<co<<" at "<<cur%k<<endl;
        if(mov[ro][co][cur%k]==0)
        {
            s = s+"L";
            cur-=peas[ro][co];
            ro++;
            co++;
        } else{
            s = s+"R";
            cur-=peas[ro][co];
            ro++;
            co--;
        }
    }
    //cout<<cur<<" -> "<<ro<<" "<<co<<" at "<<cur%k<<endl;
    //assert(cur==0);
    cout<<co<<endl;
    reverse(all(s));
    cout<<s<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;
    int t = 1;
   // cin>>t;
    while(t--)
        solve();
}