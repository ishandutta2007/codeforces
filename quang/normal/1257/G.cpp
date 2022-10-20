#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
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

struct NTT {
    int maxBase, root;
    NTT() {
        maxBase = __builtin_ctz(MOD - 1);
        root = 1;
        while (power(root, 1 << maxBase) != 1 || power(root, 1 << maxBase - 1) == 1) root++;
    }

    void fft(vector<int> &a, int lg) {
        for (int i = 0; i < a.size(); i++) {
            int u = 0;
            for (int j = 0; j < lg; j++) {
                if (i >> j & 1) u |= (1 << lg - j - 1);
            }
            if (i < u) swap(a[i], a[u]);
        }
        for (int k = 1; k < a.size(); k <<= 1) {
            int w = 1, wDelta = power(root, (1 << maxBase - 1) / k);
            for (int i = 0; i < k; i++, w = mul(w, wDelta)) {
                for (int j = i; j < a.size(); j += k * 2) {
                    int foo = a[j];
                    int bar = mul(a[j + k], w);
                    a[j] = add(foo, bar);
                    a[j + k] = sub(foo, bar);
                }
            }
        }
    }

    vector<int> mult(vector<int> a, vector<int> b) {
        int sz = a.size() + b.size() - 1;
        int lg = 0;
        while ((1 << lg) < sz) lg++;
        a.resize(1 << lg, 0);
        b.resize(1 << lg, 0);
        fft(a, lg);
        fft(b, lg);
        int invN = inv(1 << lg);
        for (int i = 0; i < a.size(); i++) {
            a[i] = mul(a[i], b[i]);
            a[i] = mul(a[i], invN);
        }
        reverse(a.begin() + 1, a.end());
        fft(a, lg);
        a.resize(sz);
        return a;
    }
} ntt;

int n;
map<int, int> cnt;
map<int, int> id;
int cntId = 0;
vector<int> ls[N];
set<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        cnt[u]++;
        if (!id.count(u)) id[u] = ++cntId;
    }
    for (auto u : cnt) {
        int now = id[u.first];
        ls[now] = vector<int>(u.second + 1, 1);
        s.insert({u.second + 1, now});
    }
    while (s.size() >= 2) {
        auto u = *s.begin();
        s.erase(s.begin());
        auto v = *s.begin();
        s.erase(s.begin());
        ls[u.second] = ntt.mult(ls[u.second], ls[v.second]);
        s.insert({ls[u.second].size(), u.second});
    }
    int root = s.begin()->second;
    cout << ls[root][(n + 1) / 2] << endl;
    return 0;
}