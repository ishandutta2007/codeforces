//#pragma GCC optimize("O3")
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
    int n, m;
    cin >> n >> m;
    vector<int> cnt(101);
    int total = 0;
    for (int i = 0; i < n; i++) {
        int a;
        int ans = 0;
        cin >> a;
        total += a;
        int s = total;
        for (int j = 100; j > 0; j--) {
            if (s <= m) {
                break;
            }
            int kek = min(cnt[j], (s - m + j - 1) / j);
            s -= kek * j;
            ans += kek;
        }
        cout << ans << ' ';
        cnt[a]++;
    }
    return 0;
}