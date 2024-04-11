/*  Answer for first quqery is indegree * outdegree
    for all v in graph.

    Sort all vertices by their degrees in descending
    order. Observe that v has at most sqrt(2m) edges
    connecting from left to v. If there are more than
    sqrt(2m) edges, than that would mean there are more
    than sqrt(2m) vertices on the left. But that would mean
    there are sqrt(2m) vertices on the left with more than 
    sqrt(2m) = more than 2m edges, which is a contradiction.

    Thus we will swap edges at most O(m + qsqrt(m)) times,
    as the start potential is O(m) and each query increases
    the potential by at most sqrt(m).

*/

#include <bits/stdc++.h>
using namespace std;
using lint = long long;
vector<int> in[100005]; // we will only reverse this one
int out[100005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        in[min(u, v)].emplace_back(max(u, v));
        out[max(u, v)]++;
    }

    lint ans = 0;
    for (int i = 0; i < N; i++) 
        ans += 1ll * in[i].size() * out[i];

    cout << ans << "\n";
    int Q; cin >> Q;
    while (Q--) {
        int v; cin >> v;
        ans -= 1ll * out[v] * in[v].size();
        out[v] += in[v].size();
        for (auto &nxt : in[v]) {
            ans -= 1ll * out[nxt] * in[nxt].size();
            out[nxt]--;
            in[nxt].emplace_back(v);
            ans += 1ll * out[nxt] * in[nxt].size();
        }

        cout << ans << "\n";
        in[v].clear();
    }

    return 0;
}