//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

const old PI = acos(-1.0);

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    int ans = LONG_MAX, best = 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= 100; ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] != i) {
                s += min(abs(a[j] - i - 1), abs(a[j] - i + 1));
            }
        }
        if (s < ans) {
            ans = s;
            best = i;
        }
    }
    cout << best << ' ' << ans;
    return 0;
}