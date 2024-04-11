#include <iostream>
#include <stdio.h>

using namespace std;

int n, m;
int err = 0;

int abs(int x) {
  return x < 0 ? -x : x;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int ls_x = -1, ls_h = -1;
  int ans = 0;
  for(int i = 0;i < m;i++) {
    int x, h;
    cin >> x >> h;
    if(ls_x == -1) {
      ans = max(ans, h + x - 1);
    }else {
      int dif_x = x - ls_x;
      int dif_h = abs(h - ls_h);
      if(dif_h > dif_x) {
        err = 1;
      }else {
        ans = max(ans, max(h, ls_h) + (dif_x - dif_h) / 2);
      }
    }
    ls_x = x;
    ls_h = h;
  }
  ans = max(ans, ls_h + n - ls_x);
  if(err) {
    cout << "IMPOSSIBLE" << endl;
  }else {
    cout << ans << endl;
  }
  return 0;
}