#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int MOD = 998244353;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n, m;
pair<int, int> a[N];
pair<int, int> b[22];
int num[N];
int cnt[44][N];
int fac[N];
int invFac[N];

int getC(int n, int k) {
    if (k < 0 || n < 0) return 0;
    if (k > n) return 0;
    return mul(fac[n], mul(invFac[k], invFac[n - k]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
    invFac[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) invFac[i] = mul(invFac[i + 1], i + 1);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    
    multiset<pair<int, int>> s1;
    multiset<int> s2;
    for (int i = 1; i <= n; i++) {
        s1.insert(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        while (!s1.empty() && s1.begin()->first <= i) {
            s2.insert(s1.begin()->second);
            s1.erase(s1.begin());
        }
        while (!s2.empty() && *s2.begin() < i) s2.erase(s2.begin());
        num[i] = s2.size();
    }
    

    cnt[0][0] = 1;
    for (int mask = 1; mask < (1 << m); mask++) {
        int l = 0, r = n + 1;
        set<int> ss;
        for (int i = 0; i < m; i++) {
            if (mask >> i & 1) {
                ss.insert(b[i].first);
                ss.insert(b[i].second);
                l = max(l, a[b[i].first].first);
                r = min(r, a[b[i].first].second);
                l = max(l, a[b[i].second].first);
                r = min(r, a[b[i].second].second);
            }
        }
        if (l > r) continue;
        int numBit = __builtin_popcount(mask);
        int sign = numBit % 2 ? -1 : 1;
        cnt[ss.size()][l] += sign;
        cnt[ss.size()][r + 1] -= sign;
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m * 2; j++) {
            cnt[j][i] += cnt[j][i - 1];
            int now = mul(getC(num[i] - j, i - j), abs(cnt[j][i]));
            if (cnt[j][i] > 0) res = add(res, now);
            else if (cnt[j][i] < 0) res = sub(res, now);
        }
    }
    cout << res << endl;
    return 0;   
}