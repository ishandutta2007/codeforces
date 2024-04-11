#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
pair<int, int> a[N];

bool cmp(pair<int, int> u, pair<int, int> v) {
  return u.second < v.second;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i].first = i;
  }
  sort(a + 1, a + n + 1, cmp);
  int cur = n;
  int res = 0;
  while (cur) {
    int minval = a[cur].first;
    while (minval != cur) {
      cur--;
      minval = min(minval, a[cur].first);
    }
    cur--;
    res++;
  }
  cout << res << endl;
  return 0;
}