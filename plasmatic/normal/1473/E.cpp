// ./e-minimum-path.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pli = pair<ll, int>;

using T = tuple<ll, int, bool, bool>;

const int MN = 2e5 + 1;
int N, M;
vector<pli> g[MN];
ll dis[MN][2][2];
priority_queue<T, vector<T>, greater<T>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (auto i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }
    memset(dis, 0x3f, sizeof dis);
    dis[1][0][0] = 0LL; pq.emplace(0, 1, 0, 0);
    while (!pq.empty()) {
        auto [w, c, e1, e2] = pq.top(); pq.pop(); // e1 -> min, e2 -> max
        if (w > dis[c][e1][e2]) continue;
        auto push = [&] (ll w0, int a, bool b, bool c) {
            if (w0 < dis[a][b][c]) {
                dis[a][b][c] = w0;
                pq.emplace(w0, a, b, c);
            }
        };
        for (auto [to, tow] : g[c]) {
            ll alt = w + tow;
            push(alt, to, e1, e2);
            if (!e1)
                push(alt + tow, to, 1, e2);
            if (!e2) 
                push(alt - tow, to, e1, 1);
            if (!e1 && !e2)
                push(alt, to, 1, 1);
        }
    }
    for (auto i = 2; i <= N; i++) cout << dis[i][1][1] << ' ';
    cout << '\n';

    return 0;
}