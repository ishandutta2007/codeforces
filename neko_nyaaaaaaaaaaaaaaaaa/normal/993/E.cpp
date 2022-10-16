#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef complex<double> cd;
const double PI = acos(-1.0);

void fft(vector<cd> &a, bool invert) {
      int n = a.size();

      for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;

            if (i < j) swap(a[i], a[j]);
      }

      for (int len = 2; len <= n; len <<= 1) {
            double ang = 2*PI / len*(invert ? -1 : 1);
            cd wlen(cos(ang), sin(ang));

            for (int i = 0; i < n; i += len) {
                  cd w(1);
                  for (int j = 0; j < len/2; j++) {
                        cd u = a[i+j], v = a[i+j+len/2] * w;
                        a[i+j] = u+v;
                        a[i+j+len/2] = u-v;
                        w *= wlen;
                  }
            }
      }

      if (invert) {
            for (cd &x: a) x /= n;
      }
}

vector<int> polymul(vector<int> &a, vector<int> &b) {
      vector<cd> fa(a.begin(), a.end());
      vector<cd> fb(b.begin(), b.end());

      int n = 1;
      while (n < a.size() + b.size()) n <<= 1;
      fa.resize(n); fb.resize(n);
      fft(fa, 0); fft(fb, 0);

      for (int i = 0; i < n; i++) {
            fa[i] *= fb[i];
      }
      fft(fa, 1);

      vector<int> ans(n);
      for (int i = 0; i < n; i++) {
            ans[i] = round(fa[i].real());
      }
      return ans;
}

void solve(vector<int> x, vector<int> y, int n, int a0) {
      vector<int> a(400001), b(400001);
      for (int i: x) a[i + 200000]++;
      for (int i: y) b[i + 200000]++;

      vector<int> c = polymul(a, b);

      cout << a0 << ' ';
      for (int i = 1; i <= n; i++) {
            cout << c[i+400000] << " ";
      }
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, x, a0 = 0; cin >> n >> x;
      vector<int> a(n+1), b(n+1);
      map<int, int> m; m[0]++;
      for (int i = 1; i <= n; i++) {
            int k; cin >> k;
            a[i] = a[i-1] + (k < x);
            b[i] = b[i-1] - (k < x);
            m[a[i]]++;
      }
      for (auto u: m) {
            int k = u.second;
            a0 += k*(k-1)/2;
      }

      solve(a, b, n, a0);

      return 0;
}