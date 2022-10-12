#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int A = 20;

int n, a, b;
char s[N];
int L[A], R[A], cnt[A];
char iconvert[A];

int dp[1 << A];
int f(int mask) {
  if (mask == 0) return 1;
  if (~dp[mask]) return dp[mask];

  int l = n, r = -1, cum = 0;
  for (int i = 0; i < A; ++i) {
    if (mask >> i & 1); else continue;

    if (l < n && f(mask & ((1 << i) - 1)) && f(mask & ~((1 << i) - 1))) {
      return dp[mask] = 1;
    }

    l = min(l, L[i]);
    r = max(r, R[i]);
    cum += cnt[i];
  }

  if (a * (r - l + 1) <= b * cum) for (int i = 0; i < A; ++i) {
    if (mask >> i & 1); else continue;

    if (f(mask ^ (1 << i))) return dp[mask] = 1;
  }

  return dp[mask] = 0;
}

int main() {
  scanf("%d %d %d", &n, &a, &b);
  scanf("%s", s);

  map<char, int> convert;
  for (int i = 0; i < n; ++i) {
    int converted = -1;
    if (convert.find(s[i]) == convert.end()) {
      converted = convert.size();
      L[converted] = i;
      iconvert[converted] = s[i];
      convert[s[i]] = converted;
    } else {
      converted = convert[s[i]];
    }
    ++cnt[converted];
    R[converted] = i;
  }

  memset(dp, -1, sizeof dp);
  vector<char> ans;
  for (int i = 0; i < convert.size(); ++i) {
    if (f((1 << convert.size()) - 1 ^ (1 << i))) ans.push_back(iconvert[i]);
  }

  sort(ans.begin(), ans.end());
  printf("%d", (int) ans.size());
  for (int c : ans) printf(" %c", c);
  printf("\n");
  return 0;
}