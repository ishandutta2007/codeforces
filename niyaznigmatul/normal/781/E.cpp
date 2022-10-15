#include <bits/stdc++.h>

using namespace std;
struct qwe {
  int y;
  int l, r;
  int s;
  int id;
};

struct event {
  bool start;
  int y;
  int id;
};

int const N = 223456;
int const T = 1 << 19;

vector<qwe> tr[2 * T + 5];
qwe z[N];
event ev[2 * N];

void add(vector<qwe> &a, qwe const &z, bool delta) {
  if (delta) {
    while (a.size() > 0 && a.back().y + a.back().s <= z.y + z.s) a.pop_back();
    a.push_back(z);
  } else {
    if (!a.empty() && a.back().id == z.id) a.pop_back();
  }
}

void make(int left, int right, qwe const &z, bool delta) {
  left += T;
  right += T;
  --right;
  while (left <= right) {
    if ((left & 1) == 1) {
      add(tr[left++], z, delta);
    }
    if ((right & 1) == 0) {
      add(tr[right--], z, delta);
    }
    left >>= 1;
    right >>= 1;
  }
}

int get(int x) {
  x += T;
  int have = -1;
  while (x > 0) {
    if (!tr[x].empty()) {
      int cur = tr[x].back().id;
      if (have < 0 || z[have].y < z[cur].y) have = cur;
    }
    x >>= 1;
  }
  return have;
}

int const MOD = 1000000007;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int ans[N];

int main() {
  int h, w, n;
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 0; i < n; i++) {
    int y, l, r, s;
    scanf("%d%d%d%d", &y, &l, &r, &s);
    --l;
    z[i] = {y, l, r, s, i};
  }
  int cn = 0;
  for (int i = 0; i < n; i++) {
    ev[cn++] = {true, z[i].y, i};
    if (z[i].y + z[i].s <= h) {
      ev[cn++] = {false, z[i].y + z[i].s, i};
    }
  }
  sort(ev, ev + cn, [](event const &a, event const &b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.start == b.start) return false;
    return a.start;
  });
  for (int i = 0; i < cn; i++) {
    event &e = ev[i];
    qwe &f = z[e.id];
    if (e.start) {
      int first, second;
      if (f.l > 0 && f.r < w) {
        first = f.l - 1;
        second = f.r;
      } else if (f.l == 0) {
        first = second = f.r;
      } else {
        first = second = f.l - 1;
      }
      int to1 = get(first);
      int to2 = get(second);
      ans[f.id] = to1 < 0 ? 1 : ans[to1];
      add(ans[f.id], to2 < 0 ? 1 : ans[to2]);
      make(f.l, f.r, f, true);
    } else {
      make(f.l, f.r, f, false);
    }
  }
  int answer = 0;
  for (int i = 0; i < w; i++) {
    int to = get(i);
    add(answer, to < 0 ? 1 : ans[to]);
  }
  printf("%d\n", answer);
}