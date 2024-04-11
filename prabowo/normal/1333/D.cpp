#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n, k;
char s[N];

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);

  vector<int> ans;
  vector<int> idxs = {0};
  for (;;) {
    for (int j = 1; j < n; ++j) {
      if (s[j-1] == 'R' && s[j] == 'L') {
        ans.push_back(j);
        swap(s[j-1], s[j]);
        ++j;
      }
    }
    if (ans.size() == idxs.back()) break;
    idxs.push_back(ans.size());
  }

  if (idxs.size() > k + 1) return 0 * printf("-1\n");
  if (ans.size() < k) return 0 * printf("-1\n");

  int lst = 0;
  for (int i = 1; i < idxs.size(); ++i) {
    int curSize = idxs[i] - idxs[i-1];
    int take = min(((int) ans.size() - idxs[i-1]) - k, curSize - 1);
    // cerr << k << " " << take << endl;
    ++take;

    printf("%d", take);
    for (int j = 0; j < take; ++j) printf(" %d", ans[idxs[i-1] + j]);
    printf("\n");
    --k;

    if (curSize - take > 0) {
      for (int j = take; j < curSize; ++j) {
        --k;
        printf("1 %d\n", ans[idxs[i-1] + j]);
      }
    }
  }

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}