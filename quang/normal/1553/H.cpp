#include <bits/stdc++.h>

using namespace std;

const int N = 19;
const int INF = 1e9;

int n, k;
long long mn[1 << N];
long long mx[1 << N];
long long res[1 << N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < (1 << k); i++) {
    mn[i] = INF;
    mx[i] = -INF;
    res[i] = INF;
  }
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    mn[u] = mx[u] = u;
  }
  for (int i = 1; i < (1 << k); i <<= 1) {
    for (int j = 0; j < i; j++) {
      for (int x = j; x < (1 << k); x += (i << 1)) {
        res[x] = res[x + i] = min(res[x], res[x + i]);
        res[x] = min(res[x], mn[x + i] - mx[x]);
        res[x + i] = min(res[x + i], mn[x] - mx[x + i] + i * 2);

        long long min_val[2] = {mn[x], mn[x + i]};
        long long max_val[2] = {mx[x], mx[x + i]};
        mn[x] = min(min_val[0], min_val[1]);
        mx[x] = max(max_val[0], max_val[1]);
        mn[x + i] = min(min_val[0] ^i , min_val[1] ^ i);
        mx[x + i] = max(max_val[0] ^i , max_val[1] ^ i); 
      }
    }
  }
  for (int i = 0; i < (1 << k); i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
  return 0;
}