#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n); for (auto& c : a) cin >> c;
    if (n >= 2*x) {
        cout << "YES\n";
        return;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());

    for (int i = n - x; i < x; i++) if (a[i] != b[i]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}