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

const int maxn = 7e3 + 7;

const ll inf = 1e9 + 7;

int dp[2][maxn],num[2][maxn];
int n;
vector<int> v[2];


void bfs()
{
    queue<pair<int,int> > que;
    que.push(make_pair(0,0));
    que.push(make_pair(1,0));
    while(!que.empty())
    {
        int p=que.front().first;
        int pos=que.front().second;
        int x=dp[p][pos];
        que.pop();
        if(x==0)
        {
            for(int i=0; i<v[!p].size(); i++)
            {
                int nxt=(pos-v[!p][i]+n)%n;
                if(dp[!p][nxt]==-1)
                {
                    dp[!p][nxt]=1;
                    que.push(make_pair(!p,nxt));
                }
            }
        }
        else
        {
            for(int i=0; i<v[!p].size(); i++)
            {
                int nxt=(pos-v[!p][i]+n)%n;
                if(dp[!p][nxt]!=-1) continue;
                if(num[!p][nxt]<v[!p].size()) num[!p][nxt]++;
                if(num[!p][nxt]==v[!p].size())
                {
                    dp[!p][nxt]=0;
                    que.push(make_pair(!p,nxt));
                }
            }

        }
    }

}

int32_t main ()
{
    IOS;
    memset(dp,-1,sizeof(dp));
    memset(num,0,sizeof(num));
    cin>>n;
    for(int i=0; i<2; i++)
    {
        int k;
        cin>>k;
        for(int j=0; j<k; j++)
        {
            int m;
            cin>>m;
            v[i].push_back(m);
        }
    }
    dp[0][0]=dp[1][0]=0;
    bfs();
    for(int i=0; i<2; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(dp[i][j]==0) cout<<"Lose"<<' ';
            else if(dp[i][j]==1) cout<<"Win"<<' ';
            else cout<<"Loop"<<' ';
        }
        cout<<endl;
    }
    return 0;
}