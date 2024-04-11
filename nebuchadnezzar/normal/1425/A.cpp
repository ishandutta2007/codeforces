#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100;

ll greedy(ll t) {
    if (t % 2 == 1) {
        return t - greedy(t - 1);
    }
    ll s = 0;
    bool cur = true;
    while (t > 0) {
        ll step = 1;
        if (t % 2 == 0 && (t == 4 || t % 4 != 0)) {
            step = t / 2;
        }
        if (cur) {
            s += step;
        }
        t -= step;
        cur = !cur;
    }
    return s;
}

ll smart(ll t) {
    if (t % 2 == 1) {
        return t - smart(t - 1);
    }
    ll e = 2;
    int ones = 1;
    while (true) {
        ll next = e * 4 + 2;
        if (next > t) {
            break;
        }
        e = next;
        ones += 1;
    }
    return (t - e) / 2 + (e - ones);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

//    vector<vector<int> > dp(N, vector<int>(2));
//    for (int i = 1; i < N; i++) {
//        dp[i][0] = dp[i - 1][1] + 1;
//        dp[i][1] = dp[i - 1][0];
//        if (i % 2 == 0) {
//            dp[i][0] = max(dp[i][0], dp[i / 2][1] + i / 2);
//            dp[i][1] = min(dp[i][1], dp[i / 2][0]);
//        }
//    }
//    for (int i = 0; i < N; i++) {
//        cout << i << ' ' << dp[i][0] << ' ' << greedy(i) << '\n';
//    }
    int n;
    cin >> n;
    while (n--) {
        ll t;
        cin >> t;
        ll s = greedy(t);
        cout << s << '\n';
    }
    return 0;
}