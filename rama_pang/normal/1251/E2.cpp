#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int solve() {
    int N;
    cin >> N;
    vector<vector<int>> V(N);
    for (int i = 0; i < N; i++) {
        int m, p;
        cin >> m >> p;
        V[m].emplace_back(p);
    }

    int prefix = N;
    lint ans = 0;
    int bought = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = N - 1; i >= 0; i--) {
        prefix -= V[i].size();
        for (auto j : V[i]) {
            pq.emplace(j);
        }
        while (bought + prefix < i) {
            bought++;
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}