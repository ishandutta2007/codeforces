#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

int h[400];

void solve(){
    memset(h, -1, sizeof(h));
    int p, n; cin >> p >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int y = x%p;
        if (h[y] == -1){ h[y] = x; continue; }
        cout << i << '\n';
        return;
    }
    cout << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}