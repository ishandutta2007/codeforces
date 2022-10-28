#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 4e3+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

int pre[MAXN], cur[MAXM], cost[MAXN][MAXN], ps[MAXN][MAXN];

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void dfs(int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l+r) >> 1;
    pair<int, int> best = {INF, -1};
    for (int k = optl; k <= min(mid, optr); k++) best = min(best, {(k?pre[k-1]:0)+cost[k][mid], k});
    cur[mid] = best.first;
    dfs(l, mid - 1, optl, best.second), dfs(mid + 1, r, best.second, optr);
}
void solve(){
    int n, K; cin >> n >> K;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            char c; cin >> c; c -= '0';
            ps[i][j] = (j?ps[i][j-1]:0)+c;
            cost[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++){
        cost[i][i] = 0; pre[i] = cur[i] = INF;
        for (int j = i+1; j < n; j++){
            cost[i][j] = cost[i][j-1]+ps[j][j]-(i?ps[j][i-1]:0);
        }
    }
    for (int k = 1; k <= K; k++){
        dfs(0, n-1, 0, n-1);
        for (int i = 0; i < n; i++) pre[i] = cur[i];
    }
    cout << pre[n-1];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
}