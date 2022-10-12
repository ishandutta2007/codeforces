#include <bits/stdc++.h>
using namespace std;

vector<long long> cubes;

int solve() {
  long long n;
  scanf("%lld", &n);

  for (long long c : cubes) {
    if (binary_search(cubes.begin(), cubes.end(), n - c)) return 0 * printf("YES\n");
  }

  printf("NO\n");
  return 0;
}

int main() {
  for (int i = 1; 1LL*i*i*i <= 1000000000000LL; ++i) {
    cubes.push_back(1LL*i*i*i);
  }
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}