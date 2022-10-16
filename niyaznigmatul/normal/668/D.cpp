#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;
int read() {
  int c = getchar();
  while (c <= 32) c = getchar();
  int x = 0;
  while (c > 32) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}

int f[N];

int z[N];

struct event {
  int time;
  int type;
  int x;
  int id;
};

void add(int x, int y) {
  for (int i = x; i < N; i |= i + 1) {
    f[i] += y;
  }
}

int get(int x) {
  int ret = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
    ret += f[i];
  }
  return ret;
}

event events[N];
int ans[N];

int main() {
  int n = read();
  for (int i = 0; i < n; i++) {
    int type = read();
    int tm = read();
    int x = read();
    events[i] = {tm, type, x, i};
    z[i] = tm;
  }
  sort(events, events + n, [](event const &a, event const &b) {
    return a.x < b.x;
  });
  sort(z, z + n);
  for (int i = 0; i < n; i++) ans[i] = -1;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && events[i].x == events[j].x) {
      ++j;
    }
    sort(events + i, events + j, [](event const &a, event const &b) {
      return a.time < b.time;
    });
    for (int k = i; k < j; k++) {
      auto &e = events[k];
      if (e.type == 1) {
        add(e.id, 1);
      } else if (e.type == 2) {
        add(e.id, -1);
      } else {
        ans[e.id] = get(e.id);
      }
    }
    for (int k = i; k < j; k++) {
      auto &e = events[k];
      if (e.type == 1) {
        add(e.id, -1);
      } else if (e.type == 2) {
        add(e.id, 1);
      }
    }
    i = j;
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] >= 0) printf("%d\n", ans[i]);
  }
}