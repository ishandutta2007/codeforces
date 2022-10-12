#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
char s[N], t[N];

void rev(int x) {
  for (int i = 0; i <= x; ++i) {
    if (s[i] == '0') s[i] = '1';
    else s[i] = '0';
  }
  reverse(s, s + x + 1);
}

int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", t);

  vector<int> v;
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == t[i]) continue;
    if (s[0] != t[i]) {
      rev(i);
      v.push_back(i);
    } else {
      rev(0);
      rev(i);
      v.push_back(0);
      v.push_back(i);
    }
  }

  printf("%d", (int) v.size());
  for (int u: v) printf(" %d", u+1);
  printf("\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}