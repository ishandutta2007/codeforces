#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
long long sum[N];
long long initRes = 0, maxDelta = 0;

struct convexHullForward {
  long long a[N], b[N];
  long double c[N];
  int top;

  convexHullForward() {
    top = 0;
  }

  void add(long long A, long long B) {
    long double cross = -1e18;
    while (top) {
      cross = (long double) (B - b[top - 1]) / (long double) (a[top - 1] - A);
      if (cross <= c[top - 1]) {
        top--;
      } else {
        break;
      }
    }
    a[top] = A, b[top] = B, c[top] = cross;
    top++;
  }

  long long get(int u) {
    int pos = lower_bound(c, c + top + 1, (long double)u) - c - 1;
    return a[pos] * u + b[pos];
  }
} hForward;

struct convexHullBackward {
  long long a[N], b[N];
  long double c[N];
  int top;

  convexHullBackward (){
    top = N - 1;
  }

  void add(long long A, long long B) {
    long double cross = 1e18;
    while (top < N - 1) {
      cross = (long double) (B - b[top + 1]) / (long double) (a[top + 1] - A);
      if (cross >= c[top + 1]) {
        top++;
      } else {
        break;
      }
    }
    a[top] = A, b[top] = B, c[top] = cross;
    top--;
  }

  long long get(int u) {
    int pos = lower_bound(c + top + 1, c + N, (long double)u) - c;
    return a[pos] * u + b[pos];
  }
} hBackward;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    initRes += 1ll * a[i] * i;
    sum[i] = sum[i - 1] + a[i];
  }
  //push forward
  for (int i = 1; i <= n; i++) {
    if (i > 1) {
      long long foo = hForward.get(a[i]);
      foo += -1ll * a[i] * i + sum[i - 1];
      maxDelta = max(maxDelta, foo);
    }
    hForward.add(i, -sum[i - 1]);
  }
  //push backward
  for (int i = n; i; i--) {
    if (i < n) {
      long long foo = hBackward.get(a[i]);
      foo += sum[i] - 1ll * a[i] * i;
      maxDelta = max(maxDelta, foo);
    }
    hBackward.add(i, -sum[i]);
  }
  cout << initRes + maxDelta << endl;
  return 0;
}