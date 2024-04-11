#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;
int n, m, a[N], b[N];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    cin >> a[i];
  sort(a + 1, a + m + 1);
  b[1] = a[1] - 1 + n - a[m];
  for (int i = 2; i <= m; i++)
    b[i] = a[i] - a[i - 1] - 1;
  sort(b + 1, b + m + 1, greater<int>());
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    b[i] -= 4 * (i - 1);
    if (b[i] == 1)
      sum += 1;
    if (b[i] > 1)
      sum += b[i] - 1;
  }
  cout << n - sum << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}

//mod mwr!!!!