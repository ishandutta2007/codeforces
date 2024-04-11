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

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;

ll parent[100005];
ll ranki[100005];
vector<ll> switches[100005];

vector<ll> graph[100005];
map<pair<ll,ll>,ll> added;
ll visited[100005];
bool value;

void dfs(ll val)
{
    ll u;
    for(ll i=0;i<graph[val].size();i++)
    {
        u = graph[val][i];
        if(visited[u]==0)
        {
            visited[u] = 3 - visited[val];
            dfs(u);
        }
        if(visited[u]==visited[val])
            value = true;
    }
    return;
}

void checkOdd()
{
    for(ll i=0;i<100005;i++)
    {
        if(visited[i]!=0)
            continue;
        
        visited[i] = 1;
        dfs(i);
    }
}

ll find(ll val)
{
    if(parent[val]==-1)
        return val;
    parent[val] = find(parent[val]);
    return parent[val];
}

void merge(ll x, ll y)
{
    x = find(x);
    y = find(y);
    if(x==y)
        return;
    if(ranki[x]>ranki[y])
    {
        ranki[x]+=ranki[y];
        parent[y] = x;
    }
    else
    {
        ranki[y]+=ranki[x];
        parent[x] = y;
    }
    return;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    
    memset(ranki,0,sizeof(ranki));
    memset(parent,-1,sizeof(parent));
    memset(visited,0,sizeof(visited));
    
    ll n,m,tem;
    cin>>n>>m;
    vector<ll> zer;
    vector<ll> ones;
    
    for(ll i=1;i<=n;i++)
    {
        cin>>tem;
        if(tem==0)
            zer.pb(i);
        else
            ones.pb(i);
    }
    ll lock;
    for(ll i=1;i<=m;i++)
    {
        cin>>tem;
        for(ll j=1;j<=tem;j++)
        {
            cin>>lock;
            switches[lock].pb(i);
        }
    }
    
    for(ll i=0;i<ones.size();i++)
    {
        tem = ones[i];
        merge(switches[tem][0], switches[tem][1]);
    }
    ll u,v;
    for(ll i=0;i<zer.size();i++)
    {
        tem = zer[i];
        u = find(switches[tem][0]);
        v = find(switches[tem][1]);
        if(u==v)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(added[{u,v}]>0)
            continue;
        //cout<<u<<" "<<v<<endl;
        graph[u].pb(v);
        graph[v].pb(u);
        added[{u,v}]=1;
        added[{v,u}]=1;
    }
    value = false;
    checkOdd();
    //for(ll i=1;i<=n;i++)
      //  cout<<visited[i]<<endl;
    if(value)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}