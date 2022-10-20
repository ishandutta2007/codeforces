#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

inline int add(int u, int v, int mod = MOD) {return (u += v) >= mod ? u - mod : u;}
inline int sub(int u, int v, int mod = MOD) {return (u -= v) < 0 ? u + mod : u;}
inline int mul(int u, int v, int mod = MOD) {return (long long)u * v % mod;}
inline int power(int u, int v, int mod = MOD) {int res = 1;for (; v; v >>= 1, u = mul(u, u, mod)) if (v & 1) res = mul(res, u, mod); return res;}
inline int inv(int u, int mod = MOD) {return power(u, mod - 2, mod);}
inline void add_to(int &u, int v, int mod = MOD) {u = add(u, v, mod);}
inline void sub_to(int &u, int v, int mod = MOD) {u = sub(u, v, mod);}
inline void mul_to(int &u, int v, int mod = MOD) {u = mul(u, v, mod);}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> s(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    pos[s[i]] = i;
  }
  int num = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == n - 1) continue;
    if (s[i + 1] == n - 1 || pos[s[i] + 1] > pos[s[i + 1] + 1]) {
      num++;
    }
  }
  vector<int> fac(n + k + 1, 1);
  for (int i = 1; i <= n + k; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  if (k - 1 - num < 0) cout << 0 << '\n';
  else cout << mul(fac[n + k - 1 - num], inv(mul(fac[n], fac[k - 1 - num]))) << '\n';
  return 0;
}