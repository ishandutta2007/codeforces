#include <bits/stdc++.h>
using namespace std;

const int N = 400005;

int n, I;
int a[N];

int main() {
  scanf("%d %d", &n, &I);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int bit = min(20, I*8 / n);

  sort(a, a + n);
  vector<int> dq;

  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && a[j] == a[i]) ++j;

    dq.push_back(j - i);
    i = j;
  }

  if (dq.size() <= (1 << bit)) return 0 * printf("0\n");

  int sum = 0;
  for (int i = 0; i < (1 << bit); ++i) {
    sum += dq[i];
  }

  int ans = n - sum;
  for (int i = 1 << bit; i < dq.size(); ++i) {
    sum += dq[i];
    sum -= dq[i - (1 << bit)];
    ans = min(ans, n - sum);
  }

  printf("%d\n", ans);
  return 0;
}