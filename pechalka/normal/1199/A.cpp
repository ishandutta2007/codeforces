#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>

using namespace std;

int main(){
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  for (int i = 0; i < n; ++i){
    bool ok = true;
    for (int j = max(i - x, 0); j <= i - 1; ++j)
      ok = ok && (A[j] > A[i]);
    for (int j = i + 1; j <= i + y && j < n; ++j)
      ok = ok && (A[j] > A[i]);
    if (ok){
      cout << i + 1 << ' ';
      return 0;
    }
  }
  return 0;
}