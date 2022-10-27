#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;
int n, m;
vector<int> to[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x > y)
      swap(x, y);
    to[x].push_back(y - x);
    to[y].push_back(n + x - y);
  }

  for (int i = 0; i < n; i++)
    sort(to[i].begin(), to[i].end());

  for (int k = 1; k < n; k++) {
    if (n % k)
      continue;
    bool ok = 1;
    for (int i = 0; i < n && ok; i++) {
      int j = (i + k) % n;
      if (to[i].size() != to[j].size()) {
        ok = 0;
        break;
      }

      for (int x = 0; x < (int)to[i].size(); x++)
        if (to[i][x] != to[j][x]) {
          ok = 0;
          break;
        }
    }
    if (ok) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
}