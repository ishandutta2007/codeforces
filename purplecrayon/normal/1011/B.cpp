#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> cnt(101);
    vector<int> a(m); for (auto& it : a) cin >> it, cnt[it]++;

    auto v = [&](int x) -> bool {
        int v = 0;
        for (int i = 0; i < sz(cnt); i++) {
            v += cnt[i]/x;
        }
        return v >= n;
    };

    int lo=0, hi=1e9, mid=(lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (v(mid)) lo = mid;
        else hi = mid;
        mid = (lo+hi)/2;
    }
    cout << lo << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}