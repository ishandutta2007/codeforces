#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solvePlusMul(vector<int> &a) {
    int n = a.size();
    if (a.size() == 1) {
        cout << a[0];
        return;
    }
    {
        int tt = 0;
        while (tt < n && a[tt] == 1) {
            tt++;
        }
        if (tt != 0) {
            cout << "1";
            range(i, tt - 1) cout << "+1";
            if (tt == n) return;
            cout << "+";
            vector<int> b;
            for (int i = tt; i < n; ++i) b.push_back(a[i]);
            solvePlusMul(b);
            return;
        }
    }
    {
        int tt = n - 1;
        while (tt >= 0 && a[tt] == 1) {
            tt--;
        }
        if (tt != n - 1) {
            vector<int> b;
            for (int i = 0; i <= tt; ++i) b.push_back(a[i]);
            if (tt != -1) {
                solvePlusMul(b);
                cout << '+';
            }
            cout << "1";
            for (int i = n - 2; i > tt; --i) cout << "+1";
            return;
        }
    }
    ll x = 1;
    range(i, n) {
        x *= a[i];
        if (x > n * 2) {
            range(j, n) {
                cout << a[j];
                if (j + 1 != n) cout << '*';
            }
            return;
        }
    }
    vector<pair<int, int>> kek;
    range(i, n) {
        if (i == 0 || a[i] != a[i - 1] || a[i] != 1) {
            kek.emplace_back(a[i], 0);
        }
        kek.back().second++;
    }
    vector<ll> dp(kek.size() + 1), pref(kek.size() + 1);
    int kn = kek.size();
    dp[0] = 0;
    range(i, kn) {
        dp[i + 1] = dp[i] + kek[i].first * kek[i].second;
        pref[i + 1] = i;
        ll cur = kek[i].first;
        for (int j = i - 1; j >= 0; --j) {
            cur *= kek[j].first;
            if (cur + dp[j] > dp[i + 1]) {
                dp[i + 1] = dp[j] + cur;
                pref[i + 1] = j;
            }
        }
    }
    vector<string> res;
    int j = kn;
    for (int i = kn; i >= 1; --i) {
        if (i == j) {
            res.push_back("");
            j = pref[j];
        }
        if (j + 1 == i && kek[i - 1].first == 1) {
            string cw = "1";
            range(w, kek[i - 1].second - 1) cw += "+1";
            res.back() += cw;
            continue;
        }
        range(_, kek[i - 1].second) {
            if (!res.back().empty()) {
                res.back() += "*";
            }
            res.back() += (char) (kek[i - 1].first + '0');
        }
    }
    reverse(all(res));
    range(i, (int) res.size()) {
        reverse(all(res[i]));
        cout << res[i];
        if (i + 1 != res.size()) cout << "+";
    }
}

void solveMulSub(vector<int> &a) {
    int n = a.size();
    vector<bool> has(n - 1, 0);
    for (int i = 0, j = 0; i < n; i = j) {
        if (a[i] != 1) {
            j++;
            continue;
        }
        while (j < n && a[j] == 1) j++;
        if (j < n) {
            has[j - 1] = true;
        } else if (i > 0) {
            has[i - 1] = true;
        }
        for (int e = i; e < j - 1; ++e) has[e] = true;
    }
    range(i, n) {
        cout << a[i];
        if (i + 1 < n) {
            if (has[i]) cout << '*';
            else cout << '-';
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    string s;
    cin >> s;
    int was = 0;
    for (auto &c : s) {
        if (c == '*') was |= 1;
        if (c == '-') was |= 2;
        if (c == '+') was |= 4;
    }
    if (was >= 4) was &= 5;
    if (__builtin_popcount(was) == 1) {
        char x;
        if (was == 1) x = '*';
        if (was == 2) x = '-';
        if (was == 4) x = '+';
        range(i, n) {
            cout << a[i];
            if (i + 1 != n) cout << x;
        }
        return;
    }
    if (was == 3) {
        bool finded = false;
        range(i, n) {
            if (!finded && a[i] == 0) {
                finded = true;
                if (i) cout << '-';
            } else if (i) {
                cout << '*';
            }
            cout << a[i];
        }
        return;
    }
    vector<int> kek;
    range(i, n) {
        if (a[i] == 0) {
            if (!kek.empty()) {
                solvePlusMul(kek);
                cout << "+0";
            } else {
                cout << "0";
            }
            kek.clear();
            if (i + 1 != n) cout << "+";
        } else {
            kek.push_back(a[i]);
        }
    }
    if (!kek.empty()) {
        solvePlusMul(kek);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}