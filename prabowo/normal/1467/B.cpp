#include <bits/stdc++.h>
using namespace std;
 
const int N = 300005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
bool in[N];

int diff(int x, int y) {
  int ret = 0;
  if (x > 1) {
    bool aft = false;
    if (a[x - 1] > a[x - 2] && a[x - 1] > y) aft = true;
    if (a[x - 1] < a[x - 2] && a[x - 1] < y) aft = true;
    if (aft != in[x - 1]) ret += (aft ? 1 : -1);
  }
  if (x > 0 && x < n - 1) {
    bool aft = false;
    if (y > a[x - 1] && y > a[x + 1]) aft = true;
    if (y < a[x - 1] && y < a[x + 1]) aft = true;
    if (aft != in[x]) ret += (aft ? 1 : -1);
  }
  if (x < n - 2) {
    bool aft = false;
    if (a[x + 1] > a[x + 2] && a[x + 1] > y) aft = true;
    if (a[x + 1] < a[x + 2] && a[x + 1] < y) aft = true;
    if (aft != in[x + 1]) ret += (aft ? 1 : -1);
  }
  return ret;
}

int solve() {
  scanf("%d", &n);
  // scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = 0;
  int con = 0;
  for (int i = 1; i < n - 1; ++i) {
    in[i] = false;
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) in[i] = true;
    else if (a[i] < a[i - 1] && a[i] < a[i + 1]) in[i] = true;

    if (in[i]) ++ans;
  }

  int maxi = 0;
  for (int i = 1; i < n - 1; ++i) {
    maxi = min(maxi, min(diff(i, a[i - 1]), diff(i, a[i + 1])));
  }

  printf("%d\n", ans + maxi);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}