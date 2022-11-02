#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int MOD = 998244353;

int mul(int a, int b) {
    return (1ll * a * b % MOD);
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s, res = 1;
        cin >> n >> s;
        vector<int> a(n), b(n), used(n), add(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
            if (b[i] != -2) {
                if (a[i] > b[i] + s) {
                    res = 0;
                }
                used[b[i]] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == -2) {
                add[max(0, a[i] - s)]++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += add[i];
            if (used[i]) continue;
            res = mul(res, cnt--);
        }
        cout << res << endl;
    }
    return 0;
}