#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  vector<int> B(n - 1);
  for (int i = 0; i + 1 < n; ++i)
    B[i] = A[i + 1] - A[i];
  sort(B.rbegin(), B.rend());
  int ans = A.back() - A[0];
  for (int i = 0; i + 1 < k; ++i)
    ans -= B[i];
  cout << ans;
  return 0;
}