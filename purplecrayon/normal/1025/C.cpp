#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    string t = s + s;
    int ans = 0;
    for (int i = 0; i < sz(s); i++) {
        int j = i;
        while (j < sz(t) - 1 && t[j + 1] != t[j]) j++;
        ans = max(ans, j - i + 1);
        i = j;
    }
    cout << min(ans, sz(s)) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}