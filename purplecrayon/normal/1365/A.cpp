#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5+10, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const int hA[4] = {1, 0, -1, 0}, kA[4] = {1, 0, -1, 0};
// const ll INF = 1e18+10;

void solve(){
    string p1 = "Ashish\n", p2 = "Vivek\n";
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m, 0));
    vector<int> c(m), r(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cin >> g[i][j], r[i] |= g[i][j], c[j] |= g[i][j];
    }
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; i++) a1 += 1-r[i];
    for (int j = 0; j < m; j++) a2 += 1-c[j];
    if (min(a1, a2)&1) cout << p1;
    else cout << p2;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}