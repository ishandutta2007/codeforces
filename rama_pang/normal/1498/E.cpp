#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> deg(N);
  for (int i = 0; i < N; i++) {
    cin >> deg[i];
  }
  vector<pair<int, int>> A;
  for (int i = 0; i < N; i++) {
    A.emplace_back(deg[i], i);
  }
  sort(begin(A), end(A));
  vector<array<int, 3>> query;
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      query.push_back({abs(A[i].first - A[j].first), A[i].second, A[j].second});
    }
  }
  sort(begin(query), end(query));
  reverse(begin(query), end(query));
  for (auto q : query) {
    cout << "? " << q[1] + 1 << ' ' << q[2] + 1 << endl;
    string foo; cin >> foo;
    if (foo == "Yes") {
      cout << "! " << q[1] + 1 << ' ' << q[2] + 1 << endl;
      return 0;
    }
  }
  cout << "! 0 0" << endl;
  return 0;
}