#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    string s; cin >> s;
    if (s.back() != 'B') {
        cout << "NO\n";
        return;
    }

    int a = 0, b = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'A') {
            a++;
        } else {
            b++;
        }
        if (b > a) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}