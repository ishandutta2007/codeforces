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

//#define int ll
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
int n;
char board[25][25];
int id[25][25];
vector<pii> inv[45];
int dp[41][1<<20];
//stores 1000+ ans;

int findAns(int pos,int mask)
{
    if(pos==n+n-2)
        return 0;
    if(dp[pos][mask]!=-1)
        return (dp[pos][mask]-1000);

    vector<int> t;
    for(int i=0;i<20;i++)
        if(mask&(1<<i))
            t.pb(i);

    int m[26];
    memset(m,0,sizeof(m));

    int r,c;
    for(int i=0;i<t.size();i++)
    {
        r = inv[pos][t[i]].F;
        c = inv[pos][t[i]].S;

        if(r<n-1)
            m[board[r+1][c]-'a']|=(1<<id[r+1][c]);
        if(c<n-1)
            m[board[r][c+1]-'a']|=(1<<id[r][c+1]);
    }
    
    int ans = pos%2==0?200:-200;
    int diff;
    for(int i=0;i<26;i++)
    {
        if(m[i])
        {
            diff = findAns(pos+1,m[i]);
            if(i==0)
                diff++;
            if(i==1)
                diff--;
            if(pos%2==0)
                ans = min(ans,diff);
            else
                ans = max(ans,diff);
        }
    }

    dp[pos][mask] = ans+1000;
    return ans;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS; 
    cin>>n;
    
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            id[i][j] = inv[i+j].size();
            inv[i+j].pb({i,j});
        }
    }

    int ans = findAns(0,1);
    if(board[0][0]=='a')
        ans++;
    if(board[0][0]=='b')
        ans--;

    if(ans==0)
        cout<<"DRAW"<<endl;
    else if(ans<0)
        cout<<"SECOND"<<endl;
    else
        cout<<"FIRST"<<endl;
}