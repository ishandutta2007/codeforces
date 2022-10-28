#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 110, ALP = 26, MAXL = 20, INF = 1e9+10;

int n, m;
ll dp[MAXN][MAXN];
pair<int, int> a[MAXN][MAXN];

ll dfs(int l, int r){
    if (dp[l][r] != -1) return dp[l][r];
    if (l > r) return 0;
    // cout << "HERE " << l << " " << r << endl;
    ll ans = 0;
    for (int k = l; k <= r; k++){
        ll nxt = dfs(l, k-1)+dfs(k+1, r), cost = 0;
        for (int j = 0; j < n; j++){
            cost += (a[j][k].first >= l && a[j][k].second <= r);
        }
        ans = max(ans, nxt+cost*cost);
    }
    return dp[l][r] = ans;
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int mi; cin >> mi;
        for (int j = 0; j < mi; j++){
            int l, r; cin >> l >> r; l--, r--;
            for (int nxt = l; nxt <= r; nxt++) a[i][nxt] = {l, r};
        }
    }
    // for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cout << i << " " << j << " " << a[i][j].first << " " << a[i][j].second << endl;
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) dp[i][j] = -1;
    cout << dfs(0, m-1) << "\n";
}
int main(){
    int t=1;// cin >> t;
    while (t--) solve();
}