#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
char s[N], t[N];


int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", t);

  int l = 0, r = n-1;
  bool rev = false;
  vector<int> v;
  for (int i = n-1; i >= 0; --i) {
    if (!rev && s[r] == t[i]) {
      --r;
      continue;
    }

    if (rev && s[l] != t[i]) {
      ++l;
      continue;
    }

    if (!rev) {
      if (s[l] != t[i]) {
        rev = !rev;
        ++l;
        // --r;
        v.push_back(i);
      } else {
        rev = !rev;
        ++l;
        // --r;
        v.push_back(0);
        v.push_back(i);
      }
    } else {
      if (s[r] == t[i]) {
        --r;
        // ++l;
        rev = !rev;
        v.push_back(i);
      } else {
        --r;
        // ++l;
        rev = !rev;
        v.push_back(0);
        v.push_back(i);
      }
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