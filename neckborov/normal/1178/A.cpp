//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    vector<int> ans(1, 1);
    int kek = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        if (i && a[0] >= a[i] * 2) {
            kek += a[i];
            ans.push_back(i + 1);
        }
    }
    kek += a[0];
    if (kek > total - kek) {
        cout << ans.size() << '\n';
        for (int i : ans) {
            cout << i << ' ';
        }
    } else {
        cout << 0;
    }
    return 0;
}