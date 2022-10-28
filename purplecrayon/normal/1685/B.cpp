#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    string s; cin >> s;

    int cnt[2] = {};
    for (char c : s) cnt[c - 'A']++;
    if (cnt[0] != a + c + d || cnt[1] != b + c + d) {
        cout << "NO\n";
        return;
    }
    int n = sz(s);

    // ABA -> 1AB, 1BA
    // ABAB -> 2AB, 1BA
    //
    // either one extra of one type, or the same possible thing
    // use ABAB (with even length) for c first and then use BABA (with even length) for d first and then just tile greedily

    vector<string> use;
    vector<string> greedy;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n-1 && s[j+1] != s[j]) j++;

        int len = j - i + 1;
        if (len < 2) continue;

        string t = s.substr(i, len);
        use.push_back(t);

        i = j;
    }
    sort(use.begin(), use.end(), [&](const string& a, const string& b) { return sz(a) < sz(b); });
    for (auto t : use) {
        int len = sz(t);
        if (len % 2 == 0) {
            if (t[0] == 'A') {
                int cur = 0;
                while (c && cur < sz(t)-1) {
                    c--;
                    cur += 2;
                }
                if (cur < sz(t)) {
                    greedy.push_back(t.substr(cur));
                }
            } else {
                int cur = 0;
                while (d && cur < sz(t)-1) {
                    d--;
                    cur += 2;
                }
                if (cur < sz(t)) {
                    greedy.push_back(t.substr(cur));
                }
            }
        } else {
            greedy.push_back(t);
        }
    }

    for (auto& t : greedy) if (sz(t) > 1) {
        if (t[0] == 'A') {
            int cur = 0;
            while (c && cur < sz(t)-1) {
                c--;
                cur += 2;
            }
            if (cur < sz(t)) {
                t = t.substr(cur);
            } else {
                t = "";
            }
        } else {
            int cur = 0;
            while (d && cur < sz(t)-1) {
                d--;
                cur += 2;
            }
            if (cur < sz(t)) {
                t = t.substr(cur);
            } else {
                t = "";
            }
        }
    }
    for (auto& t : greedy) if (sz(t) > 1) {
        t = t.substr(1);
        if (t[0] == 'A') {
            int cur = 0;
            while (c && cur < sz(t)-1) {
                c--;
                cur += 2;
            }
            if (cur < sz(t)) {
                t = t.substr(cur);
            } else {
                t = "";
            }
        } else {
            int cur = 0;
            while (d && cur < sz(t)-1) {
                d--;
                cur += 2;
            }
            if (cur < sz(t)) {
                t = t.substr(cur);
            } else {
                t = "";
            }
        }
    }

    if (c || d) cout << "NO\n";
    else cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}