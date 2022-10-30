#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  int ans = n;
  int left = -1;
  unordered_map<int, int> was;
  int t = 2;
  while (left < n){
    ++left;
    if (left > 0 && was.find(A[left - 1]) != was.end() && was[A[left - 1]] == 1)
      break;
    if (left > 0)
      was[A[left - 1]] = 1;
    int right = n;
    while (right > left && (was.find(A[right - 1]) == was.end() || (was[A[right - 1]] != 1 && was[A[right - 1]] < t))){
      was[A[right - 1]] = t;
      --right;
    }
    ++t;
    ans = min(ans, right - left);
  }
  cout << ans;
  return 0;
}