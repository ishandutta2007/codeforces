#include<bits/stdc++.h>

using namespace std;

const int MAXN = 42;

typedef bitset<MAXN> bs;

int n, k;
bs a[MAXN];
int f[1 << (MAXN / 2)];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      int x; cin >> x;
      a[i][j] = x;
    }
  }

  if(n == 1) return cout << 0, 0;

  int c = n / 2, d = n - c;

  for(int mask = 0; mask < (1 << c); ++mask) {
    bs cur(mask);
    int all = cur.count(), able = 1;
    for(int i = 0; i < c; ++i) {
      if(mask & (1 << i)) {
        if((a[i] & cur).count() != all - 1) {
          able = 0;
          break;
        }
      }
    }
    if(able) f[mask] = all;
    for(int i = 0; i < c; ++i) {
      f[mask | (1 << i)] = max(f[mask | (1 << i)], f[mask]);
    }
  }

  int ans = 1;

  for(int mask = 0; mask < (1 << d); ++mask) {
    bs cur(mask), edges;
    cur <<= c;
    for(int i = 0; i < c; ++i) edges[i] = 1;

    int all = cur.count(), able = 1;
    for(int i = 0; i < d; ++i) {
      if(mask & (1 << i)) {
        if((a[i + c] & cur).count() != all - 1) {
          able = 0;
          break;
        }
        edges &= a[i + c];
      }
    }

    if(able) {
      int mask2 = edges.to_ulong();
      ans = max(ans, all + f[mask2]);
    }
  }

  double rans = ans;
  cout << fixed << setprecision(10) << k * k * (ans * (ans - 1) / 2) * (1 / rans / rans) << endl;

  return 0;
}