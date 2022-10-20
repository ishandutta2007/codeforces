#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef pair<long long, long long> pi;

int n, m;
int a[N];
long long sum[N], res[N];
vector <pi> b[N * 4];

struct query {
  int x, y, id;
  query() {};
  query(int x, int y, int id) {
    this->x = x;
    this->y = y;
    this->id = id;
  }
} q[N];

bool cmp(query u, query v) {
  return u.x - u.y < v.x - v.y;
}

struct convexhull {
  vector <long long> A, B;
  vector <double> C;
  int top;

  convexhull () {
    A.clear(), B.clear(), C.clear();
    top = 0;
  }

  double inter(pi u, pi v) {
    return (1.0 * u.second - v.second) / (1.0 * v.first - u.first);
  }

  void add(const vector <pi> &u) {
    for (int i = 0; i < u.size(); i++) {
      while(!A.empty()) {
        if (u[i].first == A.back()) {
          A.pop_back();
          B.pop_back();
          C.pop_back();
          continue;
        }
        double x = inter(u[i], pi(A.back(), B.back()));
        if (x <= C.back()) {
          A.pop_back();
          B.pop_back();
          C.pop_back();
          continue;
        }
        break;
      }
      if (A.empty()) {
        A.push_back(u[i].first);
        B.push_back(u[i].second);
        C.push_back(-1e15);
      } else {
        C.push_back(inter(u[i], pi(A.back(), B.back())));
        A.push_back(u[i].first);
        B.push_back(u[i].second);
      }
    }
  }

  long long get(long long pos) {
    int f = top + 1;
    while (f < C.size()) {
      if (C[f] > pos) {
        break;
      }
      f++;
    }
    top = f - 1;
    return A[top] * pos + B[top];
  }
} t[N * 4];

vector <pi> mergesort(const vector <pi> &u, const vector <pi> & v) {
  vector <pi> res;
  int curu = 0, curv = 0;
  while (curu < u.size() || curv < v.size()) {
    if (curu >= u.size()) {
      res.push_back(v[curv++]);
      continue;
    }
    if(curv >= v.size()) {
      res.push_back(u[curu++]);
      continue;
    }
    if (u[curu] > v[curv]) {
      res.push_back(u[curu++]);
    } else {
      res.push_back(v[curv++]);
    }
  }
  return res;
}

void build(int node, int l, int r) {
  if (l == r) {
    b[node].push_back(make_pair(a[l], 1ll * a[l] * l - sum[l]));
    t[node].add(b[node]);
    return;
  }
  int m = (l + r) >> 1;
  build(node * 2, l, m);
  build(node * 2 + 1, m + 1, r);
  b[node] = mergesort(b[node + node], b[node + node + 1]);
  t[node].add(b[node]);
}

long long get(int node, int l, int r, int x, int y, int pos) {
  if (x > r || y < l) {
    return (1ll << 60);
  }
  if (x <= l && r <= y) {
    return t[node].get(pos);
  }
  int m = (l + r) >> 1;
  long long p1 = get(node + node, l, m, x, y, pos);
  long long p2 = get(node + node + 1, m + 1, r, x, y, pos);
  return min(p1, p2);
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> q[i].x >> q[i].y;
    q[i].id = i;
  }
  sort(q + 1, q + m + 1, cmp);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int x = q[i].x;
    int y = q[i].y;
    int l0 = y - x + 1;
    long long ans = sum[y] + get(1, 1, n, l0, y, x - y);
    res[q[i].id] = ans;
  }
  for (int i = 1; i <= m; i++) {
    cout << res[i] << endl;
  }
  return 0;
}