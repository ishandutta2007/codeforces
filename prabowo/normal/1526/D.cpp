#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
char s[N];
int a[N];
int ans[N];

int solve() {
  scanf("%s", s);
  n = strlen(s);
  vector<int> cnt(4, 0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') a[i] = 0;
    else if (s[i] == 'N') a[i] = 1;
    else if (s[i] == 'T') a[i] = 2;
    else if (s[i] == 'O') a[i] = 3;
    ++cnt[a[i]];
  }

  vector<int> perm = {0, 1, 2, 3};
  long long ans = -1;
  vector<int> pans;
  do {
    // int pos[4];
    // for (int i = 0; i < 4; ++i) {
    //   if (i == 0) pos[perm[i]] = 0;
    //   else pos[perm[i]] = pos[perm[i - 1]] + cnt[perm[i - 1]];
    // }
    // long long res = 0;
    // for (int i = 0; i < n; ++i) {
    //   res += abs(pos[a[i]]++ - i);
    // }

    long long inv = 0;
    int cnt[4] = {0, 0, 0, 0};
    for (int i = 0; i < n; ++i) {
      inv += cnt[perm[a[i]]];
      for (int j = 0; j < perm[a[i]]; ++j) ++cnt[j];
    }

    if (ans == -1 || inv > ans) {
      ans = inv;
      pans = perm;
    }
  } while (next_permutation(perm.begin(), perm.end()));

  // cerr << ans << endl;

  int pos = 0;
  for (int i = 0; i < 4; ++i) {
    int c;
    for (int j = 0; j < 4; ++j) if (pans[j] == i) c = j;
    for (int j = 0; j < cnt[c]; ++j) {
      if (c == 0) printf("A");
      else if (c == 1) printf("N");
      else if (c == 2) printf("T");
      else if (c == 3) printf("O");
    }
  }

  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}