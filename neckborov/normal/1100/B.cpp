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
    int n, m;
    cin >> n >> m;
    multiset<int> kek;
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        kek.insert(0);
    }
    int ans = 0;
    while (m--) {
        int a;
        cin >> a;
        --a;
        kek.erase(kek.find(cnt[a]));
        ++cnt[a];
        kek.insert(cnt[a]);
        if (*kek.begin() > ans) {
            ++ans;
            cout << 1;
        } else {
            cout << 0;
        }
    }
    return 0;
}