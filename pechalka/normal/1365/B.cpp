#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int T;
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    for (int i = 0; i < n; ++i)
      cin >> B[i];
    bool has1 = false;
    bool has2 = false;
    for (int i = 0; i < n; ++i){
      if (B[i] == 1)
        has1 = true;
      else
        has2 = true;
    }
    if (has1 && has2)
      cout << "Yes\n";
    else {
      bool ok = true;
      for (int i = 1; i < n; ++i)
        ok = ok && (A[i - 1] <= A[i]);
      if (ok)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}