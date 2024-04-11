#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

pair<int, int> jump(pair<int, int> p) {
  if (p.first == 0 && p.second == 0) return p;
  if (p.first - 1 & p.second) return {p.first, p.second ^ (p.second & -p.second)};
  return {p.first ^ (p.first & -p.first), p.second};
}

inline int depth(pair<int, int> p) { return p.first + p.second; }

vector<pair<int, pair<int, int>>> hori, vert;
pair<int, int> lca(pair<int, int> p, pair<int, int> q) {
  while (p != q) {
    // cerr << p.first << " " << p.second << "; " << q.first << " " << q.second << endl;
    pair<int, int> np = jump(p), nq = jump(q);

    if (np == nq && (p.first == np.first) == (q.first == nq.first)) {
      if (depth(p) < depth(q)) swap(p, q);
      if (p.first == np.first) {
        hori.push_back({p.first, {q.second, p.second}});
      } else {
        vert.push_back({p.second, {q.first, p.first}});
      }
      p = q;
    } else {
      if (depth(np) < depth(nq) || (depth(np) == depth(nq) && depth(p) < depth(q))) swap(p, q), swap(np, nq);
      if (p.first == np.first) {
        hori.push_back({p.first, {np.second, p.second}});
      } else {
        vert.push_back({p.second, {np.first, p.first}});
      }
      p = np;
    }
  }
  // cerr << p.first << " " << p.second << endl;

  if (p.first - 1 & p.second) {
    hori.push_back({p.first, {p.second - 1, p.second}});
  } else {
    vert.push_back({p.second, {p.first - 1, p.first}});
  }
  return p;
}

vector<int> flips;
void mergeSegments(vector<pair<int, pair<int, int>>> &segments) {
  sort(segments.begin(), segments.end());

  for (int i = 0; i < segments.size(); ) {
    int j = i;

    int rgt = -100;
    while (j < segments.size() && segments[i].first == segments[j].first) {
      // cerr << segments[i].first << " " << segments[j].second.first << " " << segments[j].second.second << endl;
      if (rgt < segments[j].second.first + segments[i].first) {
        flips.push_back(rgt);
        flips.push_back(segments[j].second.first + segments[i].first);
      }
      rgt = max(rgt, segments[j].second.second + segments[i].first);
      ++j;
    }
    flips.push_back(rgt);

    i = j;
  }
}

int solve() {
  int m;
  scanf("%d", &m);

  bool root = false;
  hori.clear(); vert.clear();
  for (int i = 0; i < m; ++i) {
    int x, y, xx, yy;
    scanf("%d %d %d %d", &x, &y, &xx, &yy);
    root |= lca({x, y}, {xx, yy}) == make_pair(0, 0);
  }

  flips.clear();
  // cerr << "OK" << endl;
  mergeSegments(hori);
  // cerr << "OK" << endl;
  mergeSegments(vert);

  sort(flips.begin(), flips.end());
  int ans = 0;
  for (int i = 0; i < flips.size(); ) {
    int j = i;
    while (j < flips.size() && flips[i] == flips[j]) {
      // cerr << flips[j] << endl;
      ++j;
    }

    if (flips[i] >= 0 && (j - i & 1)) ++ans;
    i = j;
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}