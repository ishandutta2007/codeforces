#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

vector<int> pos[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    pos[a[i]].push_back(i);
  }
  pos[0].push_back(n);
  for (int i = 1; i <= n; ++i) {
    pos[i].push_back(n);
    reverse(pos[i].begin(), pos[i].end());
  }

  int lst0 = 0, lst1 = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == lst0 && a[i] == lst1) continue;
    if (a[i] == lst0) {
      lst0 = a[i];
      continue;
    }
    if (a[i] == lst1) {
      lst1 = a[i];
      continue;
    }

    while (pos[lst0].size() > 0 && pos[lst0].back() <= i) pos[lst0].pop_back();
    while (pos[lst1].size() > 0 && pos[lst1].back() <= i) pos[lst1].pop_back();
    if (pos[lst0].back() > pos[lst1].back()) {
      lst0 = a[i];
    } else {
      lst1 = a[i];
    }
    ++ans;
  }

  printf("%d\n", ans);
  return 0;
}