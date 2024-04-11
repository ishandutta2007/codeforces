#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int b[N];
int a[N];

int solve() {
  scanf("%d", &n);
  long long sum = 0;

  multiset<long long> bs;
  for (int i = 0; i < n + 2; ++i) {
    scanf("%d", &b[i]);
    sum += b[i];
    bs.insert(b[i]);
  }

  for (int i = 0; i < n + 2; ++i) {
    bs.erase(bs.find(b[i]));
    if ((sum - b[i]) % 2 == 0 && bs.find((sum - b[i]) / 2) != bs.end()) {
      bs.erase(bs.find((sum - b[i]) / 2));
      for (long long a : bs) printf("%lld ", a);
      printf("\n");
      return 0;
    }
    bs.insert(b[i]);
  }

  printf("-1\n");
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