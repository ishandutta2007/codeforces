#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, b, k, c;
long long res = (1ll << 60);
int t[N];
priority_queue<long long> s;
long long sum;

void go(int u) {
  while (!s.empty()) {
    s.pop();
  }
  sum = 0;
  for (int i = 1; i <= n; i++) {
    int x = (t[i] - u) / 5;
    int y = (t[i] - u) % 5;
    if (y) {
      x++;
      y = 5 - y;
    }
    long long now = -1ll * b * x + c * y;
    if ((int)s.size() < k) {
      s.push(now);
      sum += now;
    } else {
      long long foo = s.top();
      if (foo > now) {
        sum -= foo;
        s.pop();
        sum += now;
        s.push(now);
      }
    }
    if ((int)s.size() == k) {
      res = min(res, 1ll * b * k * x + sum);
    }
  }
}

long long tot[N];

int main() {
  scanf("%d %d %d %d", &n, &k, &b, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", t + i);
    t[i] += 1e9 + 10;
  }
  sort(t + 1, t + n + 1);
  if (c * 5 <= b) {
    for (int i = 1; i <= n; i++) {
      tot[i] = tot[i - 1] + t[i];
    }
    for (int i = k; i <= n; i++) {
      res = min(res, 1ll * c * (1ll * k * t[i] - (tot[i] - tot[i - k])));
    }
  } else {
    for (int i = 0; i < 5; i++) {
      go(i);
    }
  }
  cout << res << endl;
  return 0;
}