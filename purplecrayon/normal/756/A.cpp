#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, p[MAXN];
bool b[MAXN], vis[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i], --p[i];
    for (int i = 0; i < n; i++) { int x; cin >> x; b[i] = x; }
    int ans = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        ans++;
        int c = i;
        while (!vis[c]) {
            vis[c] = 1;
            c = p[c];
        }
    }
    if (ans == 1) ans = 0;
    int c = 0;
    for (int i = 0; i < n; i++) c ^= b[i];
    ans += c^1;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}