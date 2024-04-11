#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
  int t;
  cin >> t;
  for (int query = 0; query < t; ++query){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    bool ok = true;
    for (int i = 0; i + 1 < n; ++i){
      m += A[i] - max(A[i + 1] - k, 0);
      if (m < 0)
        ok = false;
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}