#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int cnt[N];

int two, four, six, eight;
void add(int x, int t=0) {
  int val = (t == 0 ? 1 : -1);
  cnt[x] += val;

  if (cnt[x] == 8 + t) {
    eight += val;
  }

  if (cnt[x] == 6 + t) {
    six += val;
  }

  if (cnt[x] == 4 + t) {
    four += val;
  }

  if (cnt[x] == 2 + t) {
    two += val;
  }
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int l;
    scanf("%d", &l);
    add(l);
  }

  scanf("%d", &m);
  while (m--) {
    char c;
    int l;
    getchar();
    scanf("%c %d", &c, &l);
    if (c == '+') add(l);
    else add(l, -1);

    int eight = ::eight;
    int six = ::six - eight;
    int four = ::four - six - eight;
    int two = ::two - four - six - eight;

    if (eight > 0) printf("YES\n");
    else if (six >= 2) printf("YES\n");
    else if (six == 1 && (four > 0 || two > 0)) printf("YES\n");
    else if (four >= 2) printf("YES\n");
    else if (four == 1 && two >= 2) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}