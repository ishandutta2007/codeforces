#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;


int fpow(int x, int y) {
  int ret = 1;
  while(y) {
    if(y & 1) ret = (long long)ret * x % mod;
    y >>= 1;
    x = (long long) x * x % mod;
  }
  return ret;
}

template < long long mod >
struct NumberTheoriticTransform{
private:
  static const int M = 19;
  static const int N = 1 << 19;

  int ivn, n;
  int a[N];
  int b[N];
  int revbit[N];
  int rts[N + 1];

  int prt(){
    vector < int > divisors;
    for(int i = 2; i * i < mod; ++i) {
      if((mod - 1) % i == 0) {
        divisors.push_back((mod - 1) / i);
        divisors.push_back(i);
      }
    }

    for(int w = 2; w < mod; ++w) {
      int flag = 1;
      for(auto &x : divisors) {
        if(fpow(w, x) == 1) {
          flag = 0;
          break;
        }
      }
      if(flag) return w;
    }
    return -1;
  }

public:
  int fpow(int x, int y) {
    int ret = 1;
    while(y) {
      if(y & 1) ret = (long long)ret * x % mod;
      y >>= 1;
      x = (long long) x * x % mod;
    }
    return ret;
  }

  NumberTheoriticTransform() {
    int pw = fpow(prt(), (mod - 1) / N);

    rts[0] = 1;
    for(int i = 1; i <= N; ++i) {
      rts[i] = (long long) rts[i - 1] * pw % mod;
    }

    ivn = fpow(N, mod - 2);
    n = (1 << 19);
    for(int i = 0; i < n; ++i) revbit[i] = (revbit[i >> 1] >> 1) + (i & 1) * (n >> 1);

    ivn = fpow(n, mod - 2);
  }

  void permute(int *a) {
    for(int i = 0; i < n; ++i) if(i < revbit[i]) {
      swap(a[i], a[revbit[i]]);
    }
  }

  void dft(int *a, int sign) {
    for(int i = 0; i < n; ++i) if(i < revbit[i]) {
      swap(a[i], a[revbit[i]]);
    }

    for(int len = 2; len <= n; len += len) {
      int delta = N / len * sign;
      for(int i = 0; i < n; i += len) {
        int *w = (sign > 0 ? rts : rts + N);
        for(int j = 0; j + j < len; ++j) {
          int &u = a[i + j], &v = a[i + (len >> 1) + j];
          int t = (long long)v * *w % mod;
          v = u - t;
          u = u + t;
          v += v < 0 ? mod : 0;
          u -= u >= mod ? mod : 0;
          w += delta;
        }
      }
    }

    if(sign < 0) {
      for(int i = 0; i < n; ++i) a[i] = (long long) ivn * a[i] % mod;
    }
  }

};

NumberTheoriticTransform < mod > ntt;

const int N = 1 << 19;

int n, m;
int a[N];
int b[N];
int id[N];
int risan[6][N];

int dfta[1 << 19];
int dftb[1 << 19];
int dftans[1 << 19];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    int x; cin >> x;
    ++a[x];
  }

  for(int i = 1; i <= m; ++i) {
    cin >> b[i];
    id[b[i] - 1] = i;
  }

  dfta[0] = 1; dfta[1] = 2;
  dftb[0] = 1; dftb[1] = 2; dftb[2] = 1;

  ntt.dft(dfta, 1);
  ntt.dft(dftb, 1);

  int one = 0, two = 0;
  for(int i = 0; i < N; ++i) {
    if(a[i] == 1) ++one;
    else if(a[i] > 1) ++two;

    if(id[i] > 0) {
      for(int i = 0; i < (1 << 19); ++i) dftans[i] = 1LL * fpow(dfta[i], one) * fpow(dftb[i], two) % mod;
      ntt.dft(dftans, -1);
      for(int j = 0; j < (1 << 19); ++j) risan[id[i]][j] = dftans[j];
    }
  }

  int q; cin >> q;
  while(q--) {
    int d; cin >> d;
    long long ret = 0;
    for(int i = 1; i <= m; ++i) {
      int num = (d - 2 * b[i]) / 2 - 1;
      if(num < 0) continue;
      if(num >= N) continue;
      ret += risan[i][num];
    }
    cout << ret % mod << "\n";
  }
}