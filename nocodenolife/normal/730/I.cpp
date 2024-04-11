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

const int maxn = 3e3 + 7;

const ll inf = 1e15 + 7;

struct MinCostFlow {

    static const int max_nodes = 3050;
    static const int infinity = LLONG_MAX / 1000;
    static const int IN_QUEUE = 1;
    static const int NOT_IN_QUEUE = 2;
    static const int NOT_VISITED = 3;

    vector < int > G[max_nodes];
    int cap[max_nodes][max_nodes];
    int flow[max_nodes][max_nodes];
    int cost[max_nodes][max_nodes];
    int parent[max_nodes];
    int state[max_nodes];
    int dist[max_nodes];
    deque < int > Q;

    int N;


    MinCostFlow() {

        N = max_nodes;

        for (int j = 0; j < N; j++) {
            G[j] = *new vector < int > ();
        }
        memset(cap, 0, sizeof cap);
        memset(flow, 0, sizeof flow);
        memset(cost, 0, sizeof cost);
        Q = *new deque < int > ();
    }

    void clear() {

        N = max_nodes;

        for (int j = 0; j < N; j++) {
            G[j].clear();
        }
        memset(cap, 0, sizeof cap);
        memset(flow, 0, sizeof flow);
        memset(cost, 0, sizeof cost);
        Q = *new deque < int > ();
    }

    // Nodes are in [0, N)
    // Don't send x -- y and also y -- x
    // Multiple sends of x -- y will also work to modify it
    void modifyEdge(int x, int y, int cap_, int cost_) {

        //cout << x << " -- " << y << " : " << cap_ << " $ = " << cost_ << endl;

        assert(x < N && y < N);
        cap[x][y] = cap_;
        cap[y][x] = 0;
        cost[x][y] = cost_;
        cost[y][x] = -cost_;
        G[x].pb(y); G[y].pb(x);
    }

    int flowOnEdge(int x, int y) {
        return flow[x][y];
    }

    void shortestPathsFasterAlgorithm(int s, int t) {

        //cout << s << " --> " << t << endl;

        for (int i = 0; i < N; i++) {
            dist[i] = infinity;
            state[i] = NOT_VISITED;
            parent[i] = -1;
        }

        dist[s] = 0;

        while (!Q.empty()) Q.pop_front();

        Q.push_back(s); state[s] = IN_QUEUE;

        while (!Q.empty()) {
            int u = Q.front(); Q.pop_front();
            state[u] = NOT_IN_QUEUE;
            for (int v : G[u]) {
                if (cap[u][v] - flow[u][v] > 0 && dist[v] > dist[u] + cost[u][v]) {
                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u;
                    if (state[v] == NOT_IN_QUEUE) {
                        state[v] = IN_QUEUE;
                        Q.push_front(v);
                    } else if (state[v] == NOT_VISITED) {
                        state[v] = IN_QUEUE;
                        Q.push_back(v);
                    }
                }
            }
        }
    }

    pair < int, int > minCostFlow(int s, int t, int dist_bound) {
        // if cost of path exceeds dist_bound, stop
        // solve min-cost flow using dist_bound = 0
        // solve mcmf using dist_bound = infinity

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                flow[i][j] = 0;
            }
        }

        int total_flow = 0;
        int total_cost = 0;

        while (true) {
            shortestPathsFasterAlgorithm(s, t);

            //cout << " | " << dist[t] << endl;

            if (dist[t] > dist_bound) break;

            int current = t;
            int min_cap = infinity;
            while (current != s) {
                int prev = parent[current]; // path from v -- t
                min_cap = min(min_cap, cap[prev][current] - flow[prev][current]);
                current = prev;
            }

            total_flow += min_cap;
            total_cost += dist[t] * min_cap;

            current = t;
            while (current != s) {
                //cout << current << " --- " << parent[current] << ", " ;
                int prev = parent[current];
                flow[prev][current] += min_cap;
                flow[current][prev] -= min_cap;
                current = prev;
            }
            //cout << endl;
        }

        return {total_flow, total_cost};
    }
} MCF;

int n,p,s;
int a[maxn];
int b[maxn];

vector<int> P;
vector<int> S;

void solve()
{
    cin>>n>>p>>s;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    MCF.modifyEdge(0,3030,s,0);
    MCF.modifyEdge(0,3020,p,0);

    for(int i=1;i<=n;i++)
    {
        MCF.modifyEdge(3030,i,1,3000-b[i]);
        MCF.modifyEdge(3020,i,1,3000-a[i]);
        MCF.modifyEdge(i,3040,1,0);
    }

    MCF.minCostFlow(0,3040,inf);

    int ans =0;
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        if(MCF.flowOnEdge(3030,i))
        {
            //cout<<i<<endl;
            ans+=b[i];
            S.pb(i);
        }
        if(MCF.flowOnEdge(3020,i))
        {
            //cout<<i<<endl;
            ans+=a[i];
            P.pb(i);
        }
    }

    cout<<ans<<endl;
    for(auto c:P)
    {
        cout<<c<<" ";
    }
    cout<<endl;

    for(auto c:S)
    {
        cout<<c<<" ";
    }
    cout<<endl;

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