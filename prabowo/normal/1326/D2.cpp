#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n;
char s[N];

// From cp algorithms

int d1[N];
void oddPalindromes(int n, char s[]) {
  for (int i = 0; i < n; ++i) d1[i] = 1;
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
}

int d2[N];
void evenPalindromes(int n, char s[]) {
  for (int i = 0; i < n; ++i) d2[i] = 0;
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k ;
    }
  }
}

bool isPalin(int l, int r) {
  if (r - l & 1) {
    int mid = (r + l) / 2 + 1;

    if (d2[mid] * 2 >= r-l+1) return true;
    return false;
  }

  int mid = (r + l) / 2;

  if (d1[mid]*2 - 1 >= r-l+1) return true;
  return false;
}

int longL[N];
void longestPalinLeft() {
  // cerr << "CHECKR ";
  int mid;
  if (n & 1) {
    mid = n/2;
    longL[mid] = mid;
  } else {
    mid = n/2 - 1;
    longL[mid] = mid + (s[mid] == s[mid+1]);
  }
  // cerr << r << " ";

  for (int i = mid-1; i >= 0; --i) {
    int r = min(n-i-1, longL[i+1] + 5);
    while (!isPalin(i, r)) --r;
    // cerr << r << " ";

    longL[i] = r;
  }

  // cerr << endl;
}

int longR[N];
void longestPalinRight() {
  // cerr << "CHECKR ";
  int mid;
  if (n & 1) {
    mid = n/2;
    longR[mid] = mid;
  } else {
    mid = n/2;
    longR[mid] = mid - (s[mid] == s[mid-1]);
  }

  // cerr << l << " ";

  for (int i = mid+1; i < n; ++i) {
    int l = max(n-i-1, longR[i-1] - 5);
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

  oddPalindromes(n, s); evenPalindromes(n, s);

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