#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long inf = 1ll << 60;
const int N = 5010;

vector<long long> best1[N], best2[N];
vector<int> adj[N];
int size[N];
int n;

long long cost[N], sale[N];
long long b;

void dfs(int u) {
    size[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
        size[u] += size[v];
    }

    auto& b1 = best1[u];
    auto& b2 = best2[u];

    b1.resize(size[u]+1, inf);
    b2.resize(size[u]+1, inf);

    b1[1] = cost[u] - sale[u];
    b2[0] = 0;
    b2[1] = cost[u];

    int current = 1;
    for (int v : adj[u]) {
        for (int i = current; i >= 0; --i) {
            for (int j = 1; j <= size[v]; ++j) {
                b1[i+j] = min(b1[i+j], b1[i] + best1[v][j]);
                b2[i+j] = min(b2[i+j], b2[i] + best2[v][j]);
            }
        }
        current += size[v];
    }
        
    for (int i = 0; i <= size[u]; ++i) {
        b1[i] = min(b1[i], b2[i]);
    }
}
int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i] >> sale[i];
        if (i > 1) {
            int par;
            cin >> par;
            adj[par].push_back(i);
        }
    }

    dfs(1);

    auto &arr = best1[1];
    int idx = upper_bound(arr.begin(), arr.end(), b) - arr.begin() - 1;
    cout << idx << endl;

    return 0;
}