#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> B(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int j = 0; j < M; j++) {
    cin >> B[j];
  }

  int maxA = *max_element(begin(A), end(A)) + 1;
  vector<int> powA(N + 1);
  powA[0] = 1;
  for (int i = 1; i <= N; i++) {
    powA[i] = powA[i - 1] * maxA;
  }
  int allA = powA[N];

  vector<int> cntcol(1 << N);
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      if ((i >> j) & 1) {
        cntcol[i]++;
      }
      if (((i >> j) & 3) == 3) {
        cntcol[i]--;
      }
    }
  }

  vector<char> dp((M + 1) * allA * (1 << N), -1);
  int initial = 0;
  for (int i = 0; i < N; i++) {
    initial += powA[i] * A[i];
  }
  dp[(0 * allA + initial) << N | 0] = 0;

  for (int j = 0; j < M; j++) {
    for (int a = 0; a < allA; a++) {
      for (int mask = 0; mask < (1 << N); mask++) if (dp[(j * allA + a) << N | mask] != -1) {
        for (int cur = 0; cur < (1 << N); cur++) if (cntcol[cur] == B[j]) {
          int sub = ~mask & cur;
          int newa = a;
          for (int i = 0; i < N; i++) if ((sub >> i) & 1) {
            if ((a / powA[i] % maxA) == 0) {
              newa = -1;
              break;
            } else {
              newa -= powA[i];
            }
          }
          if (newa != -1) {
            dp[((j + 1) * allA + newa) << N | cur] = mask;
          }
        }
      }
    }
  }

  int cur = 0, a = 0;
  vector<int> ans(M);
  while (dp[(M * allA + 0) << N | cur] == -1) {
    cur += 1;
  }
  for (int j = M; j > 0; j--) {
    int mask = dp[(j * allA + a) << N | cur];
    assert(mask != -1);
    ans[j - 1] = cur;
    int sub = ~mask & cur;
    for (int i = 0; i < N; i++) if ((sub >> i) & 1) {
      a += powA[i];
    }
    cur = mask;
  }
  assert(a == initial);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if ((ans[j] >> i) & 1) {
        cout << '*';
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }
  return 0;
}