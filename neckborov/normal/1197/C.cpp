#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    multiset<int> kek;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            kek.insert(a[i - 1] - a[i]);
        }
    }
    ans = a[n - 1] - a[0];
    for (int i = 1; i < k; i++) {
        ans += *kek.begin();
        kek.erase(kek.begin());
    }
    cout << ans;
    return 0;
}