#include <bits/stdc++.h>
// #define TESTCASE
#define int long long
using namespace std;
using lint = long long;
int solve();
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifdef TESTCASE
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
    return 0;
}

int N, K, L;
string S;
int A[1000005];
int DP[1000005];
int cnt[1000005];
int type[1000005];

int solve() {
    cin >> N >> K >> L;
    cin >> S;

    for (int i = 0; i < N; i++) {
        if ('a' <= S[i] && S[i] <= 'z') {
            A[i + 1] = 0;
        } else {
            A[i + 1] = 1;
        }
    }

    int ans = 1e18;

    auto check = [&](int lambda) {
        DP[0] = 0;
        for (int i = 1; i <= N; i++) {
            int& res = DP[i];
            res = DP[i - 1] + A[i];
            type[i] = 0;
            if (((i >= L) ? DP[i - L] : 0) + lambda < res) {
                res = (i >= L ? DP[i - L] : 0) + lambda;
                type[i] = 1;
            }
        }

        int cnt = 0;
        int cur = N;

        while (cur > 0) {
            if (type[cur] == 1) {
                cnt++;
                cur = cur - L;
            } else {
                cur--;
            }
        }

        return cnt;
    };

    int le = 0, ri = 1e18;
    while (le < ri) {
        int mid = (le + ri) / 2;
        if (check(mid) <= K) {
            ri = mid;
        } else {
            le = mid + 1;
        }
    }

    check(ri);
    ans = min(ans, DP[N] - ri * K);

    for (int i = 1; i <= N; i++) {
        A[i] = 1 - A[i];
    }

    le = 0, ri = 1e18;
    while (le < ri) {
        int mid = (le + ri) / 2;
        if (check(mid) <= K) {
            ri = mid;
        } else {
            le = mid + 1;
        }
    }

    check(ri);
    ans = min(ans, DP[N] - ri * K);

    cout << ans << "\n";

}