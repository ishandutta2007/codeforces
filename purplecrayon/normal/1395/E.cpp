#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, k; ll ans=0;
vector<pair<ll, int>> adj[MAXN];
bool bad[MAXK][MAXK][MAXK][MAXK], sbad[MAXK][MAXK];
bitset<MAXN> in[MAXK][MAXK];
int cperm[MAXK];

void rec(int i){
    if (i > k) { 
        bool cbad=0;
        for (int i = 1; i <= k && !cbad; i++) for (int j = 1; j <= k && !cbad; j++) if (i!=j && bad[i][cperm[i]][j][cperm[j]]) cbad=1;
        ans+=!cbad;
        // for (int i = 1; i <= k; i++) cout << cperm[i] << ' '; cout << '\n';
        return;
    }
    for (int j = 0; j < i; j++) if (!sbad[i][j]) {
        cperm[i] = j;
        rec(i+1);
    }
}
void solve(){
    cin >> n >> m >> k;
    //want to make sure that the in-degree of every node in the induced graph is equal to one
    //no node can have an indegree of zero -> means a node has indegree > 0 bcs the sum of indegrees is n
    for (int i = 0; i < m; i++){
        int a, b; ll w; cin >> a >> b >> w, --a, --b;
        adj[a].emplace_back(w, b);
    }
    //bad[i][j][k][l] means that i can't put a j in the i'th position as well as an l in the k'th position
    memset(bad, 0, sizeof(bad)); memset(in, 0, sizeof(in)); memset(sbad, 0, sizeof(sbad));
    for (int i = 0; i < n; i++){
        sort(adj[i].begin(), adj[i].end());
        int ck=sz(adj[i]);
        for (int j = 0; j < ck; j++){
            int nxt=adj[i][j].second;
            if (in[ck][j][nxt]) sbad[ck][j] = 1;
            in[ck][j][nxt] = 1;
        }
    }
    for (int i = 1; i <= k; i++){
        for (int j = 0; j < k; j++){
            for (int f = 1; f <= k; f++){
                for (int g = 0; g < k; g++){
                    bad[i][j][f][g] |= !(in[i][j]&in[f][g]).none();
                }
            }
        }
    }
    // for (int i = 1; i <= k; i++) for (int j = 0; j < k; j++) for (int f = 1; f <= k; f++) for (int g = 0; g < k; g++) cout << i << ' ' << j << ' ' << f << ' ' << g << ' ' << bad[i][j][f][g] << '\n';
    rec(1);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}