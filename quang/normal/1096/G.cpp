#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
    // return (u + v) % MOD;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
    // return (u - v + MOD) % MOD;
}

// inline int mul(int u, int v) {
//     return (long long)u * v % MOD;
// }

inline int mul(int a, int b) {
#if !defined(_WIN32) || defined(_WIN64)
  return (int) ((long long) a * b % MOD);
#endif
  unsigned long long x = (long long) a * b;
  unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
  asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (MOD)
  );
  return m;
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

int n, k;
int sz;

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
        while (1) {
            if (power(root, 1 << maxBase) == 1 && power(root, 1 << (maxBase - 1)) != 1) {
                break;
            }
            root++;
        }
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
                for (int j = 0; j < n; j += k * 2) {
            for (int i = 0; i < k; i++) {
                    int foo = a[i + j];
                    int bar = mul(a[i + j + k], w[i + k]);
                    a[i + j] = add(foo, bar);
                    a[i + j + k] = sub(foo, bar);
                }
            }
        }
    }
    vector<int> mult(vector<int> a, vector<int> b) {
        int nResult = a.size() + b.size() - 1;
        int curBase = 0;
        while ((1 << curBase) < nResult) curBase++;
        ensure(curBase);
        a.resize(1 << curBase), b.resize(1 << curBase);
        fft(a);
        fft(b);
        for (int i = 0; i < (1 << curBase); i++) {
            a[i] = mul(mul(a[i], b[i]), inv(1 << curBase));
        }
        reverse(a.begin() + 1, a.end());
        fft(a);
        a.resize(nResult);
        return a;
    }

     vector<int> sqr(vector<int> a) {
        int nResult = a.size() + a.size() - 1;
        int curBase = 0;
        while ((1 << curBase) < nResult) curBase++;
        ensure(curBase);
        a.resize(1 << curBase);
        fft(a);
        int invBase = inv(1 <<  curBase);
        for (int i = 0; i < (1 << curBase); i++) {
            a[i] = mul(mul(a[i], a[i]), invBase);
        }
        reverse(a.begin() + 1, a.end());
        fft(a);
        a.resize(nResult);
        while (!a.empty() && !a.back()) a.pop_back();
        return a;
    }

} ntt;


// struct ntt {
//   int base = 1;
//   vector<int> roots = {0, 1};
//   vector<int> rev = {0, 1};
//   int max_base = -1;
//   int root = -1;

//   void init() {
//     int tmp = MOD - 1;
//     max_base = 0;
//     while (tmp % 2 == 0) {
//       tmp /= 2;
//       max_base++;
//     }
//     root = 2;
//     while (true) {
//       if (power(root, 1 << max_base) == 1) {
//         if (power(root, 1 << (max_base - 1)) != 1) {
//           break;
//         }
//       }
//       root++;
//     }
//   }

//   void ensure_base(int nbase) {
//     if (max_base == -1) {
//       init();
//     }
//     if (nbase <= base) {
//       return;
//     }
//     assert(nbase <= max_base);
//     rev.resize(1 << nbase);
//     for (int i = 0; i < (1 << nbase); i++) {
//       rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
//     }
//     roots.resize(1 << nbase);
//     while (base < nbase) {
//       int z = power(root, 1 << (max_base - 1 - base));
//       for (int i = 1 << (base - 1); i < (1 << base); i++) {
//         roots[i << 1] = roots[i];
//         roots[(i << 1) + 1] = mul(roots[i], z);
//       }
//       base++;
//     }
//   }

//   void fft(vector<int> &a) {
//     int n = (int) a.size();
//     assert((n & (n - 1)) == 0);
//     int zeros = __builtin_ctz(n);
//     ensure_base(zeros);
//     int shift = base - zeros;
//     for (int i = 0; i < n; i++) {
//       if (i < (rev[i] >> shift)) {
//         swap(a[i], a[rev[i] >> shift]);
//       }
//     }
//     for (int k = 1; k < n; k <<= 1) {
//       for (int i = 0; i < n; i += 2 * k) {
//         for (int j = 0; j < k; j++) {
//           int x = a[i + j];
//           int y = mul(a[i + j + k], roots[j + k]);
//           // a[i + j] = x + y - MOD;
//           // if (a[i + j] < 0) a[i + j] += MOD;
//           // a[i + j + k] = x - y + MOD;
//           // if (a[i + j + k] >= MOD) a[i + j + k] -= MOD;
//         a[i + j] = add(x, y);
//         a[i + j + k] = sub(x, y);
//         }
//       }
//     }
//   }

//   vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
//     int need = (int) (a.size() + b.size() - 1);
//     int nbase = 0;
//     while ((1 << nbase) < need) nbase++;
//     ensure_base(nbase);
//     int sz = 1 << nbase;
//     a.resize(sz);
//     b.resize(sz);
//     fft(a);
//     if (eq) b = a; else fft(b);
//     int inv_sz = inv(sz);
//     for (int i = 0; i < sz; i++) {
//       a[i] = mul(mul(a[i], b[i]), inv_sz);
//     }
//     reverse(a.begin() + 1, a.end());
//     fft(a);
//     a.resize(need);
//     while (!a.empty() && a.back() == 0) {
//         a.pop_back();
//     }
//     return a;
//   }

//   vector<int> sqr(vector<int> a) {
//     return multiply(a, a, 1);
//   }
// } ntt;


// vector<int> go(vector<int> u, int v) {
//     vector<int> res(u.size(), 0);
//     res[0] = 1;
//     while (v) {
//         if (v & 1) res = ntt.mult(res, u);
//         u = ntt.sqr(u);
//         v >>= 1;
//     }
//     return res;
// }

vector<int> go(vector<int> &u, int v) {
    if (v == 0) return vector<int>(1, 1);
    if (v % 2 == 0) {
        vector<int> foo = go(u, v >> 1);
        return ntt.sqr(foo);
    }
    vector<int> res = go(u, v - 1);
    vector<int> now(res.size() + u.size() - 1, 0);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < u.size(); j++) {
            now[i + j] = add(now[i + j], mul(res[i], u[j]));
        }
    }
    return now;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    sz = 9 * n / 2 + 1;
    vector<int> a(10, 0);
    for (int i = 1; i <= k; i++) {
        int u;
        cin >> u;
        a[u] = 1;
    }
    vector<int> res = go(a, n / 2);
    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
        ans = add(ans, mul(res[i], res[i]));
    }
    cout << ans << endl;
    return 0;
}