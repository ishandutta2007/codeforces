#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int tree[(1 << 20) + 228];

void build(int v, int left, int right) {
  tree[v] = 0;
  if (left + 1 == right)
    return;
  int mid = (left + right) / 2;
  build(2 * v + 1, left, mid);
  build(2 * v + 2, mid, right);
}

void add(int v, int left, int right, int x, int y, int d) {
  if (y <= left || right <= x)
    return;
  if (x <= left && right <= y) {
    tree[v] += d;
    return;
  }
  int mid = (left + right) / 2;
  add(2 * v + 1, left, mid, x, y, d);
  add(2 * v + 2, mid, right, x, y, d);
}

int get(int v, int left, int right, int i) {
  if (left + 1 == right)
    return tree[v];
  int mid = (left + right) / 2;
  if (i < mid)
    return tree[v] + get(2 * v + 1, left, mid, i);
  return tree[v] + get(2 * v + 2, mid, right, i);
}

bool field[3][500'500];

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < 3; ++i) {
    char c;
    for (int j = 0; j < n; ++j) {
      cin >> c;
      field[i][j] = c - '0';
    }
  }
  int q;
  cin >> q;
  vector<pair<int, int>> queries(q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    queries[i] = make_pair(l - 1, r - 1);
  }
  vector<int> ans(q);
  vector<int> order(q);
  for (int i = 0; i < q; ++i)
    order[i] = i;
  sort(order.begin(), order.end(), [&queries](int a, int b) {
    return queries[a].first > queries[b].first;
  });
  for (int t = 0; t < 3; t += 2) {
    build(0, 0, n);
    int pr0 = n, pr2 = n;
    int j = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (!field[t][i]) {
        pr0 = i;
      } else if (field[t][i] && !field[1][i]) {
        if (i + 1 == pr0) {
          add(0, 0, n, i, n, 1);
        } else {
          add(0, 0, n, i, i + 1, 1);
        }
      } else {
        if (i + 1 == pr0 || i + 1 == pr2);
        else {
          if (pr2 >= pr0) {
            add(0, 0, n, i + 1, n, -1);
          } else {
            add(0, 0, n, i + 1, pr2, -1);
          }
        }
        pr2 = i;
      }
      while (j < q && queries[order[j]].first == i) {
        ans[order[j]] += get(0, 0, n, queries[order[j]].second);
        ++j;
      }
    }
  }
  int j = 0;
  int pr = n;
  build(0, 0, n);
  for (int i = n - 1; i >= 0; --i) {
    if (field[1][i]) {
      if (i + 1 == pr) {
        add(0, 0, n, i, i + 1, 1);
      } else {
        bool ok0 = true, ok2 = true;
        if (pr == n) {
          ok0 = false;
          ok2 = false;
        } else {
          for (int t = i; t <= pr; ++t)
            ok0 = ok0 && field[0][t];
          for (int t = i; t <= pr; ++t)
            ok2 = ok2 && field[2][t];
        }
        if (ok0 || ok2) {
          add(0, 0, n, i, pr, 1);
        } else {
          add(0, 0, n, i, n, 1);
        }
      }
      pr = i;
    }
    while (j < q && queries[order[j]].first == i) {
      ans[order[j]] += get(0, 0, n, queries[order[j]].second);
      ++j;
    }
  }
  for (int i = 0; i < q; ++i)
    cout << ans[i] << '\n';
  return 0;
}