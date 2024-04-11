#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int N, M;
  cin >> N >> M;
  
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << (A[i][j] + ((i + j) % 2 != A[i][j] % 2)) << " \n"[j + 1 == M];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}