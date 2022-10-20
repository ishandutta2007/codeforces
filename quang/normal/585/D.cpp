#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n;
int a[3][N], cnt;
pair<pair<int, int>, pair<long long, long long> > d[2000000];
int out[N], mid;
int res = -1e9;

void go(int u, int n, int A, int B, int C, long long mask) {
  if (u > n) {
    d[cnt++] = make_pair(make_pair(B - A, C - B), make_pair(-A, mask));
    return;
  }
  for (int i = 0; i < 3; i++) {
    int aa = A, bb = B, cc = C;
    aa += a[0][u] * (i != 0);
    bb += a[1][u] * (i != 1);
    cc += a[2][u] * (i != 2);
    go (u + 1, n, aa, bb, cc, mask * 4 + i);
  }
}

void go2(int u, int n, int A, int B, int C, int mask) {
  if (u > n) {
    pair<int, int> need = make_pair(A - B, B - C);
    int pos = lower_bound(d, d + cnt, make_pair(need, make_pair(-1000000000ll, 0ll))) - d;
    if (pos >= cnt || d[pos].first != need) {
      return;
    }
    if (res < -d[pos].second.first + A) {
      res = -d[pos].second.first + A;
      int f = d[pos].second.second;
      for (int i = mid; i; i--) {
        int x = f & 3;
        out[i] = x;
        f >>= 2;
      }
      for (int i = n; i > mid; i--) {
        int x = mask & 3;
        out[i] = x;
        mask >>= 2;
      }
    }
    return;
  }
  for (int i = 0; i < 3; i++) {
    int aa = A, bb = B, cc = C;
    aa += a[0][u] * (i != 0);
    bb += a[1][u] * (i != 1);
    cc += a[2][u] * (i != 2);
    go2(u + 1, n, aa, bb, cc, mask * 4 + i);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[0][i] >> a[1][i] >> a[2][i];
  }
  mid = (n + 1) / 2;
  go(1, mid, 0, 0, 0, 0);
  sort(d, d + cnt);
  go2(mid + 1, n, 0, 0, 0, 0);
  if (res <= -1e9) {
    puts("Impossible");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (out[i] != 0) {
      cout << "L";
    }
    if (out[i] != 1) {
      cout << "M";
    }
    if (out[i] != 2) {
      cout << "W";
    }
    cout << endl;
  }
  return 0;
}