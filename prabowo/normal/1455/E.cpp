#include <bits/stdc++.h>
using namespace std;
 
const int N = 501;
const int INF = 1e9 + 5;
const long long INFLL = 1LL * INF * INF;

pair<int, int> points[4];

long long dist(pair<long long, long long> p, pair<long long, long long> q) {
  return abs(p.first - q.first) + abs(p.second - q.second);
}

long long shortest(int x, int y, long long len) {
  pair<long long, long long> squares[4] = {{x, y}, {x + len, y}, {x, y + len}, {x + len, y + len}};
  long long ret = INFLL;
  vector<int> p = {0, 1, 2, 3};
  do {
    long long sum = 0;
    for (int i = 0; i < 4; ++i) sum += dist(squares[p[i]], points[i]);
    ret = min(ret, sum);
  } while (next_permutation(p.begin(), p.end()));

  // cerr << x << " " << y << " " << len << " " << ret << endl;
  return ret;
}

int solve() {
  int minX = INF, maxX = -INF, minY = INF, maxY = -INF;
  for (int i = 0; i < 4; ++i) {
    scanf("%d %d", &points[i].first, &points[i].second);
    minX = min(minX, points[i].first);
    maxX = max(maxX, points[i].first);
    minY = min(minY, points[i].second);
    maxY = max(maxY, points[i].second);
  }

  if (maxX - minX > maxY - minY) {
    for (int i = 0; i < 4; ++i) {
      swap(points[i].first, points[i].second);
    }
    swap(maxX, maxY); swap(minX, minY);
  }

  vector<int> ys;
  for (int i = 0; i < 4; ++i) ys.push_back(points[i].second);
  sort(ys.begin(), ys.end());

  // cerr << maxX << " " << minX << " " << maxY << " " << minY << endl;

  int side = maxX - minX;
  vector<int> cand = {ys[0], ys[1], ys[2], ys[3], ys[0] - side, ys[1] - side, ys[2] - side, ys[3] - side};

  long long ans = INFLL;
  for (int c: cand) {
    ans = min(ans, shortest(minX, c, side));
  }

  printf("%lld\n", ans);
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}