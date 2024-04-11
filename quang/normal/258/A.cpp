#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char a[N];
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> (a + 1);
  n = strlen(a + 1);
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == '0') {
      pos = i;
      break;
    }
  }
  if (pos) {
    for (int i = 1; i <= n; i++) {
      if (i != pos) {
        cout << a[i];
      }
    }
  } else {
    for (int i = 1; i < n; i++) {
      cout << a[i];
    }
  }
  return 0;
}