#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
const int MOD = 1000000007;
const int LOG = 60;

inline int add(int u, int v, int mod = MOD) {return (u += v) >= mod ? u - mod : u;}
inline int sub(int u, int v, int mod = MOD) {return (u -= v) < 0 ? u + mod : u;}
inline int mul(int u, int v, int mod = MOD) {return (long long)u * v % mod;}
inline int power(int u, int v, int mod = MOD) {int res = 1;for (; v; v >>= 1, u = mul(u, u, mod)) if (v & 1) res = mul(res, u, mod); return res;}
inline int inv(int u, int mod = MOD) {return power(u, mod - 2, mod);}
inline void addTo(int &u, int v, int mod = MOD) {u = add(u, v, mod);}
inline void subTo(int &u, int v, int mod = MOD) {u = sub(u, v, mod);}
inline void mulTo(int &u, int v, int mod = MOD) {u = mul(u, v, mod);}

int n;
long long a[N];
int cnt[LOG];
int p[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = mul(p[i - 1], 2);
    }
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int j = 0; j < LOG; j++) {
                if (a[i] >> j & 1) {
                    cnt[j]++;
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j < LOG; j++) {
                if (a[i] >> j & 1) {
                    addTo(sum, mul(p[j], cnt[j]));
                }
            }

            int now = 0;
            for (int j = 0; j < LOG; j++) {
                if (a[i] >> j & 1) {
                    addTo(now, mul(p[j], n));
                } else {
                    addTo(now, mul(p[j], cnt[j]));
                }
            }
            

            addTo(res, mul(sum, now));
        }

        cout << res << '\n';

        // reset
        for (int i = 0; i < LOG; i++) {
            cnt[i] = 0;
        }
    }
    return 0;
}