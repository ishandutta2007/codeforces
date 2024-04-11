#include <bits/stdc++.h>

using namespace std;

// make sure that BASE > maxValue
const int BASE = 10007;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int NUM = 3;
const int MOD[NUM] = {1000000007, 1000000009, 998224353};

inline int add(int u, int v, int MOD) {return (u += v) >= MOD ? u - MOD : u;}
inline int sub(int u, int v, int MOD) {return (u -= v) < 0 ? u + MOD : u;}
inline int mul(int u, int v, int MOD) {return (long long)u * v % MOD;}
inline int power(int u, int v, int MOD) {int res = 1;for (; v; v >>= 1, u = mul(u, u, MOD)) if (v & 1) res = mul(res, u, MOD); return res;}
inline int inv(int u, int MOD) {return power(u, MOD - 2, MOD);}
inline void addTo(int &u, int v, int MOD) {u = add(u, v, MOD);}
inline void subTo(int &u, int v, int MOD) {u = sub(u, v, MOD);}
inline void mulTo(int &u, int v, int MOD) {u = mul(u, v, MOD);}

struct Hash {
    int a[NUM];
    Hash(int u = 0) {
        for (int i = 0; i < NUM; i++) {
            a[i] = u % MOD[i];
        }
    }
    Hash operator + (const Hash &u) const {
        Hash res(0);
        for (int i = 0; i < NUM; i++) {
            res.a[i] = add(a[i], u.a[i], MOD[i]);
        }
        return res;
    }
    Hash operator - (const Hash &u) const {
        Hash res(0);
        for (int i = 0; i < NUM; i++) {
            res.a[i] = sub(a[i], u.a[i], MOD[i]);
        }
        return res;
    }
    Hash operator * (const int u) const {
        Hash res(0);
        for (int i = 0; i < NUM; i++) {
            res.a[i] = mul(a[i], u, MOD[i]);
        }
        return res;
    }
    Hash operator * (const Hash &u) const {
        Hash res(0);
        for (int i = 0; i < NUM; i++) {
            res.a[i] = mul(a[i], u.a[i], MOD[i]);
        }
        return res;
    }
    bool operator == (const Hash &u) const {
        for (int i = 0; i < NUM; i++) {
            if (a[i] != u.a[i]) return 0;
        }
        return 1;
    }
    Hash inv() {
        Hash res(0);
        for (int i = 0; i < NUM; i++) {
            res.a[i] = ::inv(a[i], MOD[i]);
        }
        return res;
    }
    void debug() {
        // cout << "{";
        // for (int i = 0; i < NUM; i++) cout << a[i] << ' ';
        //     cout << "}";
        //     cout << endl;
    }
};

const int N = 100010;
const int M = 2500010;
const int C = 26;

int n, q;
char s[M], t[N];
int k[N];
string w[N];

int order[N];
int res[N];

int sumP2[C][N];
int p2[N];
Hash h[M];
Hash now[M];
Hash pBASE[M];

Hash getHash(Hash *a, int l, int r) {
    if (l > r) return Hash(0);
    return a[r] - (a[l - 1] * pBASE[r - l + 1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    cin >> (s + 1);
    cin >> (t + 1);
    int sz = strlen(s + 1);

    int INV2 = inv(2, MOD[0]);
    int curVal = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < C; j++) {
            sumP2[j][i] = sumP2[j][i - 1];
        }

        curVal = mul(curVal, INV2, MOD[0]);
        sumP2[t[i] - 'a'][i] = add(sumP2[t[i] - 'a'][i], curVal, MOD[0]);
    }
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = mul(p2[i - 1], 2, MOD[0]);
    }
    h[0] = Hash(0);
    for (int i = 1; i <= sz; i++) {
        h[i] = (h[i - 1] * BASE) + (s[i] - 'a' + 1);
        // cout << "upd " << i << endl;
        // h[i].debug();
    }
    pBASE[0] = Hash(1);
    for (int i = 1; i < M; i++) {
        pBASE[i] = pBASE[i - 1] * BASE;
    }

    for (int i = 1; i <= q; i++) {
        cin >> k[i] >> w[i];
    }
    iota(order + 1, order + q + 1, 1);
    sort(order + 1, order + q + 1, [&](int u, int v) {
        return w[u].size() < w[v].size();
    });

    int curID = 0;
    for (int i = 1; i <= q; i++) {
        int u = order[i];
        while (curID <= n && sz < w[u].size()) {
            curID++;
            s[sz + 1] = t[curID];
            for (int j = 1; j <= sz; j++) {
                s[sz + 1 + j] = s[j];
            }

            // for (int j = 1; j <= sz + 1; j++) {
            //     h[sz + j] = (h[sz + j - 1] * BASE) * (s[sz + j] - 'a' + 1);
            //     cout << "upd " << sz + j << endl;
            //     h[sz + j].debug();
            // }

            sz = sz << 1 | 1;

            for (int j = 1; j <= sz; j++) {
                h[j] = (h[j - 1] * BASE) + (s[j] - 'a' + 1);
            }
        }

        if (sz < w[u].size() || curID > k[u]) {
            res[u] = 0;
            continue;
        }

        int szOfW = w[u].size();
        now[0] = 0;
        for (int j = 0; j < szOfW; j++) {
            now[j + 1] = (now[j] * BASE) + (w[u][j] - 'a' + 1);
        }
        int num = 0;
        // cout << "# " << u << ' ' << curID << endl;
        getHash(h, 5, 5).debug();
        for (int j = szOfW; j <= sz; j++) {
            Hash foo = getHash(h, j - szOfW + 1, j);
            // foo.debug();
            num += (foo == now[szOfW]);
        }

        addTo(res[u], mul(num, p2[k[u] - curID], MOD[0]), MOD[0]);
        // cout << w[u] << ' ' << (s + 1) << endl;
        // cout << num << endl;

        vector<int> tot(C, 0);

        for (int j = 0; j < szOfW; j++) {
            // cout << "## " << j << endl;
            // getHash(now, 1, j).debug();
            // getHash(h, sz - j + 1, sz).debug();
            // getHash(now, j + 2, szOfW).debug();
            // getHash(h, 0, szOfW - j - 1).debug();
            if (getHash(now, 1, j) == getHash(h, sz - j + 1, sz) && getHash(now, j + 2, szOfW) == getHash(h, 0, szOfW - j - 1)) {
                tot[w[u][j] - 'a']++;
            }
        }

        // for (int u : tot) cout << u << ' ' ;
        //     cout << endl;

        for (int j = 0; j < C; j++) {
            int foo = sub(sumP2[j][k[u]], sumP2[j][curID], MOD[0]);
            mulTo(foo, p2[k[u]], MOD[0]);
            addTo(res[u], mul(tot[j], foo, MOD[0]), MOD[0]);
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}