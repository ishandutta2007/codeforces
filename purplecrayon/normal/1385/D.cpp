#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

int n, l, a[MAXN];

int dfs(int c, int idx, int sz){
    if (sz == 0) return a[idx] != c;
    int rsz = (1<<sz), r = idx+rsz-1, mid = ((idx+r)>>1)+1;
    int ans = INF, lamt = 0, ramt = 0;
    for (int i = idx; i < mid; i++) lamt += (a[i] != c);
    for (int i = mid; i <= r; i++) ramt += (a[i] != c);
    ans = min(ans, min(dfs(c+1, mid, sz-1)+lamt, dfs(c+1, idx, sz-1)+ramt));
    return ans;
}
void solve(){
    cin >> n; l = floor(log2(n));
    string s; cin >> s;
    // for (int i = 0; i < n; i++) for (int j = 0; j < ALP; j++) for(int k = 0; k <= l; k++) dp[j][i][k] = -1;
    for (int i = 0; i < n; i++){
        a[i] = s[i]-'a';
    }
    cout << dfs(0, 0, l) << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}