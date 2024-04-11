#include <bits/stdc++.h>
using namespace std;

void Main() {
  int Nin, K;
  cin >> Nin >> K;

  int N = K;
  vector<vector<int>> ans(N, vector<int>(N, 1));
  for (int i = 0; i < N; i++) {
    ans[i][i] = 0;
  }

  int cnt = 1;
  while (N < Nin) {
    cnt += 1;
    if (N * K <= Nin) {
      vector<vector<int>> newAns(N * K, vector<int>(N * K, cnt));
      for (int k = 0; k < K; k++) {
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
            newAns[k * N + i][k * N + j] = ans[i][j];
          }
        }
      }
      N *= K;
      ans = newAns;
    } else {
      vector<vector<int>> newAns(Nin, vector<int>(Nin, cnt));
      for (int k = 0; k < K; k++) {
        if (k * N > Nin) break;
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
            if (k * N + i < Nin && k * N + j < Nin) {
              newAns[k * N + i][k * N + j] = ans[i][j];
            }
          }
        }
      }
      N = Nin;
      ans = newAns;      
    }
  }
  N = Nin;

  cout << cnt << '\n';
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      cout << ans[i][j] << ' ';
    }
  }
  cout << '\n';

  // vector<vector<int>> edge(N, vector<int>(N, -1));
  // for (int MAX = 1; MAX <= 4; MAX++) {
  //   const auto Check = [&](int node) {
  //     if (K == 2) {
  //       for (int i = 0; i <= node; i++) {
  //         for (int j = 0; j < i; j++) {
  //           for (int k = i + 1; k <= node; k++) {
  //             if (edge[j][i] == edge[i][k]) {
  //               return false;
  //             }
  //           }
  //         }
  //       }
  //       return true;
  //     }
  //     if (K == 3) {
  //       for (int i = 0; i <= node; i++) {
  //         for (int j = i + 1; j <= node; j++) {
  //           for (int k = 0; k < i; k++) {
  //             for (int l = j + 1; l <= node; l++) {
  //               if (edge[k][i] == edge[i][j] && edge[i][j] == edge[j][l]) {
  //                 return false;
  //               }
  //             }
  //           }
  //         }
  //       }
  //       return true;
  //     }
  //     if (node + 1 <= K) return true;
  //     vector<int> ord(node + 1);
  //     iota(begin(ord), end(ord), 0);
  //     do {
  //       assert(ord.size() > K);
  //       vector<int> v;
  //       for (int i = 0; i <= K; i++) {
  //         v.emplace_back(ord[i]);
  //       }
  //       sort(begin(v), end(v));
  //       set<int> meet;
  //       assert(v.size() == K + 1);
  //       for (int i = 1; i <= K; i++) {
  //         meet.emplace(edge[v[i - 1]][v[i]]);
  //       }
  //       if (meet.size() <= 1) return false;
  //     } while (next_permutation(begin(ord), end(ord)));
  //     return true;
  //   };
  //   const auto Brute = [&](const auto &self, int pos, int last) -> void {
  //     if (pos == last) {
  //       if (!Check(pos)) {
  //         return;
  //       }
  //       if (pos == N - 1) {
  //         for (int i = 0; i < N; i++) {
  //           for (int j = 0; j < N; j++) {
  //             cout << edge[i][j] + 1 << ' ';
  //           }
  //           cout << '\n';
  //         }
  //         exit(0);
  //       } else if (pos + 1 < N) {
  //         self(self, pos + 1, 0);
  //       }
  //     } else {
  //       // for (int r = MAX; r < MAX; r++) {
  //       //   edge[last][pos] = r;
  //       //   edge[pos][last] = r;
  //       // }
  //       edge[last][pos] = edge[pos][last] = ans[last][pos];
  //       self(self, pos, last + 1);
  //     }
  //   };
  //   Brute(Brute, 0, 0);
  // }
  // cout << "WHAA?\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
/*

5 2
0 1 1 1 1 
0 0 2 3 2
0 0 0 3 3
0 0 0 0 2
0 0 0 0 0

6 2
0 1 1 1 2 1 
0 0 2 3 2 2
0 0 0 3 3 3
0 0 0 0 2 2
0 0 0 0 0 1
0 0 0 0 0 0

7 2
0 1 1 3 1 2 1 
0 0 2 3 3 2 2
0 0 0 3 3 3 3
0 0 0 0 1 2 1
0 0 0 0 0 2 2
0 0 0 0 0 0 1
0 0 0 0 0 0 0

8 2
0 1 2 1 3 1 2 1 
1 0 2 2 3 3 2 2
2 2 0 1 3 1 3 1
1 2 1 0 3 3 3 3
3 3 3 3 0 1 2 1
1 3 1 3 1 0 2 2
2 2 3 3 2 2 0 1
1 2 1 3 1 2 1 0

9 3
0 1 1 2 1 1 2 1 1 
1 0 1 2 2 1 2 2 1
1 1 0 2 2 2 2 2 2

2 2 2 0 1 1 2 1 1
1 2 2 1 0 1 2 2 1
1 1 2 1 1 0 2 2 2

2 2 2 2 2 2 0 1 1
1 2 2 1 2 2 1 0 1
1 1 2 1 1 2 1 1 0

10 3
0 1 1 1 1 1 1 2 1 1 
1 0 1 1 1 1 1 2 2 1
1 1 0 2 2 2 2 2 2 2
1 1 2 0 2 2 3 2 2 2
1 1 2 2 0 3 3 3 3 3
1 1 2 2 3 0 3 3 3 3
1 1 2 3 3 3 0 2 2 2
2 2 2 2 3 3 2 0 1 1
1 2 2 2 3 3 2 1 0 1
1 1 2 2 3 3 2 1 1 0
*/