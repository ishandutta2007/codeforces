#include <set>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for (int query = 0; query < t; ++query){
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i){
      int x;
      cin >> x;
      A[i] = make_pair(x, i);
    }
    sort(A.begin(), A.end());
    set<int> was;
    for (int i = 0; i < n; ++i)
      was.insert(A[i].first);
    vector<int> B(n);
    int ans = 0;
    for (int i = 0; i < n; ++i){
      if (i == 0 || A[i].first != A[i - 1].first)
        B[A[i].second] = A[i].first;
      else {
        ++ans;
        bool end = false;
        for (int j = 0; j < 4; ++j){
          for (int k = 0; k < 10; ++k){
            int tmp;
            if (j == 0){
              tmp = k * 1000 + A[i].first % 1000;
            } else if (j == 1){
              tmp = k * 100 + A[i].first / 1000 * 1000 + A[i].first % 100;
            } else if (j == 2){
              tmp = k * 10 + A[i].first / 100 * 100 + A[i].first % 10;
            } else {
              tmp = k + A[i].first / 10 * 10;
            }
            if (was.count(tmp) == 0){
              was.insert(tmp);
              B[A[i].second] = tmp;
              end = true;
              break;
            }
          }
          if (end)
            break;
        }
      }
    }
    cout << ans << '\n';
    for (int x: B)
      cout << x / 1000 << x / 100 % 10 << x / 10 % 10 << x % 10 << '\n';
  }
  return 0;
}