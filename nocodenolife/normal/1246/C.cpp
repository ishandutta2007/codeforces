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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { // from [0, x-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

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

const int maxn = 2e3 + 7;

const ll inf = 1e9 + 7;

int n,m;
char graph[maxn][maxn];
int maxr[maxn][maxn];
int maxd[maxn][maxn];
int dp[maxn][maxn][2];
int sum[maxn][maxn][2];

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
           cin>>graph[i][j];
    }
    memset(dp,-1,sizeof(dp));
    memset(sum,0,sizeof(sum));
    // 0 for right
    for(int i=n-1;i>=0;i--)
    {
        for(int j = m-1;j>=0;j--)
        {
            if(j==m-1)
            {
                maxr[i][j]=0;
               // dp[i][j][0] = 0;
                //sum[i][j][0] = 0;
            }
            else
            {
                maxr[i][j] = maxr[i][j+1];
                if(graph[i][j+1]=='.')
                    maxr[i][j]++;
            }
            if(i==n-1)
            {
                maxd[i][j]=0;
                //dp[i][j][1] = 0;
                //sum[i][j][1] = 0;
            }
            else
            {
                maxd[i][j] = maxd[i+1][j];
                if(graph[i+1][j]=='.')
                    maxd[i][j]++;
            }
            //cout<<i<<" "<<j<<" "<<maxr[i][j]<<" "<<maxd[i][j]<<endl;
        }
    }
    dp[n-1][m-1][0] = 1;
    dp[n-1][m-1][1] = 1;
    sum[n-1][m-1][1] = 1;
    sum[n-1][m-1][0] = 1;
    
    int idx;

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(dp[i][j][0]==-1)
            {
                idx = maxr[i][j] + j;
                dp[i][j][0] = (sum[i][j+1][1] - sum[i][idx+1][1] + mod) % mod;
                sum[i][j][0] = (sum[i+1][j][0] + dp[i][j][0]) % mod;
            }

            if(dp[i][j][1]==-1)
            {
                idx = maxd[i][j] + i;
                dp[i][j][1] = (sum[i+1][j][0] - sum[idx+1][j][0] + mod)%mod;
                sum[i][j][1] = (sum[i][j+1][1] + dp[i][j][1]) %mod;
            }

            //cout<<i<<" "<<j<<" d "<<dp[i][j][1];
            //cout<<" r "<<dp[i][j][0]<<endl;
        }
    }

    int ans = (dp[0][0][0] + dp[0][0][1])%mod;


    if(n==1 && m==1)
        ans=1;

    cout<<ans<<endl;
    
    
    
}