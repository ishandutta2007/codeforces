#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, x;
int a[N];

int mex[N];
vector<int> idxs[N];

int solve() {
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < x; ++i) {
    idxs[i].clear();
    mex[i] = 0;
  }

  idxs[0].push_back(0);

  int ans = 0;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    int s = sum % x;
    while (binary_search(idxs[s].begin(), idxs[s].end(), mex[s])) {
      ++mex[s];
    }

    // cerr << s << " " << mex[s] << endl;

    ans = max(ans, i - mex[s] + 1);
    idxs[s].push_back(i + 1);
  }

  printf("%d\n", ans == 0 ? -1 : ans);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}