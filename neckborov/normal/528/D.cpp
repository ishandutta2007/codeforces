#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<char, int> kek;
    kek['A'] = 0;
    kek['T'] = 1;
    kek['G'] = 2;
    kek['C'] = 3;
    string s, t;
    cin >> s >> t;
    bitset<800000> a, b, c;
    bitset<200000> ax, d, e;
    vector<int> cnt(4);
    for (int i = 0; i < min(k, n); i++) {
        cnt[kek[s[i]]]++;
    }
    for (int i = 0; i < n; i++) {
        if (i + k < n) {
            cnt[kek[s[i + k]]]++;
        }
        if (i - k - 1 >= 0) {
            cnt[kek[s[i - k - 1]]]--;
        }
        for (int j = 0; j < 4; j++) {
            a[i * 4 + j] = cnt[j];
            if (i < 50000) {
                ax[i * 4 + j] = cnt[j];
            }
        }
    }
    int ans = 0;
    if (m > 50000) {
        for (int i = 0; i < m; i++) {
            b[i * 4 + kek[t[i]]] = 1;
        }
        for (int i = 0; i < n - m + 1; i++) {
            c = b;
            c &= a;
            if (c.count() == m) {
                ans++;
            }
            a >>= 4;
        }
    } else {
        for (int i = 0; i < m; i++) {
            d[i * 4 + kek[t[i]]] = 1;
        }
        for (int i = 0; i < n - m + 1; i++) {
            e = d;
            e &= ax;
            if (e.count() == m) {
                ans++;
            }
            ax >>= 4;
            if (i < n - m) {
                ax[199996] = a[199996 + i * 4];
                ax[199997] = a[199997 + i * 4];
                ax[199998] = a[199998 + i * 4];
                ax[199999] = a[199999 + i * 4];
            }
        }
    }
    cout << ans;
    return 0;
}