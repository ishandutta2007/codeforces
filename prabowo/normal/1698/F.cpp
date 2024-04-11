#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n;
int a[N];
int b[N];

vector<pair<int, int>> ans;
void rev(int l, int r) {
  reverse(a + l, a + r + 1);
  ans.emplace_back(l + 1, r + 1);
}

vector<pair<int, int>> getPairs(int a[]) {
  vector<pair<int, int>> ret;
  for (int i = 1; i < n; ++i) {
    ret.emplace_back(min(a[i - 1], a[i]), max(a[i - 1], a[i]));
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  if (getPairs(a) != getPairs(b)) return 0 * printf("NO\n");
  if (a[0] != b[0] || a[n - 1] != b[n - 1]) return 0 * printf("NO\n");

  ans.clear();
  for (int i = 1; i < n; ++i) {
    if (a[i] == b[i]) continue;

    for (int j = i + 1; j < n; ++j) {
      if (a[j - 1] == b[i] && a[j] == a[i - 1]) {
        rev(i - 1, j);
        break;
      }
    }

    if (a[i] == b[i]) continue;

    bool found = false;
    for (int j = i; j < n; ++j) {
      if (a[j] == a[i - 1] && a[j + 1] == b[i]) {
        for (int l = i - 1; l <= j; ++l) {
          for (int r = j + 1; r < n; ++r) {
            if (a[l] == a[r]) {
              rev(l, r);
              found = true;
              break;
            }
          }
          if (found) break;
        }
        if (found) break;
      }
    }

    for (int j = i + 1; j < n; ++j) {
      if (a[j - 1] == b[i] && a[j] == a[i - 1]) {
        rev(i - 1, j);
        break;
      }
    }
  }

  printf("YES\n%d\n", (int) ans.size());
  for (pair<int, int> p : ans) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}