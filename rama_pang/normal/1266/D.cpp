#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<lint> debt(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        debt[u] += w;
        debt[v] -= w;
    }

    vector<int> s, t;
    for (int i = 0; i < N; i++) {
        if (debt[i] > 0) {
            s.emplace_back(i);
        } else if (debt[i] < 0) {
            t.emplace_back(i);
        }
    }

    vector<tuple<int, int, lint>> ans;
    while (!s.empty() && !t.empty()) {
        int u = s.back(), v = t.back();
        lint mn = min(debt[u], -debt[v]);
        debt[u] -= mn;
        debt[v] += mn;
        if (debt[u] == 0) s.pop_back();
        if (debt[v] == 0) t.pop_back();
        ans.emplace_back(u, v, mn);
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << get<0>(i) + 1 << " " << get<1>(i) + 1 << " " << get<2>(i) << "\n";
    }

    return 0;
    
}