#include <bits/stdc++.h>
using namespace std;
using lint = long long;

template<typename T>
class MaxQueue : public deque<pair<T, lint>> {
 public:
  void insert(T x, lint id) {
    while (!this->empty() && this->back() <= make_pair(x, id)) {
      this->pop_back();
    }
    this->emplace_back(x, id);
  }

  void erase(lint id) {
    if (!this->empty() && this->front().second <= id) {
      this->pop_front();
    }
  }

  T query() {
    assert(!this->empty());
    return this->front().first;
  }

};

lint N, K, X;
lint A[5005];

pair<lint, lint> dp[5005];
MaxQueue<pair<lint, lint>> maxQ;

pair<lint, lint> trial(lint lambda) {
  dp[0] = {0, 0};
  maxQ.clear();
  maxQ.insert(dp[0], 0);
  for (int i = 1; i <= N; i++) {
    dp[i] = maxQ.query();
    dp[i].first += A[i] - lambda;
    dp[i].second--;
    maxQ.erase(i - K);
    maxQ.insert(dp[i], i);
  }

  return maxQ.query();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> K >> X;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  lint opt = 1e12;
  for (lint l = 0, r = opt, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
    pair<lint, lint> cur = trial(mid);
    if (-cur.second <= X) {
      opt = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  pair<lint, lint> cur = trial(opt);
  if (-cur.second > X) {
    cout << -1 << "\n";
  } else {
    cout << (cur.first + 1ll * X * opt) << "\n";
  }
  return 0;
}