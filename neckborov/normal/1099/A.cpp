//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int w, h;
    int u1, d1;
    int u2, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    if (d1 < d2) {
        swap(u1, u2);
        swap(d1, d2);
    }
    int kek = w + (h + d1) * (h - d1 + 1) / 2 - u1;
    kek = max(kek, 0);
    kek = kek + (d1 + d2 - 1) * (d1 - d2) / 2 - u2;
    kek = max(kek, 0);
    kek += (d2 - 1) * d2 / 2;
    cout << kek;
    return 0;
}