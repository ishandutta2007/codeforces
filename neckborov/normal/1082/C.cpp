#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double old;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<vector<int>> a(m + 1);
    for (int i = 0; i < n; ++i) {
        int s, r;
        cin >> s >> r;
        a[s - 1].push_back(r);
    }
    for (int i = 0; i < m; ++i) {
        sort(a[i].begin(), a[i].end(), greater<int>());
    }
    vector<int> seg(n);
    for (int i = 0; i < m; ++i) {
        int kek = 0;
        for (int j = 0; j < a[i].size(); ++j) {
            kek += a[i][j];
            if (kek > 0) {
                seg[j] += kek;
            }
        }
    }
    cout << *max_element(seg.begin(), seg.end());
    return 0;
}