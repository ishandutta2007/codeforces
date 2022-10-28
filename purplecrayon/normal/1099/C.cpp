#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    string s; cin >> s;
    int k; cin >> k;
    int cur = 0;
    for (char c : s) if (c != '?' && c != '*') cur++;

    string t;
    for (char c : s) {
        if (c == '?') {
            if (cur > k) {
                cur--;
                t.pop_back();
            }
        } else if (c == '*') {
            if (cur > k) {
                cur--;
                t.pop_back();
            } else {
                while (cur < k) cur++, t.push_back(t.back());
            }
        } else {
            t.push_back(c);
        }
    }
    if (sz(t) != k) {
        cout << "Impossible\n";
        return;
    }
    cout << t << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}