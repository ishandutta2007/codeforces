// ./c-graph-transpositions.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

const ll MOD = 998244353;
const int MN = 2e5 + 1, LG = 20;
int N, M,
    dp1[MN][LG];
vector<int> g[2][MN];
pii dp2[MN][2];

ll fpow(ll x, ll y) {
    if (!y) return 1;
    return fpow(x * x % MOD, y / 2) * ((y & 1) ? x : 1LL) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (auto i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        g[0][a].push_back(b);
        g[1][b].push_back(a);
    }

    memset(dp1, 0x3f, sizeof dp1);
    for (auto i = 1; i <= N; i++)
        fill(dp2[i], dp2[i]+2, pii(INF, INF));

    {
        using T = tuple<int, int>;
        deque<T> q;
        dp1[1][0] = 0; q.emplace_back(1, 0);
        while (!q.empty()) {
            auto [c, lv] = q.front(); q.pop_front();
            int w = dp1[c][lv];
            // printf("c=%d lv=%d w=%d\n",c,lv,w);

            if (lv < LG-1 && dp1[c][lv+1] == INF) {
                dp1[c][lv+1] = w;
                q.emplace_front(c, lv+1);
            }
            for (auto to : g[lv & 1][c]) {
                int alt = w+1;
                if (dp1[to][lv] == INF) {
                    dp1[to][lv] = alt;
                    q.emplace_back(to, lv);
                }
            }
        }
    }
    {
        using T = tuple<int, int, int, bool>;
        priority_queue<T, vector<T>, greater<T>> pq;
        dp2[1][0] = {0, 0}; pq.emplace(0, 0, 1, 0);
        while (!pq.empty()) {
            auto [lv, w, c, lp] = pq.top(); pq.pop();
            if (pii(lv, w) > dp2[c][lp]) continue;

            if (pii(lv+1, w) < dp2[c][!lp]) {
                dp2[c][!lp] = {lv+1, w};
                pq.emplace(lv+1, w, c, !lp);
            }
            for (auto to : g[lp][c]) {
                pii alt{lv, w+1};
                if (alt < dp2[to][lp]) {
                    dp2[to][lp] = alt;
                    pq.emplace(lv, w+1, to, lp);
                }
            }
        }
    }

    int ans = INF;
    for (auto i = 0; i < LG; i++)
        ans = min(ans, dp1[N][i] + (1 << i) - 1);
    if (ans == INF) {
        auto [lv, w] = min(dp2[N][0], dp2[N][1]);
        ll ans = (fpow(2, lv)-1+w) % MOD;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
    }
    else
        cout << ans%MOD << '\n';

    return 0;
}