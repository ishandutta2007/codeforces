#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

void solve() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        if (s[0] == '0' || s[0] == 'X' || s[0] == '_') {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
        return;
    }
    if (s[0] == '0') {
        cout << "0\n";
        return;
    }
    bool havex = false;
    int n = s.size();
    int ways = 1;
    for (int i = 1; i + 2 < n; ++i) {
        if (s[i] == '_') ways *= 10;
        if (s[i] == 'X') havex = true;
    }
    char a = s[n - 2];
    char b = s[n - 1];
    int ans = 0;
    for(int t = 0; t < 100; t += 25) {
        int c = t / 10;
        int d = t % 10;
        int x = -1;
        if ('0' <= a && a <= '9') {
            if (c != (a - '0')) continue;
        } else if (a == 'X') {
            x = c;
        }
        if ('0' <= b && b <= '9') {
            if (d != (b - '0')) continue;
        } else if (b == 'X') {
            if (x != d && x != -1) continue;
            x = d;
        }
        int cur = ways;
        if (s.size() == 2) {
            if (t == 0) continue;
            ans++;
            continue;
        }
        if (s[0] == '_') cur *= 9;
        if (s[0] == 'X') {
            if (x == 0) continue;
            if (x == -1) cur *= 9;
        } else {
            if (havex && x == -1) cur *= 10;
        }
        ans += cur;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}