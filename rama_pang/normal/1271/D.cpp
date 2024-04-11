#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;
int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    #ifdef TESTCASE
    cin >> T;
    #else
    T = 1;
    #endif
    while (T--) {
        solve();
    }
    return 0;
}

int N, M, K;
vector<int> A, B, V;
vector<vector<int>> G, Gi;

int solve() {
    cin >> N >> M >> K;
    A.resize(N), B.resize(N), V.resize(N), G.resize(N), Gi.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> V[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v);
        Gi[v].emplace_back(u);
    }
    vector<int> take(N);
    iota(take.begin(), take.end(), 0);

    for (int i = 0; i < N; i++) {
        for (auto j : Gi[i]) take[i] = max(take[i], j);
    }

    int cur = K;
    for (int i = 0; i < N; i++) {
        if (cur < A[i]) {
            cout << -1 << "\n";
            return 0;
        }
        cur += B[i];
    }
    // for (int i = 0; i < N; i++) {
    //     cout << take[i] << " ";
    // } cout << "\n";
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b) { 
        return V[a] > V[b] || (V[a] == V[b] && take[a] > take[b]); 
    });
    int ans = 0;
    for (auto i : ord) {
        bool can = true;
        int att = K;
        for (int j = 0; j < N; j++) {
            if (att < A[j]) {
                can = false;
                // cout << "fail" << i << " " << j << "\n";
                break;
            }
            if (j == take[i]) {
                att--;
            }
            att += B[j];
        }

        if (can) {
            ans += V[i];
            B[take[i]]--;
        }
    }

    cout << ans << "\n";
}