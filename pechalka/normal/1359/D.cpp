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

const int MAXN = 100001;

int A[MAXN];
int pref[MAXN];

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i){
    cin >> A[i];
    pref[i + 1] = pref[i] + A[i];
  }
  vector<pair<int, int>> stack;
  vector<int> maximums;
  stack.emplace_back(31, -1e7);
  maximums.emplace_back(-1e7);
  int ans = 0;
  for (int i = n - 1; i >= 0; --i){
    int tmp = pref[i + 1];
    while (stack.back().first <= A[i]){
      tmp = max(tmp, stack.back().second);
      stack.pop_back();
      maximums.pop_back();
    }
    stack.emplace_back(A[i], tmp);
    maximums.push_back(max(maximums.back(), stack.back().second - stack.back().first));
    ans = max(ans, maximums.back() - pref[i]);
  }
  cout << ans << '\n';
  return 0;
}