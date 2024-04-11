#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  sort(A.begin(), A.end());
  int m = n / 2;
  vector<int> B(m + 1);
  for (int i = 0; i <= m; ++i)
    B[i] = A[m + i];
  int i = 1;
  while (i <= m){
    long long need = (B[i] - B[i - 1]) * 1ll * i;
    if (k < need)
      break;
    k -= (int)need;
    ++i;
  }
  cout << B[i - 1] + k / i;
  return 0;
}