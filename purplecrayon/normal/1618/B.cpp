#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<string> a(n-2); for (auto& s : a) cin >> s;
    for (int i = 0; i < n-3; i++) {
        if (a[i][1] != a[i+1][0]) {
            cout << a[0];
            for (int j = 1; j <= i; j++) cout << a[j][1];
            cout << a[i+1];
            for (int j = i+2; j < n-2; j++) cout << a[j][1];
            cout << '\n';
            return;
        }
    }
    cout << 'a' << a[0][0];
    for (auto c : a) cout << c[1];
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}