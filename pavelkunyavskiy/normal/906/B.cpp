#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

using namespace std;

#ifdef LOCAL
static struct __timestamper {
  string what;
  __timestamper(const char* what) : what(what){};
  __timestamper(const string& what) : what(what){};
  ~__timestamper(){
    TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

vector<pair<int, int>> neigh(const vector<vector<int>> &v) {
  vector<pair<int, int>> res;
  int n = (int)v.size();
  int m = (int)v[0].size();
  const int di[] = {0, 1, 0, -1};
  const int dj[] = {1, 0, -1, 0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (0 <= ni && ni < n && 0 <= nj && nj < m) {
          res.push_back({v[i][j], v[ni][nj]});
        }
      }
    }
  }
  for (auto &x : res) {
    if (x.first > x.second) {
      swap(x.first, x.second);
    }
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  return res;
};

void trans(vector<vector<int>> &v, int &n, int &m) {
  swap(n, m);
  vector<vector<int>> nv = vector<vector<int>>(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      nv[i][j] = v[j][i];
    }
  }
  v = nv;
}

bool check(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
  for (auto x : b) {
    if (binary_search(a.begin(), a.end(), x)) {
      return false;
    }
  }
  return true;
}

void solve33(int n, int m) {
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      v[i][j] = i * m + j + 1;
    }
  }
  auto neigh_old = neigh(v);
  vector<int> g(n * m);
  for (int i = 0; i < n * m; i++) {
    g[i] = i + 1;
  }
  do {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        v[i][j] = g[i * m + j];
      }
    }
    vector<pair<int, int>> neigh_new = neigh(v);

    if (check(neigh_new, neigh_old)) {
      printf("YES\n");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          printf("%d ", v[i][j]);
        }
        printf("\n");
      }
      return;
    }
  } while (next_permutation(g.begin(), g.end()));
  printf("NO\n");
}

void solve(int n, int m) {
  if (n <= 3 && m <= 3) {
    solve33(n, m);
    return;
  }

  vector<vector<int>> v(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      v[i][j] = i * m + j + 1;
    }
  }
  vector<pair<int, int>> neigh_old = neigh(v);
  for (int it = 0; it < 2; it++) {
    for (int i = 0; i < n; i += 2) {
      if (n == 1) {
        vector<int> nv(m);
        int ptr = 0;
        for (int j = 1; j < m; j += 2) {
          nv[ptr++] = v[i][j];
        }
        for (int j = 0; j < m; j += 2) {
          nv[ptr++] = v[i][j];
        }
        v[i] = nv;
      } else {
        rotate(v[i].begin(), v[i].begin() + (m + 1) / 2, v[i].end());
      }
    }
    trans(v, n, m);
  }
  vector<pair<int, int>> neigh_new = neigh(v);

  assert(check(neigh_new, neigh_old));

  printf("YES\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", v[i][j]);
    }
    printf("\n");
  }
}

int main() {
#ifdef LOCAL
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    solve(n, m);
    break;
  }

  return 0;
}