#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct road {
  int a, b, c, id;

  void read(int u) {
    scanf("%d %d %d", &a, &b, &c);
    id = u;
  }
};

int n, k;
vector <pair<int, int> > res;

long long hd(const road &x, const road &y, const road &z) {
  return 1ll * x.a * y.b * z.c + 1ll * x.c * y.a * z.b + 1ll * x.b * y.c * z.a;
}

void go(const vector<road> &u, int k) {
  int n = u.size();
  if (n <= k) {
    for (int i = 0; i < n; i++) {
      res.push_back(make_pair(u[i].id, -1));
    }
    cout << "YES\n" << res.size() << endl;
    for (auto x : res) {
      cout << x.first << " " << x.second << endl;
    }
    exit(0);
  }
  if (!k) {
    return;
  }
  for (int cnt = 1; cnt <= k * k; cnt++) {
    int x = rand() % n;
    int y = rand() % (n - 1);
    x += (x == y);
    if (1ll * u[x].a * u[y].b == 1ll * u[x].b * u[y].a) {
       continue;
    }
    vector <road> now;
    for (int i = 0; i < n; i++) {
      if (hd(u[x], u[y], u[i]) != hd(u[x], u[i], u[y])) {
        now.push_back(u[i]);
      }
    }
    if (now.size() > n - n / (k + k)) {
      continue;
    }
    res.push_back(make_pair(u[x].id, u[y].id));
    go(now, k - 1);
    res.pop_back();
  }
}

int main() {
  srand(time(0));
  scanf("%d %d", &n, &k);
  vector <road> a(n);
  for (int i = 0; i < n; i++) {
    a[i].read(i + 1);
  }
  go(a, k);
  puts("NO");
  return 0;
}