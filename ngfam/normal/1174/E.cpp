#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int fpow(int x, int y) {
  int ret = 1;
  while(y) {
    if(y & 1) ret = (long long)ret * x % mod;
    y >>= 1;
    x = (long long) x * x % mod;
  }
  return ret;
}

const int N = 2000010;

long long fact[N], inv[N];

long long comb(int n, int k) {
//  cout << n << " " << k << endl;
  return fact[n] * (inv[n - k] * inv[k] % mod) % mod;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  fact[0] = inv[0] = 1;
  for(int i = 1; i <= n + n; ++i) {
    fact[i] = fact[i - 1] * i % mod;
    inv[i] = fpow(fact[i], mod - 2);
  }

  int curmax = 0;
  while((1 << (curmax + 1)) <= n) ++curmax;

  /// (1 << curmax) first;

  long long ret = 1;

  vector < int > f(curmax + 1, 0);
  for(int i = curmax; i >= 0; --i) {
    f[i] = (n / (1 << i));
    for(int j = i + 1; j <= curmax; ++j) {
      f[i] -= f[j];
    }
  }

  //cout << f << endl;

  int cnt = 0; /// current num
  for(int i = 0; i <= curmax; ++i) {
    /// candy spread 
    ret = ret * fact[f[i]] % mod;
  //  cout << ret << endl;
    ret = ret * comb(f[i] - 1 + cnt, cnt) % mod;

    //cout << ret << " " << cnt << endl;

    cnt += f[i];
  } 


  long long ret2 = 0;
  if((1 << (curmax - 1)) * 3 > n) {

  }
  else {
    for(int place = 1; place <= curmax; ++place) {
      vector < int > f(curmax + 1, 0);
      int prod = 1;
      for(int i = 0; i <= curmax; ++i) {
        if(i == 0) f[i] = n;
        else {
          if(i == place) prod *= 3;
          else prod *= 2;

          f[i] = n / prod; 
        }
      }
      
      for(int i = curmax; i >= 0; --i) {
        for(int j = i + 1; j <= curmax; ++j) {
          f[i] -= f[j];
        }
      }

     // cout << f << endl;

      long long ret2 = 1;
      int cnt = 0; /// current num
      for(int i = 0; i <= curmax; ++i) {
        /// candy spread 
        ret2 = ret2 * fact[f[i]] % mod;
      //  cout << ret << endl;
        ret2 = ret2 * comb(f[i] - 1 + cnt, cnt) % mod;

        //cout << ret << " " << cnt << endl;

         cnt += f[i];
      }

     // cout << ret2 << endl;

      ret += ret2;
    }
  }

  cout << (ret + ret2) % mod;

  return 0;
}