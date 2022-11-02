#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

const int MOD = 998244353;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k), ind(n + 1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ind[a[i]] = i;
    }
    for (int i = 0; i < k; i++){
        cin >> b[i];
    }
    int ans = 1;
    vector<bool> used(n + 1);
    for (int i = k - 1; i > -1; i--){
        int c = 2;
        if (ind[b[i]] == 0 || used[a[ind[b[i]] - 1]]){
            c--;
        }
        if (ind[b[i]] == n - 1 || used[a[ind[b[i]] + 1]]){
            c--;
        }
        ans *= c;
        ans %= MOD;
        used[b[i]] = 1;
    }
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}