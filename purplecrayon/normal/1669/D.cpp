#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = 'W' + s + 'W'; n += 2;
    for (int l = 0; l < n; l++) if (s[l] != 'W') {
        int r = l;
        while (s[r] != 'W') r++;
        r--;

        bool bad = 1;
        for (int i = l+1; i <= r; i++) if (s[i] != s[l]) bad = 0;

        if (bad) {
            cout << "NO\n";
            return;
        }


        l = r;
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}