#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> pr(n);
        for (int i = 0; i < n; i++) {
            pr[i] = s[i] == '1';
            if (i > 0) pr[i] += pr[i - 1];
        }
        if (pr.back() * m % n != 0) {
            cout << -1 << endl;
            continue;
        }
        int x = pr.back() * m / n;
        bool good = 0;
        for (int i = 0; i + m <= n; i++) {
            int res = pr[i + m - 1] - (i > 0 ? pr[i - 1] : 0);
            if (res == x) {
                cout << 1 << endl;
                cout << i + 1 << ' ' << i + m << endl;
                good = 1;
                break;
            }
        }
        if (good) continue;
        for (int i = 0; i < m - 1; i++) {
            int sum = pr[i] + pr.back() - pr[n - (m - i)];
            if (sum == x) {
                cout << 2 << endl;
                cout << 1 << ' ' << i + 1 << endl;
                cout << n - (m - i) + 2 << ' ' << n << endl;
                break;
            }
        }
    }
    return 0;
}