#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c, --c;
    if (sz(set<int>(a.begin(), a.end())) != n) {
        cout << "YES\n";
        return;
    }

    auto b = a; sort(b.begin(), b.end());
    
    vector<set<int>> loc(n);
    for (int i = 0; i < n; i++) if (b[i] != a[i]) loc[a[i]].insert(i);

    auto er = [&](int x) {
        if (b[x] != a[x]) loc[a[x]].erase(x);
    };
    auto add = [&](int x) {
        if (b[x] != a[x]) loc[a[x]].insert(x);
    };

    auto op = [&](int x, int y, int z) {
        // swap(x, z)
        // swap(y, z)
        er(x), er(y), er(z);
        swap(a[x], a[z]);
        swap(a[y], a[z]);
        add(x), add(y), add(z);
    };

    for (int i = 0; i < n; i++) if (a[i] != b[i]) {
        if (i >= n-2) {
            cout << "NO\n";
            return;
        }
        int need = *loc[b[i]].rbegin();
        int me = i+1;
        if (me == need) me++;
        while (b[i] != a[i]) op(i, me, need);
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}