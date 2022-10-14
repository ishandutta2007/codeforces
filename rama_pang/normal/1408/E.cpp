#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M, N;
  cin >> M >> N;
  vector<int> A(M), B(N);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  vector<array<int, 3>> edge;
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    while (k--) {
      int v;
      cin >> v;
      v--;
      edge.push_back({A[i] + B[v], i, M + v});
    }
  }
  
  sort(begin(edge), end(edge));
  reverse(begin(edge), end(edge));

  vector<int> p(N + M);
  iota(begin(p), end(p), 0);
  function<int(int)> Find = [&](int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  };

  long long ans = 0;
  for (auto e : edge) {
    ans += e[0];
    if (Find(e[1]) != Find(e[2])) {
      p[Find(e[1])] = Find(e[2]);
      ans -= e[0];
    }
  }

  cout << ans << "\n";
  return 0;
}