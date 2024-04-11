#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e1+10, MOD = 1e9+7;
const ll INF = 1e18+10;

const ll MX = 1e4;
int n, m;
bitset<MX> a[MAXN];

void solve(){
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        while (k--){ int x; cin >> x, --x; a[i][x] = 1; }
    }
    for (int i = 0; i < m; i++) {
        bitset<MX> x = a[i];
        for (int i = 0; i < n; i++) x[i] = !x[i];

        for (int j = 0; j < m; j++) if ((a[j]|x) == x) {
            cout << "impossible\n";
            return;
        }
    }
    cout << "possible\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}