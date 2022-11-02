#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int N = 2e5 + 10, MOD = 1e9 + 7;
vector<int> dp(N), pr(N);
int go[30 * N][2], now = 2, ok[30 * N], n, p, ans = 0;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

void add(string s) {
    int v = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (go[v][1] == 0) {
                go[v][1] = now++;
            }
            v = go[v][1];
        } else {
            if (go[v][0] == 0) {
                go[v][0] = now++;
            }
            v = go[v][0];
        }
    }
    ok[v] = 1;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i] = add(dp[i], dp[i - 1]);
        if (i - 2 >= 0) dp[i] = add(dp[i], dp[i - 2]);
    }
    pr[0] = 1;
    for (int i = 1; i < N; i++) {
        pr[i] = add(pr[i - 1], dp[i]);
    }
    cin >> n >> p;
    vector<int> a(n);
    set<string> was;
    vector<string> all;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        string s = "";
        for (int j = 0; j < 30; j++) {
            if (a[i] & (1 << j)) {
                s += '1';
            } else {
                s += '0';
            }
        }
        while (s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        was.insert(s);
        all.pb(s);
        add(s);
    }
    for (auto t : all) {
        bool good = 1;
        int v = 1;
        for (int j = 1; j < t.size(); j++) {
            if (t[j - 1] == '0') {
                if (go[v][0] == 0) break;
                v = go[v][0];
            } else {
                if (go[v][1] == 0) break;
                v = go[v][1];
            }
            if (ok[v]) {
                int cnt = 0;
                bool nw = 0;
                for (int k = j; k < t.size(); k++) {
                    if (t[k] == '0') {
                        cnt++;
                    } else {
                        if (cnt % 2 == 1) {
                            nw = 1;
                        }
                        cnt = 0;
                    }
                }
                if (cnt % 2 == 1) nw = 1;
                if (!nw) {
                    good = 0;
                    break;
                }
            }
        }
        if (good) {
            if (p >= t.size()) {
                ans = add(ans, pr[p - (int)(t.size())]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}