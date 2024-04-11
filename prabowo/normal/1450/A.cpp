#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 1e9;

int n, m;
char s[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  sort(s, s + n);
  printf("%s\n", s);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}