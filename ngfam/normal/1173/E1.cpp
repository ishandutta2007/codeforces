#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const long long mod = 998244353;

long long fpow(long long x, long long y) {
  x %= mod;
  long long ret = 1;
  while(y) {
    if(y & 1) ret = (long long) ret * x % mod;
    y >>= 1;
    x = (long long) x * x % mod;
  }
  return ret;
}

int n, m;
int a[N];
int w[N];
long long f[N][N][N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int totlike = 0, totdislike = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> w[i];
    if(a[i]) totlike += w[i];
    else totdislike += w[i];
  }

  for(int i = 1; i <= n; ++i) {
    memset(f, 0, sizeof f);

    int sumlike = totlike - a[i] * w[i];
    int sumdislike = totdislike - (1 - a[i]) * w[i];

 //   cout << "bug: " << sumlike << " " << sumdislike << endl;

    f[0][0][0] = 1;
    for(int d = 0; d < m; ++d) {
      for(int like = 0; like <= d; ++like) {
        for(int dislike = 0; dislike <= d - like; ++dislike) {
          if(!f[d][like][dislike]) continue;
        //  cout << d << " " << like << " " << dislike << " " << f[d][like][dislike] << endl;
          int delta = d - like - dislike;

          int sum = sumlike + like + sumdislike - dislike + (w[i] + (a[i] ? 1 : -1) *  delta);
          int prob = fpow(sum, mod - 2);

          if(a[i] || delta < w[i]) f[d + 1][like][dislike] += (f[d][like][dislike] * (w[i] + (a[i] ? 1 : -1) *  delta) % mod) * prob % mod;
          f[d + 1][like + 1][dislike] += (f[d][like][dislike] * (sumlike + like) % mod) * prob % mod;
          if(dislike < sumdislike) f[d + 1][like][dislike + 1] += (f[d][like][dislike] * prob % mod) * (sumdislike - dislike) % mod;
        }
      }
    }

    long long ret = 0;
    for(int like = 0; like <= m; ++like) {
      for(int dislike = 0; dislike <= m - like; ++dislike) {
        int delta = m - like - dislike;

   //     cout << f[m][like][dislike] << endl;

        ret += (w[i] + (a[i] ? 1 : -1) *  delta) * f[m][like][dislike] % mod;
        ret %= mod;
      }
    }
    cout << ret << endl;
  }

  return 0;
}