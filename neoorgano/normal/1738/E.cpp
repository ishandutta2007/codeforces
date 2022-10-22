#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 998244353;

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n % 2 == 0) {
            a = (a * a) % MOD;
            n /= 2;
        } else {
            res = (res * a) % MOD;
            n--;
        }
    }
    return res;
}

const int MAXN = 1e5 + 100;
int f[MAXN], invf[MAXN];

main() {
    f[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        f[i] = (f[i - 1] * i) % MOD;
    }
    invf[MAXN - 1] = binpow(f[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i > 0; --i) {
        invf[i - 1] = (invf[i] * i) % MOD;
    }
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> seg, arr;
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a == 0) {
                cnt++;
            } else {
                seg.push_back(cnt);
                arr.push_back(a);
                cnt = 1;
            }
        }
        seg.push_back(cnt);
        n = arr.size();
        if (n == 0) {
            cout << binpow(2, seg[0] - 2) << endl;
            continue;
        }
        vector<int> pref(n + 1, 0);
        seg[0]--;
        seg[(int)seg.size() - 1]--;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + arr[i];
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n + 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (pref[i] > pref[n] - pref[m]) {
                    r = m;
                } else {
                    l = m;
                }
            }
            if (pref[i] == pref[n] - pref[l]) {
                if (l < i) break;
                if (i == l) {
                    ans = (ans * binpow(2, seg[i])) % MOD;
                } else {
                    int a = seg[i], b = seg[l];
                    /// cout << a << " " << b << endl;
                    int c = (f[a + b] * invf[a]) % MOD;
                    c = (c * invf[b]) % MOD;
                    ans = (ans * c) % MOD;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}