// ./e-paired-payment.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct ed {
    int v, pw; ll w;
    bool operator<(const ed &o) const {
        return w > o.w;
    }
};

const int MN = 1e5 + 1, MW = 51;
int N, M;
vector<ed> g[MN];
ll dis[MN][MW];
priority_queue<ed> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (auto i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, -1, w});
        g[b].push_back({a, -1, w});
    }
    memset(dis, 0x3f, sizeof dis);
    dis[1][0] = 0LL; pq.push({1, 0, 0LL});
    while (!pq.empty()) {
        auto c = pq.top(); pq.pop();
        if (c.w > dis[c.v][c.pw]) continue;
        for (auto to : g[c.v]) {
            if (c.pw != 0) {
                ll alt = c.w + (c.pw + to.w) * (c.pw + to.w);
                if (alt < dis[to.v][0]) {
                    dis[to.v][0] = alt;
                    pq.push({to.v, 0, alt});
                }
            }
            else {
                if (c.w < dis[to.v][to.w]) {
                    dis[to.v][to.w] = c.w;
                    pq.push({to.v, (int)to.w, c.w});
                }
            }
        }
    }
    for (auto i = 1; i <= N; i++) cout << (dis[i][0] == LLINF ? -1 : dis[i][0]) << ' ';
    cout << '\n';

    return 0;
}