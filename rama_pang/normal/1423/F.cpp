#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> segs;
  long long cnt = 0;
  long long sum = 0;
  for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    cnt += b;
    sum += 1ll * (a - 1) * b % N;
  }

  if (cnt < N) {
    cout << "1\n";
  } else if (cnt > N) {
    cout << "-1\n";
  } else if (sum % N == 1ll * N * (N - 1) / 2 % N) {
    cout << "1\n";
  } else {
    cout << "-1\n";
  }
  return 0;
}