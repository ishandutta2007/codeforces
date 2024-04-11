#include "bits/stdc++.h"
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;

int n, m, a[MAXN][MAXN], b[2*MAXN];

void solve(){
    cin >> n >> m;
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j], b[i+j] ^= a[i][j];
    if (*max_element(b, b+n+m) == 0) cout << "Jeel\n";
    else cout << "Ashish\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}