#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll LINF = 1e18;
const int N = 1e5 + 123;

struct Point {
  ll x, y;
  
  Point() {}
  
  Point(ll x, ll y) : x(x), y(y) {}
};

bool cmp_x(const Point &a, const Point &b) {
  return a.x < b.x;
}

bool cmp_y(const Point &a, const Point &b) {
  return a.y < b.y;
}

ll dist2(const Point &a, const Point &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point p[N];
Point temp[N];

ll best = LINF;
Point best_a, best_b;

void upd(const Point &a, const Point &b) {
  if (dist2(a, b) < best) {
    best = dist2(a, b);
    best_a = a;
    best_b = b;
  }
}

void nearest(int l, int r) {
  if (l == r - 1) {
    return;
  }
  
  int m = (l + r) / 2;
  ll X = p[m].x;
  nearest(l, m);
  nearest(m, r);
  
  merge(p + l, p + m, p + m, p + r, temp + l, cmp_y);
  copy(temp + l, temp + r, p + l);
  
  int ptr = 0;
  for (int i = l; i < r; i++) {
    if ((p[i].x - X) * (p[i].x - X) <= best) {
      temp[ptr++] = p[i];
    }
  }
  
  for (int i = 0; i < ptr; i++) {
    for (int j = i + 1; j < min(i + 8, ptr); j++) {
      upd(temp[i], temp[j]);
    }
  }
}

int n;
Point q[N];

int to_pos(const Point &a) {
  if (a.x > 0 && a.y > 0) {
    return 1;
  } else if (a.x < 0 && a.y > 0) {
    return 2;
  } else if (a.x > 0 && a.y < 0) {
    return 3;
  } else {
    return 4;
  }
}

int to_neg(const Point &a) {
  if (a.x > 0 && a.y > 0) {
    return 4;
  } else if (a.x < 0 && a.y > 0) {
    return 3;
  } else if (a.x > 0 && a.y < 0) {
    return 2;
  } else {
    return 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> q[i].x >> q[i].y;
    p[i].x = abs(q[i].x);
    p[i].y = abs(q[i].y);
  }
  
  sort(p, p + n, cmp_x);
  nearest(0, n);
  
  int u, k1, v, k2;
  
  for (int i = 0; i < n; i++) {
    if (abs(best_a.x) == abs(q[i].x) && abs(best_a.y) == abs(q[i].y)) {
      u = i;
      k1 = to_pos(q[i]);
    }
  }
  
  for (int i = 0; i < n; i++) {
    if (i == u) {
      continue;
    }
    
    if (abs(best_b.x) == abs(q[i].x) && abs(best_b.y) == abs(q[i].y)) {
      v = i;
      k2 = to_neg(q[i]);
    }
  }
    
  u++; v++;
  cout << u << " " << k1 << " " << v << " " << k2 << "\n";
  
  return 0;
}