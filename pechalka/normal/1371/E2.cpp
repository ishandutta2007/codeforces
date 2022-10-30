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

int p;

struct superset{
  multiset<int> S;
  int move;
  superset(){
    move = 0;
  }
  bool has(){
    return S.find((p - move) % p) != S.end();
  }
  void add(int x){
    S.emplace((x + p - move) % p);
  }
  void erase(int x){
    S.erase(S.find((x + p - move) % p));
  }
  void kek(int t){
    move = (move + t) % p;
  }
};

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
  superset S;
  for (int i = 0; i < n; ++i)
    cnt[i] = 0;
  for (int i = 0; i < n; ++i)
    cnt[max(0, A[i] - min_x)] += 1;
  S.add(cnt[0] % p);
  for (int i = 1; i < n; ++i){
    cnt[i] += cnt[i - 1] - 1;
    S.add(cnt[i] % p);
  }
  if (!S.has())
    res.emplace_back(min_x);
  for (int i = 1; min_x + i < mx; ++i){
    S.erase((cnt[i - 1] + i - 1) % p);
    S.add(0);
    S.kek(1);
    if (!S.has())
      res.emplace_back(min_x + i);
  }
  cout << res.size() << '\n';
  for (int x: res)
    cout << x << ' ';
  cout << '\n';
  return 0;
}