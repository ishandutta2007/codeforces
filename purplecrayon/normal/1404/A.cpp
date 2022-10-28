#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> v(k, -1);
    for (int i = 0; i < n; i++) if (s[i] != '?') {
        if (v[i%k] == !bool(s[i]-'0')) {
            cout << "NO\n";
            return;
        }
        v[i%k] = s[i]-'0';
    }
    int one = 0, two = 0;
    for (int i = 0; i < k; i++) {
        if (v[i] == 0) one++;
        if (v[i] == 1) two++;
    }
    if (one <= k/2 && two <= k/2) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}