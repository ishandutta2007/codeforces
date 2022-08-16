#include <bits/stdc++.h>
using namespace std;

string g[101];

void solve(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];
    int ans = 0;
    for (int i = 0; i < n-1; i++) ans += g[i][m-1] == 'R';
    for (int j = 0; j < m-1; j++) ans += g[n-1][j] == 'D';
    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}