#include <bits/stdc++.h>

using namespace std;

const int N = 310;

int n, k;
int a[N][N];
double res[N];

struct line {
  double a, b;
  line(double a = 0, double b = 0) {
    this->a = a;
    this->b = b;
  }
};

struct ConvexHull {
  double a[N], b[N], c[N];
  int top;

  ConvexHull() {
    top = 0;
  }

  void add(line u) {
    double cross = 0.;
    while (top) {
      if (a[top] == u.a) {
        if (b[top] >= u.b) {
          return;
        }
        top--;
      } else {
        cross = (u.b - b[top]) / (a[top] - u.a);
        if (cross <= c[top]) {
          top--;
        } else {
          break;
        }
      }
    }
    if (cross > 1.) {
      return;
    }
    top++;
    a[top] = u.a;
    b[top] = u.b;
    c[top] = max(cross, 0.);
  }

  double area() {
    double res = 0;
    c[top + 1] = 1.;
    for (int i = 1; i <= top; i++) {
      double dis = c[i + 1] - c[i];
      double h1 = a[i] * c[i] + b[i];
      double h2 = a[i] * c[i + 1] + b[i];
      res += (h1 + h2) * dis;
    }
    return res / 2.;
  }
};

line b[N];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 0; i < k; i++) {
    int top = 1;
    b[1] = line(0, 0);
    double old = 0.;
    for (int id = 1; id <= n; id++) {
      int dis = a[id][i + 1] - a[id][i];
      line foo = line(dis, a[id][i]);
      b[++top] = foo;
      for (int j = top; j > 1; j--) {
        if (b[j].a < b[j - 1].a) {
          swap(b[j], b[j - 1]);
        } else {
          break;
        }
      }
      ConvexHull h;
      for (int j = 1; j <= top; j++) {
        h.add(b[j]);
      }
      double area = h.area();
      res[id] += area - old;
      old = area;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%0.17f\n", res[i]);
  }
  return 0;
}