#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  int lo = 1, up = 1e18;
  while (lo < up) {
    int mid = (lo + up) / 2;
    int bef = 0;

    bef += (mid - 1) / 2;
    bef += max(0LL, (mid - 4) / 4);
    if (bef < N)
      lo = mid + 1;
    else
      up = mid;
  }
  cout << lo << endl;
}