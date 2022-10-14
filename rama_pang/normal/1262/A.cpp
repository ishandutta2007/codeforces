#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void solve() {

    int N; cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    if (N == 1) {
        cout << 0 << "\n";
        return;
    }
    sort(A.begin(), A.end());
    int minim = 1e9 + 100;
    for (int i = 0; i < N; i++) {
        minim = min(minim, A[i].second);
    }
    int maxim = 0;
    for (int i = 0; i < N; i++) {
        maxim = max(maxim, A[i].first);
    }
    cout << max(0, maxim - minim) << "\n";
    return;
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