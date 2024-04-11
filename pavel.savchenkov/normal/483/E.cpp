#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define pb push_back

inline bool bit(int x, int b) {
  return (x >> b) & 1;
}

string s[60];
int n, m;
double prob[1 << 21];
ll not_can[1 << 21];

int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  m = s[0].size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if  (j == i) {
        continue;
      }
      int mask = 0;
      for (int k = 0; k < m; ++k) {
        if  (s[i][k] == s[j][k]) {
          mask |= 1 << k;
        }
      }
      not_can[mask] |= 1ll << i;
    }
  }

  for (int len = m; len >= 0; --len) {
    for (int mask = 0; mask < (1 << m); ++mask) {
      if  (__builtin_popcount(mask) == len) {
        for (int k = 0; k < m; ++k) {
          if  (bit(mask, k)) {
            not_can[mask ^ (1 << k)] |= not_can[mask];
          }
        }
      }                             
    }
  }

  double ans = 0.0;
  memset (prob, 0, sizeof prob);
  prob[0] = 1.0;
  for (int len = 0; len <= m; ++len) {
    for (int mask = 0; mask < (1 << m); ++mask) {
      if  (__builtin_popcount(mask) == len) {
        for (int k = 0; k < m; ++k) {
          if  (!bit(mask, k)) {
            double nprob = prob[mask] / (m - len);
            ll nmask = mask | (1 << k);
            int cnt_end = __builtin_popcountll(not_can[mask] ^ not_can[nmask]);
            ans += ((double) cnt_end / n) * nprob * (len + 1);
            prob[mask | (1 << k)] += nprob;
          }
        }
      }
    }
  }

  printf("%.10f\n", ans);
  return 0;
}