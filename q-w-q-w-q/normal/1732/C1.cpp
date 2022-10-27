// LUOGU_RID: 91280296
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100005;
int n, q, a[N];
int s[N][30], lt[N][30], rt[N][30];

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    memcpy(s[i], s[i - 1], sizeof s[i - 1]);
    memcpy(lt[i], lt[i - 1], sizeof lt[i - 1]);
    for (int j = 0; j != 30; j++)
      if (a[i] >> j & 1)
        s[i][j]++, lt[i][j] = i;
  }
  for (int i = n; i; i--) {
    memcpy(rt[i], rt[i + 1], sizeof rt[i + 1]);
    for (int j = 0; j != 30; j++)
      if (a[i] >> j & 1)
        rt[i][j] = i;
  }

  while (q--) {
    static pair<int, int> lim[30];
    int l, r, cnt = 0;
    cin >> l >> r;
    int al = r, ar = l;
    for (int j = 0; j != 30; j++) {
      int x = s[r][j] - s[l - 1][j];
      if (x < 2)
        continue;
      if (x % 2 == 0) {
        al = min(al, rt[l][j]);
        ar = max(ar, lt[r][j]);
      } else {
        al = min(al, rt[rt[l][j] + 1][j]);
        ar = max(ar, lt[lt[r][j] - 1][j]);
        lim[cnt++] = {rt[l][j], lt[r][j]};
      }
    }

    sort(lim, lim + cnt);
    while (cnt && lim[cnt - 1].first >= al)
      cnt--;

    if (cnt == 0) {
      if (al > ar)
        al = ar;
      cout << al << ' ' << ar << '\n';
      continue;
    }

    int ql = l, qr = r;
    for (int i = 0; i != cnt; i++) {
      int x = lim[i].first, y = ar;
      if (y - x < qr - ql)
        ql = x, qr = y;
      ar = max(ar, lim[i].second);
    }
    int x = min(al, ar), y = ar;
    if (y - x < qr - ql)
      ql = x, qr = y;
    cout << ql << ' ' << qr << '\n';

    cnt = 0;
  }
}

void clear() {
  for (int i = 1; i <= n; i++) {
    memset(lt[i], 0, sizeof lt[i]);
    memset(rt[i], 0, sizeof rt[i]);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    clear();
  }
}