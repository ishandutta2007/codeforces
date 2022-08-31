#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (auto c : s) if (c == '0') ans++;
    if (ans % 2 == 0 || ans == 1) cout << "BOB\n";
    else cout << "ALICE\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}