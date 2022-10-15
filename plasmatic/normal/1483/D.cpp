// ./d-useful-edges.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

using pli = pair<ll, int>;
using pii = pair<int, int>;

const int MN = 601, MM = MN*(MN-1)/2;
int N, M, Q,
    A[MM], B[MM], W[MM];
vector<pii> g[MN];
ll dis[MN][MN];

bool useful[MM];
vector<pli> paths[MN];

ll minw[MN];
bool incl[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    memset(dis, 0x3f, sizeof dis);
    for (auto i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
        A[i] = a; B[i] = b; W[i] = w;
        dis[a][b] = min(dis[a][b], (ll)w);
        dis[b][a] = min(dis[b][a], (ll)w);
    }
    for (auto i = 1; i <= N; i++)
        dis[i][i] = 0;
    for (auto k = 1; k <= N; k++)
        for (auto i = 1; i <= N; i++)
            for (auto j = 1; j <= N; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    // for (auto i = 1; i <= N; i++) {
    //     memset(dis[i], 0x3f, sizeof dis[i]);
    //     dis[i][i] = 0;
    //     priority_queue<pli, vector<pli>, greater<pli>> pq; pq.emplace(0, i);
    //     while (!pq.empty()) {
    //         auto [w, c] = pq.top(); pq.pop();
    //         if (w > dis[i][c]) continue;
    //         for (auto [to, tw] : g[c]) {
    //             tw += w;
    //             if (dis[i][to] > tw) {
    //                 dis[i][to] = tw;
    //                 pq.emplace(tw, to);
    //             }
    //         }
    //     }
    // }

    cin >> Q;
    for (auto i = 0; i < Q; i++) {
        int u, v, l; cin >> u >> v >> l;
        paths[u].emplace_back(l, v);
        paths[v].emplace_back(l, u);
    }

    for (auto i = 1; i <= N; i++) {
        fill(minw, minw+N+1, -LLINF);
        fill(incl, incl+N+1, false);
        for (auto [l, v] : paths[i]) {
            for (auto j = 1; j <= N; j++)
                minw[j] = max(minw[j], l - dis[j][v]);
            // printf("adding path l=%lld v=%d\n", l,v);
        }
        // vector<pli> minws;
        // // printf("testing endpoint i=%d\n", i);
        // for (auto j = 1; j <= N; j++) {
        //     // printf("j=%d minw=%lld\n", j,minw[j]);
        //     minws.emplace_back(minw[j], j);
        // }
        // sort(minws.begin(), minws.end());

        // int ptr = N-1;
        // vector<pli> edges;
        for (auto j = 0; j < M; j++) {
            ll icost = dis[i][A[j]] + W[j];
            // edges.emplace_back(dis[i][A[j]] + W[j], j);
            useful[j] |= icost <= minw[B[j]];
        }
        // sort(edges.begin(), edges.end(), greater<>());
        // for (auto [icost, j] : edges) {
        //     while (ptr >= 0 && minws[ptr].first >= icost) {
        //         // auto [w, j] = minws[ptr];
        //         // printf("ADD minw wt=%lld endpoint=%d\n", w,j);
        //         incl[minws[ptr].second] = true;
        //         ptr--;
        //     }
        //     // printf("answer icost=%lld j=%d ED=%d,%d,%d\n",icost,j,A[j],B[j],W[j]);
        //     useful[j] |= incl[B[j]];
        // }
    }

    int ans = 0;
    for (auto i = 0; i < M; i++) ans += useful[i];
    cout << ans << '\n';

    return 0;
}