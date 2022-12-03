#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    map<int, int> cntx, cnty;
    map<pair<int, int>, int> cnt;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cntx[x]++;
        cnty[y]++;
        cnt[make_pair(x, y)]++;
        ans += cntx[x] - 1;
        ans += cnty[y] - 1;
        ans -= cnt[make_pair(x, y)] - 1;
    }
    cout << ans;
    return 0;
}