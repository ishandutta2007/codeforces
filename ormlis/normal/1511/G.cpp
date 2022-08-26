#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")

#define all(a) (a).begin(),(a).end()

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    for(auto &x : a) x--;
    sort(all(a));
    int q; cin >> q;
    while(q--) {
        int lo, hi; cin >> lo >> hi;
        lo--, hi--;
        int l = lower_bound(all(a), lo) - a.begin();
        int r = upper_bound(all(a), hi) - a.begin();
        int x = 0;
        for(int i = l; i < r; ++i) x ^= a[i] - lo;
        cout << "AB"[x==0];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}