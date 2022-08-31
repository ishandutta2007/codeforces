#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;

    bool has = 0;
    for (int x : a) if (x == 1) has = true;

    sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end()) - a.begin());
    if (a[0] == 1 && a.back() == 1) {
        cout << "YES\n";
        return;
    } else if (has) {
        for (int i = 1; i < sz(a); i++) if (a[i] == a[i-1]+1) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
    } else {
        cout << "YES\n";
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}