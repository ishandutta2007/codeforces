#include <bits/stdc++.h>
using namespace std;

const int N = 303;

int n;
char ans[N];

int guess(string s) {
  cout << s << endl;
  int ret;
  scanf("%d", &ret);

  if (ret == 0) exit(0);

  return ret;
}

int guessA(int l, int r) {
  string s;
  for (int i = 1; i < l; ++i) {
    if (ans[i]) s += ans[i];
    else s += 'a';
  }

  for (int i = l; i <= r; ++i) {
    if (ans[i]) s += ans[i];
    else s += 'b';
  }

  for (int i = r+1; i <= n; ++i) {
    if (ans[i]) s += ans[i];
    else s += 'a';
  }

  return guess(s);
}

// banyaknya B = banyaknya B_L + banyaknya B_R
// banyaknya A_L + banyaknya B_R = (mid-l+1) - banyaknya B_L + banyaknya B_R


void solve(int l, int r, int ignore, int wrong) {
  if (l == r) {
    if (wrong) {
      ans[l] = 'b';
    } else {
      ans[l] = 'a';
    }

    return;
  }

  int mid = l + r >> 1;

  int lft = guessA(l, mid);

  int wrongL = wrong - (lft-ignore) + (mid-l+1) >> 1;
  int wrongR = wrong - wrongL;

  solve(l, mid, ignore + wrongR, wrongL);
  solve(mid+1, r, ignore, wrongR);
}

int main() {
  n = guess("a") + 1;

  if (n > 300) {
    string s;
    for (int i = 0; i < 300; ++i) s += 'b';
    guess(s);
  }

  string s; int B = 0;
  for (int i = 0; i < n; ++i) s += 'a';
  B = guess(s);

  if (B >= n) {
    s = "";
    for (int i = 1; i < n; ++i) s += 'b';
    guess(s);
  }
  solve(1, n, 0, B);

  guessA(1, n);
  return 0;
}