#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n;
char s[N];

int memo[5005][5005];
bool isPalin(int l, int r) {
  if (l > r) return true;
  if (memo[l][r] != -1) return memo[l][r];
  if (s[l] == s[r]) return memo[l][r] = isPalin(l+1, r-1);
  return memo[l][r] = 0;
}

int longL[N];
void longestPalinLeft() {
  // cerr << "CHECKR ";

  // cerr << r << " ";

  for (int i = 0; i < n; ++i) {
    int r = n-i-1;
    if (r < i) break;
    while (!isPalin(i, r)) --r;
    // cerr << r << " ";

    longL[i] = r;
  }

  // cerr << endl;
}

int longR[N];
void longestPalinRight() {
  // cerr << "CHECKR ";

  // cerr << l << " ";

  for (int i = n-1; i >= 0; --i) {
    int l = n-i-1;
    if (l > i) break;
    while (!isPalin(l, i)) ++l;

    // cerr << l << " ";
    longR[i] = l;
  }

  // cerr << endl;
}


int idx, ans;
void comp(int l, int r) {
  if (l + longL[l] + 1 > ans) {
    ans = l + longL[l] + 1;
    idx = l;
  }

  if (l + (n - longR[r]) > ans) {
    ans = l + (n - longR[r]);
    idx = l;
  }
}

int solve() {
  scanf("%s", s);
  n = strlen(s);

  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) memo[i][j] = -1;
    longestPalinLeft(); longestPalinRight();

  idx = -1;
  ans = 0;
  comp(0, n-1);

  for (int l = 0, r = n-1; l < r; ++l, --r) {
    if (s[l] != s[r]) break;
    if (l+1 <= r-1) comp(l+1, r-1);
    else {
      if ((l+1)*2 > ans) {
        ans = (l+1) * 2;
        idx = l;
      }
    }
  }

  // cerr << idx << endl;
  for (int i = 0; i < idx; ++i) {
    printf("%c", s[i]);
  }

  // cerr << "|";

  int ridx = n - idx - 1;
  if (idx <= ridx) {
    if (idx + longL[idx] + 1 > idx + (n - longR[ridx])) {
      // cerr <<"L";
      for (int i = idx; i <= longL[idx]; ++i) printf("%c", s[i]);
    } else {
      // cerr << "R";
      for (int i = longR[ridx]; i <= ridx; ++i) printf("%c", s[i]);
    }
  }

  // cerr << "|";

  for (int i = ridx + 1; i < n; ++i) {
    printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}