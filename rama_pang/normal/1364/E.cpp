#include <bits/stdc++.h>
using namespace std;
using lint = long long;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
  int N;
  cin >> N;

  auto Query = [&](int i, int j) {
    static map<pair<int, int>, int> memo;
    if (memo.count({i, j})) return memo[{i, j}];
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int res;
    cin >> res;
    if (res == -1) {
      exit(0);
    }
    return memo[{i, j}] = memo[{j, i}] = res;
  };

  vector<int> zero_candidates;
  vector<int> candidates(N);
  iota(begin(candidates), end(candidates), 0);
  bool first = true;
  while (true) {
    int r = candidates[rnd() % candidates.size()];
    if (first) {
      while (true) {
        int x = rnd() % N;
        int y = rnd() % N;
        if (x != y && __builtin_popcount(Query(x, y)) <= 5) {
          r = x;
          break;
        }
      }
    }
    first = false;
    map<int, vector<int>> res;
    for (auto c : candidates) if (c != r) {
      res[Query(c, r)].emplace_back(c);
    }
    vector<int> new_candidates = begin(res)->second;
    new_candidates.emplace_back(r);
    candidates = new_candidates;
    if (candidates.size() <= 2) {
      for (auto z : candidates) {
        zero_candidates.emplace_back(z);
      }
      break;
    }
  }

  sort(begin(zero_candidates), end(zero_candidates));
  zero_candidates.resize(unique(begin(zero_candidates), end(zero_candidates)) - begin(zero_candidates));

  vector<int> order(N);
  iota(begin(order), end(order), 0);
  shuffle(begin(order), end(order), rnd);
  for (auto i : order) {
    if (zero_candidates.size() == 1) {
      break;
    }
    int can = 1;
    for (auto z : zero_candidates) if (z == i) can = 0;
    if (can) {
      map<int, vector<int>> res;
      for (auto z : zero_candidates) {
        res[Query(z, i)].emplace_back(z);
      }
      zero_candidates = begin(res)->second;
    }
  }

  int zero = zero_candidates[0];
  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    if (i != zero) {
      ans[i] = Query(i, zero);
    }
  }
  
  cout << "!";
  for (auto i : ans) cout << " " << i;
  cout << endl;
  return 0;
}