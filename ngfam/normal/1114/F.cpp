#include <bits/stdc++.h>

using namespace std;

const int N = 400005;

const long long mod = 1e9 + 7;

long long fpow(long long x, long long y) {
  long long ret = 1;
  while(y) {
    if(y & 1) ret = ret * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return ret;
}

int sieve[N];
vector < int > pr;
vector < int > inv;
long long factors[N];

int n, q;
long long T[2][N << 2];
long long lazy[2][N << 3];

#define mid ((l + r) >> 1)

void build(int x, int l, int r) {
  T[0][x] = lazy[0][x] = 1;
  if(l == r) return;
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);
}

void push(int x, int l, int r) {
  if(lazy[0][x] == 1) return;
  T[0][x] = T[0][x] * fpow(lazy[0][x], r - l + 1) % mod;
  T[1][x] |= lazy[1][x];
  lazy[0][x + x] = lazy[0][x + x] * lazy[0][x] % mod;
  lazy[0][x + x + 1] = lazy[0][x + x + 1] * lazy[0][x] % mod;
  lazy[1][x + x] |= lazy[1][x];
  lazy[1][x + x + 1] |= lazy[1][x];
  lazy[0][x] = 1;
  lazy[1][x] = 0;
}

void recalc(int x) {
  T[0][x] = T[0][x + x] * T[0][x + x + 1] % mod;
  T[1][x] = T[1][x + x] | T[1][x + x + 1];
}

void multiply(int x, int l, int r, int u, int v, int val) {
  push(x, l, r);
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    lazy[0][x] = val;
    lazy[1][x] = factors[val];
    push(x, l, r);
  //  cout << val << endl;
    return;
  }
  multiply(x + x, l, mid, u, v, val);
  multiply(x + x + 1, mid + 1, r, u, v, val);
  recalc(x);
}

long long ans[2];

void query(int x, int l, int r, int u, int v) {
  push(x, l, r);
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    ans[0] = ans[0] * T[0][x] % mod;
    ans[1] = ans[1] | T[1][x];
    return;
  }
  query(x + x, l, mid, u, v);
  query(x + x + 1, mid + 1, r, u, v);
  recalc(x);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  for(int i = 2; i < 300; ++i) if(!sieve[i]) {
    for(int j = i; j <= 300; j += i) factors[j] |= (1LL << pr.size()), sieve[j] = 1;
    pr.push_back(i);
    inv.push_back(1LL * (i - 1) * fpow(i, mod - 2) % mod);
  }

  cin >> n >> q;
  build(1, 1, n);

  for(int i = 1; i <= n; ++i) {
    int x; cin >> x;
    multiply(1, 1, n, i, i, x);
  }

  while(q--) {
    string s; cin >> s;
    if(s[0] == 'T') {
      ans[0] = 1; ans[1] = 0;

      int l, r; cin >> l >> r;
      query(1, 1, n, l, r);
      for(int i = 0; i < pr.size(); ++i) if(ans[1] & (1LL << i)) ans[0] = ans[0] * inv[i] % mod;
      cout << ans[0] << "\n";
    }
    else{
      int l, r, x; cin >> l >> r >> x;
      multiply(1, 1, n, l, r, x);
    }
  }

  return 0;
}