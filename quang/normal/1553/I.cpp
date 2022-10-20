#include <bits/stdc++.h>

using namespace std;

// source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true; string res = "{";
  for (const auto &x : v)
    {if (!first) res += ", "; first = false; res += to_string(x);}
  res += "}"; return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int MOD = 998244353;
inline int add(int u, int v, int mod = MOD) {
  return (u += v) >= mod ? u - mod : u;
}
inline int sub(int u, int v, int mod = MOD) {
  return (u -= v) < 0 ? u + mod : u;
}
inline int mul(int u, int v, int mod = MOD) { return (long long)u * v % mod; }
inline int power(int u, int v, int mod = MOD) {
  int res = 1;
  for (; v; v >>= 1, u = mul(u, u, mod))
    if (v & 1) res = mul(res, u, mod);
  return res;
}
inline int neg(int u, int mod = MOD) { return sub(0, u); }
inline int inv(int u, int mod = MOD) { return power(u, mod - 2, mod); }
inline int add_to(int &u, int v, int mod = MOD) { return u = add(u, v, mod); }
inline int sub_to(int &u, int v, int mod = MOD) { return u = sub(u, v, mod); }
inline int mul_to(int &u, int v, int mod = MOD) { return u = mul(u, v, mod); }

const int INV2 = inv(2);

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

struct Data {
  vector<int> a[2][2];

  Data(int sz) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        a[i][j].resize(sz, 0);
      }
    }
  }

  Data operator*(const Data &rhs) const {
    Data res(a[0][0].size() + rhs.a[0][0].size() - 1);
    for (int l = 0; l < 2; l++) {
      for (int r = 0; r < 2; r++) {
        for (int m1 = 0; m1 < 2; m1++) {
          for (int m2 = 0; m2 < 2; m2++) {
            auto foo = ntt.mult(a[l][m1], rhs.a[m2][r]);
            for (int i = 0; i < foo.size(); i++) {
              add_to(res.a[l][r][i], foo[i]);
              if (i > 0) {
                auto val = foo[i];
                if (m1 && m2) mul_to(val, INV2);
                if (!m1 && !m2) mul_to(val, 2);
                int l_f = a[0][0].size() == 2;
                int r_f = rhs.a[0][0].size() == 2;
                add_to(res.a[l | l_f][r | r_f][i - 1], val);
              }
            }
          }
        }
      }
    }
    return res;
  }
};
 
string to_string(const Data &v) {
  string res = "{\n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      res += "  {" + to_string(i) + ", " + to_string(j) + ", "
           + to_string(v.a[i][j]) + "}\n";
    }
  }
  res += "}";
  return res;
}

const int N = 100010;

int n;
int a[N];
int cnt;
int b[N];
int fac[N];

Data Solve(int l, int r) {
  if (l == r) {
    Data res(2);
    res.a[b[l]][b[l]][1] = (1 << b[l]); 
    debug(l, r, res);
    return res;
  }
  int m = l + r >> 1;
  auto res = Solve(l, m) * Solve(m + 1, r);
  debug(l, r, res);
  return res;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  int cur = 1;
  while (cur <= n) {
    int nxt = cur + a[cur] - 1;
    if (nxt > n) {
      cout << 0 << '\n';
      return 0;
    }
    for (int i = cur; i <= nxt; i++) {
      if (a[i] != a[cur]) {
        cout << 0 << '\n';
        return 0;
      }
    }
    b[++cnt] = a[cur] > 1;
    cur = nxt + 1;
  }

  auto foo = Solve(1, cnt);
  int res = 0;
  for (int i = 1; i < foo.a[0][0].size(); i++) {
    int now = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        add_to(now, foo.a[j][k][i]);
      }
    }
    mul_to(now, fac[i]);
    debug(i, now);
    if ((cnt - i) % 2) sub_to(res, now);
    else add_to(res, now);
  }
  cout << res << '\n';
  return 0;
}