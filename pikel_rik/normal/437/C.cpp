#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e3 + 2;

ll n, m, cost[N], tot[N];
vi g[N];
bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cost[i];

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        tot[u] += cost[v];
        tot[v] += cost[u];
    }

    ll tot_cost = 0;
    tot[1001] = cost[1001] = 0;

    for (int i = 1; i <= n; i++) {
        int best = 1001;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] and cost[j] > cost[best])
                best = j;
        }

        visited[best] = true;
        for (int &x : g[best])
            tot[x] -= cost[best];

        tot_cost += tot[best];
    }

    cout << tot_cost;
    return 0;
}