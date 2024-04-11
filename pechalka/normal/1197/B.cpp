#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  int mx = 0;
  for (int i = 1; i < n; ++i) {
    if (A[i] > A[mx])
      mx = i;
  }
  bool ok = true;
  for (int i = 0; i < mx; ++i)
    ok = ok && (A[i] < A[i + 1]);
  for (int i = mx + 1; i + 1 < n; ++i)
    ok = ok && (A[i] > A[i + 1]);
  if (ok)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}