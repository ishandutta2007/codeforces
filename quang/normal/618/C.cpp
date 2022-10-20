#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
pair< pair<int, int>, int> a[N];

bool check(int u) {
  pair<int, int> A = make_pair(a[1].first.first - a[u].first.first, a[1].first.second - a[u].first.second);
  pair<int, int> B = make_pair(a[2].first.first - a[u].first.first, a[2].first.second - a[u].first.second);
  return 1ll * A.first * B.second != 1ll * A.second * B.first;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].first.first, &a[i].first.second);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 3; i <= n; i++) {
    if (check(i)) {
      cout << a[1].second << " " << a[2].second << " " << a[i].second << endl;
      return 0;
    }
  }
  return 0;
}