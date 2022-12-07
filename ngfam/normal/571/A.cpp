#include <bits/stdc++.h>
#define int long long


using namespace std;

const int mod = 1e9 + 7;

int C(int n, int k) {
  int ret = 1;
  for(int i = n; i > n - k; --i) {
    ret *= i;
  }
  for(int i = 1; i <= k; ++i) {
    ret /= i;
  }
  return ret;
}

main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int sum = 0;

  int d;
  vector < int > vec(3);
  for(auto &x : vec) cin >> x, sum += x;
  cin >> d;

  int all = C(d + 3, 3);

  for(int i = 0; i < 3; ++i) {
    for(int v = 0; v <= d; ++v) {
      int lim = vec[i] + v;
      if(sum - vec[i] > lim) continue;
      int rem = min(d - v, lim - (sum - vec[i]));
      all -= C(rem + 2, 2);
    }
  }

  cout << all;

  return 0;
}