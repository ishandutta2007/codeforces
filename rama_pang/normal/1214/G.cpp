#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;

  set<pair<int, int>> rows_id; // (size of bitset, id) of every row
  vector<bitset<2005>> blue(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      blue[i][j] = 0;
    }
    rows_id.emplace(0, i);
  }

  set<array<int, 4>> Certificates;
  vector<bitset<2005>> ones(m + 1);

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j < i; j++) {
      ones[i][j] = 1;
    }
  }

  auto CalcCertificate = [&](int x1, int x2, int sgn) {
    if (x1 == -1 || x2 == -1) return;
    if (x1 > x2) swap(x1, x2);
    if ((blue[x1] | blue[x2]) != blue[x1] && (blue[x1] | blue[x2]) != blue[x2]) {
      int y_1 = (blue[x1] & ~blue[x2])._Find_first();
      int y_2 = (blue[x2] & ~blue[x1])._Find_first();
      if (y_1 > y_2) swap(y_1, y_2);
      if (sgn == +1) Certificates.insert({x1, y_1, x2, y_2});
      if (sgn == -1) Certificates.erase({x1, y_1, x2, y_2});
    }
  };

  auto RemoveRow = [&](int x) {
    int popcnt = blue[x].count();
    auto it = rows_id.lower_bound({popcnt, x});
    int nxt = -1, prv = -1;
    if (next(it) != end(rows_id)) {
      it++;
      nxt = it->second;
      it--;
    }
    if (it != begin(rows_id)) {
      it--;
      prv = it->second;
      it++;
    }
    rows_id.erase(it);
    CalcCertificate(x, prv, -1);
    CalcCertificate(x, nxt, -1);
    CalcCertificate(prv, nxt, +1);
  };

  auto InsertRow = [&](int x) {
    int popcnt = blue[x].count();
    rows_id.emplace(popcnt, x);
    auto it = rows_id.lower_bound({popcnt, x});
    int nxt = -1, prv = -1;
    if (next(it) != end(rows_id)) {
      it++;
      nxt = it->second;
      it--;
    }
    if (it != begin(rows_id)) {
      it--;
      prv = it->second;
      it++;
    }
    CalcCertificate(prv, nxt, -1);
    CalcCertificate(x, prv, +1);
    CalcCertificate(x, nxt, +1);
  };

  auto UpdateRow = [&](int x, int l, int r) {
    RemoveRow(x);
    blue[x] ^= ones[l];
    blue[x] ^= ones[r];
    InsertRow(x);
  };

  auto Query = [&]() {
    if (Certificates.empty()) {
      cout << -1 << "\n";
      return;
    }
    array<int, 4> ans = *begin(Certificates);
    for (int i = 0; i < 4; i++) {
      cout << ans[i] + 1 << " \n"[i == 3];
    }
  };

  while (q--) {
    int a, l, r;
    cin >> a >> l >> r;
    UpdateRow(--a, --l, r);
    Query();
  }
}