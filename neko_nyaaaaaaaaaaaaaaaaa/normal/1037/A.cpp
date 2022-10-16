#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      srand(time(NULL));

      int n; cin >> n;
      int k = log2(n);
      k++;
      cout << k;

      return 0;
}