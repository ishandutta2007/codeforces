#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 998244353;

int n, a[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> x, y;
    for (int i = 0; i <= n; i++) {
        if (!i) {
            x.push_back(-1);
            y.push_back(-1);
            continue;
        }
        int l = sz(x)-a[i-1], r = sz(x)-1;
        for (int rep = 0; rep < a[i]; rep++) x.push_back(l);
        y.push_back(l);
        for (int rep = 0; rep < a[i]-1; rep++) y.push_back(r);
    }

    if (x == y) {
        cout << "perfect\n";
        return;
    }

    cout << "ambiguous\n";
    for (auto c : x) cout << c+1 << ' '; cout << '\n';
    for (auto c : y) cout << c+1 << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}