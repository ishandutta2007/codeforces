#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int A = 10000005;

int n, m, k;
int a[N];

bool prime[A];
int p[A];

void init() {
  memset(prime, true, sizeof prime);
  for (int i = 0; i < A; ++i) p[i] = 1;
  for (int i = 2; i < A; ++i) {
    if (!prime[i]) continue;
    for (int j = i; j < A; j += i) {
      prime[j] = false;
      int num = j, e = 0;
      do {
        num /= i; e ^= 1;
      } while (num % i == 0);
      if (e) p[j] *= i;
    }
  }
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    // cerr << p[a[i]] << endl;
  }

  int ans = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    set<int> nums;
    while (j < n && nums.find(p[a[j]]) == nums.end()) nums.insert(p[a[j++]]);

    ++ans;
    i = j;
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  init();
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}