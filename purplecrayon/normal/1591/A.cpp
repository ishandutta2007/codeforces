#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    int h = 1;
    for (int i = 0; i < n; i++) {
        if (!a[i] && (i > 0 && !a[i-1])) {
            cout << -1 << '\n';
            return;
        }
        if (a[i] && (i > 0 && a[i-1])) h += 5;
        else if (a[i]) h++;
    }
    cout << h << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}