#include <bits/stdc++.h>

using namespace std;

char a[200010];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", a);
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '<') {
      res++;
    } else {
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == '>') {
      res++;
    } else {
      break;
    }
  }
  cout << res << endl;
  return 0;
}