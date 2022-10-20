#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 2000010;
const int LOG = 22;

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


struct NTT {
    int base = 1;
    int maxBase = 0;
    int root = 2;
    vector<int> w = {0, 1};
    vector<int> rev = {0, 1};
    NTT () {
        int u = MOD - 1;
        while (u % 2 == 0) {
            u >>= 1;
            maxBase++;
        }
        while (power(root, 1 << maxBase) != 1 || power(root, 1 << (maxBase - 1)) == 1) root++;
    }
    void ensure(int curBase) {
        assert(curBase <= maxBase);
        if (curBase <= base) return;
        rev.resize(1 << curBase);
        for (int i = 0; i < (1 << curBase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (curBase - 1));
        }
        w.resize(1 << curBase);
        for (; base < curBase; base++) {
            int wc = power(root, 1 << (maxBase - base - 1));
            for (int i = 1 << (base - 1); i < (1 << base); i++) {
                w[i << 1] = w[i];
                w[i << 1 | 1] = mul(w[i], wc);
            }
        }
    }
    void fft(vector<int> &a) {
        int n = a.size();
        int curBase = 0;
        while ((1 << curBase) < n) curBase++;
        int shift = base - curBase;
        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < k; i++) {
                for (int j = i; j < n; j += k * 2) {
                    int foo = a[j];
                    int bar = mul(a[j + k], w[i + k]);
                    a[j] = add(foo, bar);
                    a[j + k] = sub(foo, bar);
                }
            }
        }
    }
    vector<int> mult(vector<int> a, vector<int> b) {
        if (a.empty() || b.empty()) return vector<int>();
        int nResult = a.size() + b.size() - 1;
        int curBase = 0;
        while ((1 << curBase) < nResult) curBase++;
        ensure(curBase);
        int n = 1 << curBase;
        a.resize(n), b.resize(n);
        fft(a);
        fft(b);
        int invN = inv(n);
        for (int i = 0; i < n; i++) {
            a[i] = mul(mul(a[i], b[i]), invN);
        }
        reverse(a.begin() + 1, a.end());
        fft(a);
        a.resize(nResult);
        return a;
    }
} ntt;

vector<int> dp[100][2][2];
int delta[100][2][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;   
    }
    int sz = 1;
    while ((1 << sz) - 1 < n) sz++;
    sz--;
    dp[1][0][1] = {0, 1};
    dp[1][1][0] = {0, 0, 1};
    ntt.ensure(sz + 1);
    for (int it = 2; it <= sz; it++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                dp[it][i][j] = ntt.mult(dp[it - 1][i ^ 1][i], dp[it - 1][1][j ^ i ^ 1]);
                delta[it][i][j] = delta[it - 1][i ^ 1][i] + delta[it - 1][1][i ^ j ^ 1] + 1;
            }
        }
    }
    int res = 0;
    int id = n % 2;
    for (int i = 0; i < 2; i++) {
        int foo;
        if (n < delta[sz][i][id]) foo = 0;
        else {
            int now = n - delta[sz][i][id];
            foo = dp[sz][i][id].size() > now ? dp[sz][i][id][now] : 0;
        }
        res = add(res, foo);
    }
    cout << res << endl;
    return 0;
}