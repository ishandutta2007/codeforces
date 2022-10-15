#include <cstdio>
#include <vector>

using namespace std;

int const N = 123456;
int const MOD = 1000000007;

vector<int> edges[N];

int dp[2][N];
int color[N];

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return (long long) a * b % MOD;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x;
    scanf("%d", &x);
    edges[x].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", color + i);
  }
  for (int v = n - 1; v >= 0; v--) {
    int sz = edges[v].size();
    vector<int> zero(sz);
    for (int e = 0; e < sz; e++) {
      int to = edges[v][e];
      zero[e] = add(dp[0][to], dp[1][to]);
    }
    vector<int> a(sz);
    vector<int> b(sz);
    for (int i = 0, cur = 1; i < sz; i++) {
      cur = mul(cur, zero[i]);
      a[i] = cur;
    }
    for (int i = sz - 1, cur = 1; i >= 0; i--) {
      cur = mul(cur, zero[i]);
      b[i] = cur;
    }
    int all = 1;
    for (int i : zero) all = mul(all, i);
    if (color[v] == 0) {
      dp[0][v] = all;
      int cur = 0;
      for (int i = 0; i < sz; i++) {
        int to = edges[v][i];
        cur = add(cur, mul((i > 0 ? a[i - 1] : 1), mul((i + 1 < sz ? b[i + 1] : 1), dp[1][to])));
      }
      dp[1][v] = cur;
    } else {
      dp[0][v] = 0;
      dp[1][v] = all;
    }
  }
  printf("%d\n", dp[1][0]);
}