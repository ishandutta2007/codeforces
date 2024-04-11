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

int n, m, sx, sy;

int visitRow(int row, int sc){
    cout << row+1 << " " << sc+1 << "\n";
    int prev=-1;
    for (int i = 0; i < m; i++) if (i != sc) cout << row+1 << " " << i+1 << "\n", prev = i;
    return prev;
}
void solve(){
    cin >> n >> m >> sx >> sy; sx--, sy--;
    int prev = visitRow(sx, sy);
    for (int i = 0; i < n; i++) if (i != sx) prev = visitRow(i, prev);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;// cin >> t;
    while (t--) solve();
}