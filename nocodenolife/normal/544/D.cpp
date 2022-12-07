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

const int maxn = 3e3 + 7;

const ll inf = 1e9 + 7;

ll dist[maxn][maxn];
vector<ll> graph[maxn];
queue<ll> q;
bool visited[maxn];

void BFS(ll s)
{
    memset(visited,false,sizeof(visited));
    visited[s] = true;
    dist[s][s] = 0;
    while(!q.empty())
        q.pop();
    q.push(s);
    ll x,v;
    while(!q.empty())
    {
        x = q.front();
        q.pop();

        for(ll i=0;i<graph[x].size();i++)
        {
            v = graph[x][i];
            if(visited[v]==true)
                continue;
            visited[v] = true;
            q.push(v);
            dist[s][v] = dist[s][x]+1;
        }
    }
    return;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    memset(dist,-1,sizeof(dist));
    ll n,m,u,v,w;
    cin>>n>>m;

    for(ll i=0;i<m;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for(ll i=1;i<=n;i++)
        BFS(i);
    
    ll s1,t1,l1,s2,t2,l2;
    cin>>s1>>t1>>l1>>s2>>t2>>l2;

    if(dist[s1][t1]==-1 || dist[s1][t1]>l1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    if(dist[s2][t2]==-1 || dist[s2][t2]>l2)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    ll ans = dist[s2][t2]+dist[s1][t1];
    //cout<<m-ans<<endl; 
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(dist[s1][i]==-1 || dist[s2][i]==-1|| dist[i][j] ==-1|| dist[j][t1]==-1|| dist[j][t2]==-1)
                continue;
            v = dist[s1][i] + dist[i][j] + dist[j][t1];
            w = dist[s2][i] + dist[i][j] + dist[j][t2];

            if(v<=l1 && w<=l2)
            {
                u = dist[s1][i] + dist[s2][i] + dist[i][j] + dist[j][t1] + dist[j][t2];
                //cout<<"i: "<<i<<" j: "<<j<<" u: "<<u<<endl;
                ans = min(ans,u);
            }

            v = dist[s1][i] + dist[i][j] + dist[j][t1];
            w = dist[s2][j] + dist[j][i] + dist[i][t2];

            if(v<=l1 && w<=l2)
            {
                u = dist[s1][i] + dist[s2][j] + dist[i][j] + dist[j][t1] + dist[i][t2];
                //cout<<"i: "<<i<<" j: "<<j<<" u: "<<u<<endl;
                ans = min(ans,u);
            }


        }
    }

    ans = m-ans;
    cout<<ans<<endl;

    return 0;

}