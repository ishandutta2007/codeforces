#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 200005;
int n, s[N];
vector<int> p[N];

void add(int x, int v) {
  while (x <= n)
    s[x] += v, x += x & (-x);
}
int query(int x) {
  int ans = 1;
  while (x)
    ans += s[x], x &= x - 1;
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    p[x].push_back(i);
  }

  long long ans = 0;
  for (int i = 1, l = 0, r = n + 1; i <= n; i++)
    if (!p[i].empty()) {
      for (int x : p[i])
        ans += query(x);
      int tl = min(p[i][0], r), tr = max(p[i].back(), l);
      add(tl + 1, 1), add(tr, -1);
      l = tl, r = tr;
    }
  cout << ans;
}