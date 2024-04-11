#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>

using namespace std;

int log2(int x){
  int ans = 0;
  int pow = 1;
  while (pow < x){
    pow *= 2;
    ++ans;
  }
  return ans;
}

int main(){
  int n, I;
  cin >> n >> I;
  I *= 8;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  sort(A.begin(), A.end());
  vector<int> B(n);
  for (int i = 1; i < n; ++i){
    if (A[i] == A[i - 1])
      B[i] = B[i - 1];
    else
      B[i] = B[i - 1] + 1;
  }
  int ans = n - 1;
  for (int left = 0; left < n; ++left){
    int l = left, r = n;
    while (r - l > 1){
      int m = (l + r) / 2;
      if (n * log2(B[m] - B[left] + 1) <= I)
        l = m;
      else
        r = m;
    }
    int right = l;
    ans = min(ans, n - right + left - 1);
  }
  cout << ans;
  return 0;
}