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

vector<ll> graph[100005];
vector<ll> not_adj;
ll assign[100005];
ll arr[100005];
ll degree[100005];
ll n,m;

void findNotAdj(ll ver)
{
    not_adj.clear();
    memset(arr,0,sizeof(arr));

    for(ll i=0;i<graph[ver].size();i++)
    {
        arr[graph[ver][i]]++;
    }

    for(ll i=1;i<=n;i++)
    {
        if(arr[i]==0 && i!=ver)
        {
            not_adj.pb(i);
        }
    }
    return;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
   cin>>n>>m;
   ll u,v;
   memset(degree,0,sizeof(degree));
    for(ll i=0;i<m;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
        degree[u]++;
        degree[v]++;
    }
    
    memset(assign, -1, sizeof(assign));
    ll st;
    ll siz[4];
    for(ll g=1;g<=3;g++)
    {   
        st = -1;
        for(ll i=1;i<=n;i++)
        {
            if(assign[i]==-1)
            {
                st = i;
                break;
            }
        }

        if(st==-1)
        {
            cout<<"-1"<<endl;
            return 0;
        }

        assign[st] = g;
        siz[g]=1;
        findNotAdj(st);

        for(ll i=0;i<not_adj.size();i++)
        {
            if(assign[not_adj[i]]!=-1)
            {
                cout<<"-1"<<endl;
                return 0;
            }
            assign[not_adj[i]] = g;
            siz[g]++;
        }
    }

    for(ll i=1;i<=n;i++)
    {
        if(assign[i]==-1)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }

    for(ll i=1;i<=n;i++)
    {
        u = n - siz[assign[i]];
        if(degree[i]!=u)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        for(ll j=0;j<graph[i].size();j++)
        {
            u = graph[i][j];
            if(assign[i]==assign[u])
            {
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    

    for(ll i=1;i<=n;i++)
    {
        cout<<assign[i]<<" ";
    }
    cout<<endl;

    //cout<<-1<<endl;
}