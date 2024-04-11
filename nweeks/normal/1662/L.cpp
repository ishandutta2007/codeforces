#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5 + 1;
const int INF = 1e18;

struct Tir {
  int x, y, z;
};

int dp[MAXN];

struct maxSeg {
  vector<int> seg;
  int deb, p;

  maxSeg(int n) {
    p = 0;
    while ((1 << p) < n)
      ++p;
    seg.assign((1 << (p + 1)), -INF);
    deb = 1 << p;
  }

  void upd(int x, int v, bool force) {
    x += deb;
    if (force)
      seg[x] = v;
    else
      seg[x] = max(seg[x], v);
    while (x > 1) {
      x /= 2;
      seg[x] = max(seg[2 * x], seg[2 * x + 1]);
    }
  }

  /*
   * 1
   * 2 3
   * 4 5 6 7
   */
  int query(int l, int r) {
    int sol = -INF;
    l += deb, r += deb;
    while (l < r) {
      if (l % 2)
        sol = max(sol, seg[l++]);
      if (r % 2 == 0)
        sol = max(sol, seg[r--]);
      l /= 2;
      r /= 2;
    }
    if (l == r)
      sol = max(sol, seg[l]);
    return sol;
  }
};

maxSeg seg(MAXN);

void solve(vector<Tir> &tirs) {
  int nbTirs = tirs.size();
  if (nbTirs < 2)
    return;

  vector<Tir> left(tirs.begin(), tirs.begin() + nbTirs / 2);
  vector<Tir> right(tirs.begin() + nbTirs / 2, tirs.end());
  solve(left);

  int posL = 0;
  int szL = left.size();
  sort(right.begin(), right.end(), [](auto l, auto r) {
    return tuple(l.y, l.z, l.x) < tuple(r.y, r.z, r.x);
  });
  /*cout << "LEFT\n";
  for (auto [x, y, z] : left)
    cout << x << ' ' << y << ' ' << z << endl;
  cout << "RIGHT\n";
  for (auto [x, y, z] : right)
    cout << x << ' ' << y << ' ' << z << endl;*/
  for (auto [x, y, z] : right) {
    while (posL < szL and left[posL].y <= y) {
      // cout << "Added " << left[posL].z << ' ' << dp[left[posL].x] << endl;
      seg.upd(left[posL].z, dp[left[posL].x], false);
      ++posL;
    }
    // cout << "QUERY " << y << ' ' << z << ' ' << posL << ' ' << seg.query(0,
    // z)
    //    << endl;
    dp[x] = max(dp[x], 1 + seg.query(0, z));
  }
  for (auto [x, y, z] : left)
    seg.upd(z, -INF, true);
  sort(right.begin(), right.end(), [](auto l, auto r) {
    return tuple(l.x, l.y, l.z) < tuple(r.x, r.y, r.z);
  });

  solve(right);
  posL = 0;
  int posR = 0, szR = right.size();
  int cur = 0;
  while (posL < szL and posR < szR) {
    if (left[posL].y < right[posR].y)
      tirs[cur++] = left[posL++];
    else
      tirs[cur++] = right[posR++];
  }
  while (posL < szL)
    tirs[cur++] = left[posL++];
  while (posR < szR)
    tirs[cur++] = right[posR++];
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTirs, V;
  cin >> nbTirs >> V;

  vector<int> temps(nbTirs + 1), pos(nbTirs + 1);
  for (int i = 1; i <= nbTirs; ++i)
    cin >> temps[i];
  for (int i = 1; i <= nbTirs; ++i)
    cin >> pos[i];
  nbTirs++;
  vector<Tir> tirs(nbTirs);
  for (int i = 0; i < nbTirs; ++i)
    tirs[i] = {i, temps[i] * V + pos[i], temps[i] * V - pos[i]};

  vector<int> sums, diffs;
  for (auto [x, s, d] : tirs)
    sums.push_back(s), diffs.push_back(d);
  sort(sums.begin(), sums.end());
  sums.resize(unique(sums.begin(), sums.end()) - sums.begin());
  sort(diffs.begin(), diffs.end());
  diffs.resize(unique(diffs.begin(), diffs.end()) - diffs.begin());
  for (auto &[x, s, d] : tirs) {
    s = lower_bound(sums.begin(), sums.end(), s) - sums.begin();
    d = lower_bound(diffs.begin(), diffs.end(), d) - diffs.begin();
  }

  for (int i = 1; i < nbTirs; ++i)
    dp[i] = -INF;
  /*for (int i = 1; i < nbTirs; ++i)
    for (int j = 0; j < i; ++j)
      if (tirs[j].x <= tirs[i].x and tirs[j].y <= tirs[i].y and
          tirs[j].z <= tirs[i].z)
        dp[i] = max(dp[i], dp[j] + 1);*/
  solve(tirs);
  int sol = 0;
  for (int i = 0; i < nbTirs; ++i)
    sol = max(sol, dp[i]);
  cout << sol << endl;
}