#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int ans[N];

int askDebug(int a, int b, int c) {
  vector<int> p = {9, 10, 19, 7, 16, 18, 11, 14, 15, 6, 20, 8, 17, 4, 5, 3, 12, 2, 13, 1};
  vector<int> v = {abs(p[a] - p[b]), abs(p[a] - p[c]), abs(p[b] - p[c])};
  sort(v.begin(), v.end());
  return v[1];
}

int ask(int a, int b, int c) {
  // return askDebug(a, b, c);
  printf("? %d %d %d\n", a + 1, b + 1, c + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

int answer() {
  printf("!");
  for (int i = 0; i < n; ++i) printf(" %d", ans[i]);
  printf("\n");
  fflush(stdout);

  int verdict;
  scanf("%d", &verdict);
  return verdict;
}

int solve() {
  scanf("%d", &n);

  int a, b, c;
  while (true) {
    a = rand() % n, b = rand() % n, c = rand() % n;
    if (a == b || a == c || b == c) continue;

    if (ask(a, b, c) <= (n - 4) / 6) break;
  }

  vector<int> queries(n);
  int one = -1, maxi = -1;
  for (int i = 0; i < n; ++i) {
    if (i == a || i == b) continue;
    if ((queries[i] = ask(a, b, i)) > maxi) {
      maxi = queries[i];
      one = i;
    }
  }

  vector<int> twos;
  for (int i = 0; i < n; ++i) {
    if (i == a || i == b) continue;
    if (queries[i] == maxi - 1) twos.push_back(i);
  }

  int two;
  if (twos.size() == 1) {
    two = twos[0];
  } else if (twos.size() == 2) {
    two = ask(one, a, twos[0]) < ask(one, a, twos[1]) ? twos[0] : twos[1];
  } else {
    assert(0);
  }

  ans[one] = 1; ans[two] = 2;
  for (int i = 0; i < n; ++i) {
    if (i == one || i == two) continue;
    ans[i] = ask(one, two, i) + 2;
  }

  if (ans[0] > ans[1]) {
    for (int i = 0; i < n; ++i) ans[i] = n - ans[i] + 1;
  }

  assert(answer() == 1);
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