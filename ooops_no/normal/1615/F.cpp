#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define ll long long
#define pb push_back
#define ld long double

const int MOD = 1e9 + 7;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b) {
    return (1ll * a * b % MOD);
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> s(n), t(n);
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == '?') {
                s[i] = -1;
            } else {
                s[i] = c - '0';
            }
        }
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == '?') {
                t[i] = -1;
            } else {
                t[i] = c - '0';
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != -1) {
                s[i] = (i % 2 == s[i] % 2);
            }
            if (t[i] != -1) {
                t[i] = (i % 2 == t[i] % 2);
            }
        }
        vector<int> dp(2 * n + 1), cnt(2 * n + 1);
        cnt[n] = 1;
        for (int i = 0; i < n; i++) {
            vector<int> dpp(2 * n + 1), cntt(2 * n + 1);
            vector<int> a, b;
            if (s[i] == -1) {
                a.pb(0), a.pb(1);
            } else {
                a.pb(s[i]);
            }
            if (t[i] == -1) {
                b.pb(0), b.pb(1);
            } else {
                b.pb(t[i]);
            }
            for (int j = 0; j <= 2 * n; j++) {
                if (cnt[j] == 0) continue;
                for (auto pa : a) {
                    for (auto pb : b) {
                        int new_bal = j + pa - pb;
                        dpp[new_bal] = add(dpp[new_bal], add(dp[j], mul(cnt[j], abs(new_bal - n))));
                        cntt[new_bal] = add(cntt[new_bal], cnt[j]);
                    }
                }
            }
            swap(dp, dpp);
            swap(cnt, cntt);
        }
        cout << dp[n] << endl;
    }
    return 0;
}