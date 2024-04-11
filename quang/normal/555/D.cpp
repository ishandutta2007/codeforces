#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
pair<int, int> b[N];
int x[N], c[N], d[N];
int xx, posx, excess, cnt;

int go(int pos, int l, int r, int len, int flag) {
  if (len == 0) {
    if (flag) {
      return r;
    } else {
      return l;
    }
  }
  if (l == r) {
    return l;
  }
  if (flag) {
    xx = x[pos] - len;
    posx = lower_bound(x + l, x + r + 2, xx) - x;
    if (posx == pos) {
      return pos;
    }
    cnt = len / (x[pos] - x[posx]);
    excess = len % (x[pos] - x[posx]);
    if (cnt & 1) {
      return go(posx, posx, r, excess, flag ^ 1);
    } else {
      return go(pos, posx, r, excess, flag);
    }
  } else {
    xx = x[pos] + len;
    posx = upper_bound(x + l, x + r + 2, xx) - x - 1;
    if (posx == pos) {
      return pos;
    }
    cnt = len / (x[pos] - x[posx]);
    excess = len % (x[pos] - x[posx]);
    if (cnt & 1) {
      return go(posx, l, posx, excess, flag ^ 1);
    } else {
      return go(pos, l, posx, excess, flag);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef Q
  freopen("inp.txt", "r", stdin);
#endif // Q
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    x[i] = b[i].first;
    c[i] = b[i].second;
    d[b[i].second] = i;
  }
  x[0] = -2e9 - 10;
  x[n + 1] = 2e9 + 10;
  while (m--) {
    int a, l;
    cin >> a >> l;
    a = d[a];
    int pos = x[a] + l;
    int xx = upper_bound(x, x + n + 2, pos) - x - 1;
    cout << c[go(xx, 1, xx, pos - x[xx], 1)] << endl;
  }
  return 0;
}