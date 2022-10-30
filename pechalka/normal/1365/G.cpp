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

set<int> query[13];
long long res[13];

int main(){
#ifdef DEBUG
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<int> A(13);
  for (int i = 0; i < 6; ++i)
    A[i] = 1;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < 13; ++j){
      if (A[j] == 1)
        query[j].emplace(i);
    }
    next_permutation(A.begin(), A.end());
  }
  for (int i = 0; i < 13; ++i){
    if (query[i].empty())
      continue;
    cout << '?' << ' ' << query[i].size() << ' ';
    for (int x: query[i])
      cout << x + 1 << ' ';
    cout << endl;
    cin >> res[i];
  }
  cout << '!' << ' ';
  for (int i = 0; i < n; ++i){
    long long ans = 0;
    for (int j = 0; j < 13; ++j){
      if (!query[j].count(i))
        ans = ans | res[j];
    }
    cout << ans << ' ';
  }
  cout << '\n';
  return 0;
}