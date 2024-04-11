#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

vector<int> p;

int query(vector<int> A) {
#ifdef DEBUG
  vector<int> s(p.size());
  map<int, int> cnt;
  for (int i = 0; i < p.size(); ++i) {
    s[i] = p[i] + A[i];
    cnt[s[i]] = cnt[s[i]] + 1;
  }
  for (int i = 0; i < p.size(); ++i) {
    if (cnt[s[i]] > 1)
      return i + 1;
  }
  return 0;
#else
  cout << '?' << ' ';
  for (int x : A)
    cout << x << ' ';
  cout << endl;
  int k;
  cin >> k;
  return k;
#endif
}

int main() {
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
#ifdef DEBUG
  p.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];
#endif
  vector<int> ans(n);
  int last = 1;
  for (int d = 1; d < n; ++d) {
    vector<int> A(n, 1);
    A.back() = d + 1;
    int id = query(A);
    if (id == 0) {
      last = n + 1 - d;
      break;
    }
    ans[id - 1] = d;
  }
  for (int d = 1; d < last; ++d) {
    vector<int> A(n, d + 1);
    A.back() = 1;
    int id = query(A);
    ans[id - 1] = -d;
  }
  cout << '!' << ' ';
  for (int i = 0; i < n; ++i)
    cout << ans[i] + last << ' ';
  cout << endl;
  return 0;
}