#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;


void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    map<int, int> cnt;

    int ans = n;
    for (int i = -1; i < n; i++) {
        bool bad=0;
        cnt.clear();
        for (int j = 0; j <= i; j++) {
            if (cnt[a[j]]){ bad=1; break; }
            cnt[a[j]]++;
        }
        if (bad) continue;

        int j = n-1;
        for (; j > i; j--) {
            if (cnt[a[j]]) break;
            cnt[a[j]]++;
        }

        int l = i+1, r = j;
        ans = min(ans, r-l+1);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}