// ./f-phoenix-and-earthquake.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

using pli = pair<ll, int>;

const int MN = 3e5 + 1;
int N, M, X,
    A[MN], B[MN];
bool use[MN];

ll val[MN];
int dsu[MN], sz[MN];
vector<int> adj[MN];
int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
void unite(int x, int y) {
    x = rt(x); y = rt(y); // y into x
    if (x == y) return;
    if (sz[y] > sz[x]) swap(x, y);
    dsu[y] = x;
    sz[x] += sz[y];
    val[x] += val[y];
    adj[x].insert(adj[x].end(), adj[y].begin(), adj[y].end());
    adj[y].clear();
    adj[y].shrink_to_fit();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X;
    ll tsum = 0;
    for (auto i = 0; i < N; i++) {
        cin >> val[i];
        tsum += val[i];
    }
    if (tsum < ll(N-1)*X) 
        return cout << "NO\n", 0;
    for (auto i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        A[i] = a; B[i] = b;
        adj[a].push_back(i);
        adj[b].push_back(i);
    }

    iota(dsu, dsu+MN, 0);
    fill(sz, sz+MN, 1);
    cout << "YES\n";
    priority_queue<pli> pq;
    for (auto i = 0; i < N; i++) pq.emplace(val[i], i);

    while (!pq.empty()) {
        auto [w, c] = pq.top(); pq.pop();
        if (c != rt(c)) continue; // skip non DSU-roots
        if (w != val[c]) continue; // some root may be inserted multiple times as it is merged (if it is the largest component), make sure to only count most recent one

        while (!adj[c].empty() && (rt(A[adj[c].back()]) == rt(B[adj[c].back()]) || use[adj[c].back()]))
            adj[c].pop_back();
        if (!adj[c].empty()) {
            int bk = adj[c].back(); adj[c].pop_back();
            unite(A[bk], B[bk]);
            use[bk] = true;
            cout << bk+1 << '\n';

            c = rt(c);
            val[c] -= X;
            assert(val[c] >= 0);
            pq.emplace(val[c], c);
        }
    }

    return 0;
}