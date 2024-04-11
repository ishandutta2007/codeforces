#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;


void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& c : a) cin >> c, --c;

    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cnt[(i-a[i]+n)%n]++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) if (cnt[i] >= (n+2)/3) {
        vector<int> b; b.reserve(n);
        for (int j = i; j < n; j++) b.push_back(a[j]);
        for (int j = 0; j < i; j++) b.push_back(a[j]);

        int cur = 0;
        vector<bool> vis(n);
        for (int j = 0; j < n; j++) if (!vis[j]) {
            cur++;
            int c = j;
            while (!vis[c]) {
                vis[c] = 1;
                c = b[c];
            }
        }

        if (n-m <= cur) ans.push_back(i);
    }
    cout << sz(ans) << ' ';
    for (auto c : ans) cout << c << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}

//cyclicly shift perm to the left, need to count cycles