#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e2+10, MOD = 1e9+7;

int n, m, k;
string g[MAXN];
int ps[MAXN][MAXN], a[MAXN];

void solve(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int ni = i-1; ni <= i+1; ni++) for (int nj = j-1; nj <= j+1; nj++) if (abs(i-ni)+abs(j-nj) <= 1) {
                if (0 <= ni && ni < n && 0 <= nj && nj < m) cnt += g[ni][nj]-'0';
            }
            ps[i][j] = (cnt == 5);
            if (j) ps[i][j] += ps[i][j-1];
        }
    }
    ll ans = 0;
    for (int l = 1; l < m-1; l++) for (int r = l; r < m-1; r++) {
        for (int i = 1; i < n-1; i++) a[i] = ps[i][r]-ps[i][l-1], a[i] += a[i-1];
        for (int i = 1, j = i; i < n-1; i++) {
            while (j < n-1 && a[j]-a[i-1] < k) j++;
            ans += n-j-1;
        } 
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}