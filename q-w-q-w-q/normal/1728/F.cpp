#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>

using namespace std;

const int N = 1005;
int n;
int mh[N], top;
pair<int, int> a[N * N];
bitset<1000> e[N], nw;

bool dfs(int i) {
  while (1) {
    int j = (e[i] & nw)._Find_first();
    if (j >= n)
      return 0;
    nw[j] = 0;
    if (mh[j] == -1 || dfs(mh[j])) {
      mh[j] = i;
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0, x; i != n; i++) {
    cin >> x, mh[i] = -1;
    for (int j = 1; j <= n; j++)
      a[n * i + j] = {x * j, i};
  }

  sort(a + 1, a + n * n + 1);
  long long ans = 0;
  for (int i = 1, j;; i = j) {
    top++;
    for (j = i; j <= n * n && a[j].first == a[i].first; j++)
      e[top][a[j].second] = 1;
    nw.set();
    if (dfs(top))
      ans += a[i].first;
    else
      e[top--].reset();
    if (top == n) {
      cout << ans << endl;
      return 0;
    }
  }
}