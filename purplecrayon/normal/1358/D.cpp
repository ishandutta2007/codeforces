#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

signed main() {
  int n, len;
  cin >> n >> len;
  vector<int> A(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[n + i] = A[i];
  }
  n *= 2;
  
  vector<int> B = {0}, C = {0};
  for (int i = 0; i < n; i++) 
    B.push_back(B.back() + A[i]);
  for (int i = 0; i < n; i++) 
    C.push_back(C.back() + (A[i] * (A[i] + 1)) / 2);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (B[i + 1] >= len) {
      int z = upper_bound(B.begin(), B.end(), B[i + 1] - len) - B.begin();
      int cnt = C[i + 1] - C[z];
      int days = B[i + 1] - B[z];
      int too = len - days;
      cnt += ((A[z - 1] * (A[z - 1] + 1)) / 2);
      cnt -= (((A[z - 1] - too) * (A[z - 1] - too + 1)) / 2);
      ans = max(ans, cnt);
    }
  }
  cout << ans;
}