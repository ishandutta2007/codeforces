#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define TESTCASE



int solve() {

    lint N, P, K;
    cin >> N >> P >> K;
    vector<lint> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(begin(A), end(A));
    lint cost[N] = {};
    for (int i = 0; i < K - 1; i++) {
        cost[i] = A[i];
        if (i > 0) {
            cost[i] += cost[i - 1];
        }
    }
    cost[K - 1] = A[K - 1];
    for (int i = K; i < N; i++) {
        cost[i] = A[i];
        if (i - K >= 0) {
            cost[i] += cost[i - K];
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (cost[i] <= P) {
            res = i + 1;
        }
    }
    cout << res << "\n";
    return 0;

    auto check = [&](lint n) {
        if (n == 0) {
            return 0ll;
        }
        lint c = 0;
        int i;
        for (i = n - 1; i >= 0; i -= K) {
            c += A[i];
        }
        i += K;
        for (int j = 0; j < i; j++) {
            c += A[j];
        }

        return c;
    };

    lint l = 0, r = N, ans = 0;
    while (l <= r) {
        lint m = (l + r) / 2;
        if (check(m) <= P) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    // cout << check(ans) << " ";
    cout << ans << "\n";

}

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