#include <bits/stdc++.h>

using namespace std;

struct man {
  string name;
  int team;
  int points;
};

int const N = 123456;
vector<man> a[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    string s;
    int c = getchar();
    while (c <= 32) c = getchar();
    while (c > 32) {
      s += (char) c;
      c = getchar();
    }
    int x, y;
    scanf("%d%d", &x, &y);
    a[x].push_back({s, x, y});
  }
  for (int i = 1; i <= m; i++) {
    int mx = -1;
    int mx2 = -1;
    for (size_t j = 0; j < a[i].size(); j++) {
      if (mx < 0 || (a[i][j].points > a[i][mx].points)) {
        mx2 = mx;
        mx = (int) j;
      } else if (mx2 < 0 || (a[i][j].points > a[i][mx2].points)) {
        mx2 = (int) j;
      }
    }
    int p = a[i][mx2].points;
    int cn = 0;
    for (size_t j = 0; j < a[i].size(); j++) {
      if (a[i][j].points >= p) {
        ++cn;
      }
    }
    if (cn > 2) {
      puts("?");
    } else {
      printf("%s %s\n", a[i][mx].name.c_str(), a[i][mx2].name.c_str());
    }
  }
}