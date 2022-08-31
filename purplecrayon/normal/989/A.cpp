#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e2+10, MOD = 998244353;

void solve() {
    string s; cin >> s;
    for (int i = 0; i + 3 <= sz(s); i++) {
        string t = s.substr(i, 3);
        sort(t.begin(), t.end());
        if (t == "ABC") {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}