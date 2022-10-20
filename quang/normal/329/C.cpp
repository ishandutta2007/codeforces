#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N];
set< pair<int, int> > s;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    s.insert(make_pair(u, v));
    s.insert(make_pair(v, u));
  }
  for (int it = 1; it <= 100; it++) {
    for (int i = 1; i <= n; i++) {
      a[i] = i;
    }
    random_shuffle(a + 1, a + n + 1);
    int flag = 0;
    for (int i = 1; i <= m; i++) {
      int u = a[i];
      int v = i == n ? a[1] : a[i + 1];
      if (s.find(make_pair(u, v)) != s.end()) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      for (int i = 1; i <= m; i++) {
        int u = a[i];
        int v = i == n ? a[1] : a[i + 1];
        printf("%d %d\n", u, v);
      }
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}