#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int sol(0);
  for (int flip(0); flip < 2; ++flip) {
    for (int l(0); l < n; ++l) {
      int bit(31);
      while (!((1 << bit) & arr[l]))
        bit--;
      int sum = 0;
      for (int i(l + 1); i < n - 1; ++i) {
        sum += arr[i];
        if (sum >= 2 * (1 << bit))
          break;
        if (sum == (arr[l] ^ arr[i + 1]) and arr[i + 1] < arr[l])
          sol++;
      }
    }
    reverse(arr.begin(), arr.end());
  }
  cout << sol << endl;
}