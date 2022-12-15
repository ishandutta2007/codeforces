#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, D;
  cin >> N >> D;
  vector<int> P(N);
  for (int &x : P)
    cin >> x;
  sort(P.begin(), P.end());
  int deb = 0;
  int sol = 0;
  for (int i = N - 1; i >= deb; --i) {
    int need = (D + P[i]) / P[i];
    if (need > i - deb + 1)
      break;
    deb += need - 1;
    sol++;
  }
  cout << sol << endl;
}