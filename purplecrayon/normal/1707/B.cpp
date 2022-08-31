#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

// https://www.codechef.com/viewsolution/68474961

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    int cnt = 0;
    while (sz(a) > 1) {
        sort(a.begin(), a.end());

        bool start = !cnt;
        int cur_cnt = unique(a.begin(), a.end()) - a.begin();
        cnt += sz(a) - cur_cnt;
        a.resize(cur_cnt);


        vector<ll> b{a[0]};
        for (int i = 1; i < sz(a); i++) b.push_back(a[i] - a[i-1]);

        if (start) b.erase(b.begin());
        else cnt--;

        a = b;
    }
    cout << (sz(a) ? a[0] : 0) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}