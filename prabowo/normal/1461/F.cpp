#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const long long INF = 1e16;

int n;
int a[N];

void print(vector<char> op) {
  printf("%d", a[0]);
  for (int i = 1; i < n; ++i) {
    assert(op[i] == '+' || op[i] == '-' || op[i] == '*');
    printf("%c%d", op[i], a[i]);
  }
  printf("\n");
  exit(0);
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  char s[5];
  scanf("%s", s);
  int len = strlen(s);

  // *+-
  sort(s, s + len);

  if (len == 1) print(vector<char>(n, s[0]));

  if (len == 2) {
    if (s[0] == '+' && s[1] == '-') print(vector<char>(n, '+'));

    if (s[0] == '*' && s[1] == '-') {
      vector<char> op(n, '*');
      for (int i = 0; i < n; ++i) if (a[i] == 0) op[i] = '-';
      print(op);
    }
  }

  // * and +

  vector<char> op(n + 5);
  for (int i = 0, j; i < n; i = j + 1) {
    j = i;
    while (j < n && a[j] != 0) ++j;

    // Solve for [i, j), without 0

    long long mul = 1, frst = -1, lst = -1;
    for (int k = i; k < j; ++k) {
      if (a[k] == 1) continue;
      if (frst == -1) frst = k;
      lst = k;
      if ((mul *= a[k]) > INF) mul = INF;
    }

    if (mul == INF) {
      for (int k = i; k <= frst; ++k) op[k] = '+';
      for (int k = frst + 1; k <= lst; ++k) op[k] = '*';
      for (int k = lst + 1; k <= j; ++k) op[k] = '+';
      continue;
    }

    vector<pair<int, int>> idxs;
    idxs.emplace_back(i - 1, 0);
    for (int k = i; k < j; ++k) {
      if (a[k] > 1) idxs.emplace_back(k, a[k]);
    }
    idxs.emplace_back(j, 0);

    vector<long long> dp(idxs.size(), -1);
    vector<int> pre(idxs.size(), -1);
    dp[0] = 0LL;
    for (int i = 1; i < idxs.size(); ++i) {
      long long mul = 1;
      for (int j = i; j > 0; --j) {
        mul *= idxs[j].second;
        long long t = mul + dp[j - 1] + idxs[j].first - idxs[j - 1].first - 1;
        if (t >= dp[i]) {
          dp[i] = t; pre[i] = j - 1;
        }
      }
    }

    for (int cur = (int) idxs.size() - 1; cur > 0; cur = pre[cur]) {
      for (int k = idxs[pre[cur] + 1].first + 1; k <= idxs[cur].first; ++k) op[k] = '*';
      for (int k = idxs[pre[cur]].first + 1; k <= idxs[pre[cur] + 1].first; ++k) op[k] = '+';
    }
  }

  print(op);
  return 0;
}

// 11
// 2 1 4 1 1 1 1 1 1 1 2
// +*

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}