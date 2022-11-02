#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
  int q;
  cin >> q;
  for (int query = 0; query < q; ++query){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    vector<int> r;
    int last = -1;
    for (int i = 0; i < n - 1; ++i){
      if (A[i] % 2 == 1 && (r.size() + 1 < k)) {
        r.push_back(i);
        last = i;
      }
    }
    if (r.size() < (k - 1)){
      cout << "NO\n";
      continue;
    }
    bool ok = false;
    for (int i = last + 1; i < n; ++i) {
      if (A[i] % 2 == 1)
        ok = !ok;
    }
    if (!ok){
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int x : r)
      cout << x + 1 << " ";
    cout << n << "\n";
  }
  return 0;
}