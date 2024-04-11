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

int A[100000];

int cnt[100000];

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int p, n;
  cin >> n >> p;
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  sort(A, A + n);
  int min_x = 0;
  int mx = 0;
  for (int i = 0; i < n; ++i)
    mx = max(mx, A[i]);
  for (int i = 0; i < n; ++i)
    min_x = max(min_x, A[i] - i);
  vector<int> res;
  for (int x = min_x; x < mx; ++x){
    for (int i = 0; i < n; ++i)
      cnt[i] = 0;
    for (int i = 0; i < n; ++i)
      cnt[max(0, A[i] - x)] += 1;
    bool ok = cnt[0] % p != 0;
    for (int i = 1; i < n; ++i){
      cnt[i] += cnt[i - 1] - 1;
      ok = ok && cnt[i] % p != 0;
    }
    if (ok)
      res.emplace_back(x);
  }
  cout << res.size() << '\n';
  for (int x: res)
    cout << x << ' ';
  cout << '\n';
  return 0;
}