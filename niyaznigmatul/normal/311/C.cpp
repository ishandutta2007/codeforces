#include <cstdio>
#include <cassert>
#include <algorithm>
#include <set>

const long long INF = 1LL << 60;
using namespace std;

long long dist[111111], aid[1111111];
int ci[1111111];

long long z[123213];

int main() {
  long long h;
  int n, m, k;
  scanf("%I64d%d%d%d", &h, &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%I64d %d", aid + i, ci + i);
    --aid[i];
  }
  int cn = 0;
  set<pair<int, int> > sa;
  for (int i = 0; i < k; i++) dist[i] = INF;
  dist[0] = 0;
  for (int i = 0; i < n; i++) {
    if (aid[i] % k == 0 && ci[i] != 0) {
      sa.insert(make_pair(ci[i], -i));
    }
  }
  for (int it = 0; it < m; it++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      long long x;
      scanf("%I64d", &x);
      z[cn++] = x;
      set<pair<long long, int> > q;
      q.insert(make_pair(0, 0));
      for (int i = 0; i < k; i++) dist[i] = INF;
      dist[0] = 0;
      while (!q.empty()) {
        pair<long long, int> pv = *(q.begin());
        assert(pv.first == dist[pv.second]);
        q.erase(q.begin());
        for (int i = 0; i < cn; i++) {
          int md = (pv.second + z[i]) % k;
          long long nd = pv.first + z[i];
          if (nd >= INF) nd = INF;
          if (nd < dist[md]) {
            q.erase(make_pair(dist[md], md));
            dist[md] = nd;
            q.insert(make_pair(dist[md], md));
          }
        }
      }
      sa.clear();
      for (int i = 0; i < n; i++) {
        if (ci[i] == 0) continue;
        if (dist[aid[i] % k] <= aid[i]) {
          sa.insert(make_pair(ci[i], -i));
        }
      }
    } else if (t == 2) {
      int x, y;
      scanf("%d%d", &x, &y);
      --x;
      sa.erase(make_pair(ci[x], -x));
      ci[x] -= y;
      if (dist[aid[x] % k] <= aid[x] && ci[x] > 0) {
          sa.insert(make_pair(ci[x], -x));
      }
    } else {
      if (sa.empty()) {
        puts("0");
      } else {
        pair<int, int> fd = *(sa.rbegin());
        printf("%d\n", fd.first);
        assert(fd.first == ci[-fd.second]);
        sa.erase(fd);
        ci[-fd.second] = 0;
      }
    }
  }
}