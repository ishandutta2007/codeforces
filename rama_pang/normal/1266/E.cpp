#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define int lint

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    lint ans = 0;

    vector<lint> A(N + 10), Milestone(N + 10);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        ans += A[i];
    }

    int Q;
    cin >> Q;

    vector<map<lint, lint>> B(N + 10);
    for (int q = 0; q < Q; q++) {
        lint s, t, u;
        cin >> s >> t >> u;

        if (B[s][t] == 0) {
            B[s][t] = u;
            if (++Milestone[u] <= A[u]) {
                ans--;
            }
        } else {
            int prev = B[s][t];
            if (prev != 0 && Milestone[prev]-- <= A[prev]) {
                ans++;
            }
            B[s][t] = u;
            if (u != 0 && ++Milestone[u] <= A[u]) {
                ans--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}