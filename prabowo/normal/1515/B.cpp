#include <bits/stdc++.h>
using namespace std;

long long n;

vector<int> squares;

int solve() {
  int n;
  scanf("%d", &n);

  if (n % 2 == 0 && binary_search(squares.begin(), squares.end(), n / 2)) return 0 * printf("YES\n");
  if (n % 4 == 0 && binary_search(squares.begin(), squares.end(), n / 4)) return 0 * printf("YES\n");
  printf("NO\n");
  return 0;
}

int main() {
  for (int i = 0; i*i <= 1000000000; ++i) {
    squares.push_back(i*i);
  }
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}