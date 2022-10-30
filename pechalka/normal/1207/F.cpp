#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

const int K = 720;
const int MAXN = 500000;

int ans[K][K];
int a[MAXN];

int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i){
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1){
      for (int mod = 1; mod <= K; ++mod)
        ans[mod - 1][x % mod] += y;
      a[x - 1] += y;
    } else {
      if (x <= K)
        cout << ans[x - 1][y] << '\n';
      else {
        int res = 0;
        if (y > 0)
          res += a[y - 1];
        for (int i = x + y; i <= MAXN; i += x)
          res += a[i - 1];
        cout << res << '\n';
      }
    }
  }
  return 0;
}