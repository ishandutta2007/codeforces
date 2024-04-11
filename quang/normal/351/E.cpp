#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      a[i] *= -1;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = 0;
    for (int j = 1; j < i; j++) {
      if (a[j] < a[i]) {
        l++;
      }
    }
    for (int j = i + 1; j <= n; j++) {
      if (a[j] < a[i]) {
        r++;
      }
    }
    res += min(l, r);
  }
  cout << res << endl;
  return 0;
}