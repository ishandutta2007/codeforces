#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void solve() {

    int N; cin >> N;
    priority_queue<int> pq;
    int cur = 0;
    vector<int> P(N), ans;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        if (P[i] > cur) {
            for (int j = cur + 1; j <= P[i]; j++) {
                pq.emplace(j);
            }
            cur = P[i];
        }
        if (pq.empty()) {
            cout << -1 << "\n";
            return;
        }
        ans.emplace_back(pq.top());
        pq.pop();
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TESTCASE;
    cin >> TESTCASE;
    // TESTCASE = 1;
    while (TESTCASE--) {
        solve();
    }
}