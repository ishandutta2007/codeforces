#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, p[MAXN];
bool vis[MAXN];
vector<int> cyc;

ll c2(ll x) {
    return x*(x-1)/2;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i], --p[i];
    for (int i = 0; i < n; i++) if (!vis[i]) {
        int c = i, me = 0;
        while (!vis[c]) {
            vis[c] = 1;
            me++;
            c = p[c];
        }
        cyc.push_back(me);
    }
    sort(cyc.begin(), cyc.end());
    if (sz(cyc) > 1) {
        int a = cyc.back(); cyc.pop_back();
        int b = cyc.back(); cyc.pop_back();
        cyc.push_back(a+b);
    }
    ll ans = 0;
    for (auto x : cyc) ans += (long long)x*x;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}