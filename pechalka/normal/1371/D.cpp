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

  int t;
  cin >> t;
  while (t--){
    int n, k;
    cin >> n >> k;
    vector<int> A(n * n);
    int add = 0;
    int i = 0;
    for (int _ = 0; _ < k; ++_){
      A[i * n + (i + add) % n] = 1;
      ++i;
      if (i == n){
        i = 0;
        ++add;
      }
    }
    if (k % n == 0)
      cout << 0 << '\n';
    else
      cout << 2 << '\n';
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j)
        cout << A[i * n + j];
      cout << '\n';
    }
  }
  return 0;
}