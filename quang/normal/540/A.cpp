#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

int n;
char a[N], b[N];

int main() {
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  int res = 0;
  for (int i = 0 ; i < n; i++) {
    int x = a[i] - '0';
    int y = b[i] - '0';
    if (x > y) {
      swap(x, y);
    }
    res += min(y - x, 10 - y + x);
  }
  cout << res << endl;
}