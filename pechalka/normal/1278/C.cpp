#include <set>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

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
  for (int queries = 0; queries < t; ++queries) {

    int n;
    cin >> n;
    vector<int> A(2 * n);
    for (int i = 0; i < 2 * n; ++i)
      cin >> A[i];
    int ans = 2 * n;
    set<pair<int, int>> S;
    pair<int, int> prev = make_pair(0, 0);
    for (int i = 0; i < n; ++i){
      if (A[n + i] == 1)
        prev.first += 1;
      else
        prev.first -= 1;
      prev.second = i + 1;
      S.insert(prev);
    }
    S.insert(make_pair(0, 0));
    int wholecnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
      if (A[i] == 1)
        ++wholecnt;
      else
        --wholecnt;
    }
    int sum = 0;
    for (int cnt = 0; cnt <= n; ++cnt){
      auto t = S.lower_bound(make_pair(wholecnt - sum, 0));
      if (t != S.end() && t->first == wholecnt - sum)
        ans = min(ans, cnt + t->second);
      if (cnt < n && A[n - cnt - 1] == 1)
        sum += 1;
      else
        sum -= 1;
    }
    cout << ans << '\n';
  }
  return 0;
}