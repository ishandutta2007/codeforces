#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

const int N = 100005;
int n, k, a[N], s[N << 1], gu[N];

int findmex(int n) {
  if (a[1])
    return 0;
  for (int i = 2; i <= n; i++)
    if (a[i] > a[i - 1] + 1)
      return a[i - 1] + 1;
  return a[n] + 1;
}

int cost() {
  sort(a + 1, a + n + 1);
  int ans = 1;
  for (int i = 2; i <= n; i++)
    ans += a[i] != a[i - 1];
  return ans - findmex(n);
}

namespace sgt {
int p[N];
int s0[N << 2], s1[N << 2];

void update(int i) {
  s0[i] = s0[i << 1] + s0[i << 1 | 1];
  s1[i] = s1[i << 1] + s1[i << 1 | 1];
}

void build(int i, int l, int r) {
  if (l == r) {
    s0[i] = gu[l], s1[i] = l * s0[i];
    p[l] = i;
    return;
  }

  int mid = (l + r) >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
  update(i);
}

void modify(int x) {
  int i = p[x];
  s0[i]--, s1[i] -= x;
  while (i >>= 1)
    update(i);
}

int query(int i, int l, int r, int x) {
  if (x >= s1[i])
    return 0;
  if (l == r)
    return s0[i] - x / l;
  int mid = (l + r) >> 1;
  if (x < s1[i << 1])
    return query(i << 1, l, mid, x) + s0[i << 1 | 1];
  else
    return query(i << 1 | 1, mid + 1, r, x - s1[i << 1]);
}
} // namespace sgt

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    map<int, int> qwq;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] > n) {
        auto it = qwq.find(a[i]);
        if (it == qwq.end())
          qwq[a[i]] = n + cnt + 1, cnt++;
        a[i] = qwq[a[i]];
      }

    int ans = cost();

    for (int i = 1; i <= n; i++)
      s[a[i]]++;
    for (int i = 0; i <= 2 * n; i++)
      gu[s[i]]++;

    sgt::build(1, 1, n);
    for (int mex = 1, em = 0; mex <= n; mex++) {
      if (!s[mex - 1])
        em++;
      else
        sgt::modify(s[mex - 1]);
      if (em > k)
        break;
      int g = sgt::query(1, 1, n, k);
      if (g)
        ans = min(ans, g);
      else {
        ans = 0;
        break;
      }
    }

    cout << ans << '\n';

    memset(s, 0, (2 * n + 1) << 2);
    memset(gu, 0, (n + 1) << 2);
  }
}