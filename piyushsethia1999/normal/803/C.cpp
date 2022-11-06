#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int k; cin >> k;
    int n; cin >> n;
    std::vector<int> fac;
    for (int i = 1; i * i <= k; ++i) {
        if (k % i == 0) {
            fac.pb(i);
            if (i * i != k) {
                fac.pb(k / i);
            }
        } 
    }
    int nnp = (n * (n + 1) / 2);
    if (n > (1000000000))
        nnp = 1000000000000000000ll;
    // sort(fac.rbegin(), fac.rend());
    int ans = -1;
    for (int f : fac) {
        int nn = k / f;
        if (nn >= nnp)
            ans = max(ans, f);
    }
    if (ans == -1) {
        cout << ans;
    } else {
        int nn = k / ans;
        for (int i = 0; i < n - 1; ++i)
            cout << (i + 1) * (ans) << " ";
        cout << (n + (nn - ((n * (n + 1)) / 2))) * (ans);
    }
}