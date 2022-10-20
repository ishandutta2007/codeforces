#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
int a[N];
bool x[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1 || i == n) {
      x[i] = 1;
    } else {
      x[i] = ((a[i] == a[i - 1]) || (a[i] == a[i + 1]));
    }
  }
  int res = 0;
  int last = 1;
  for (int i = 2; i <= n; i++) {
    if (x[i]) {
      res = max(res, (i - last) / 2);
      last =  i;
    }
  }
  cout << res << endl;
  last = 1;
  cout << a[1] << " ";
  for (int i = 2; i <= n; i++) {
    if (x[i]) {
      int cnt = i - last - 1;
      if (cnt % 2) {
        for (int j = last + 1; j <= i; j++) {
          cout << a[i] << " ";
        }
      } else{
        cnt /= 2;
        for (int j = last + 1; j <= last + cnt; j++) {
          cout << a[last] << " ";
        }
        for (int j = last + cnt + 1; j <= i; j++) {
          cout << a[i] << " ";
        }
      }
      last = i;
    }
  }
  return 0;

}