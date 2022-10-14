#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,mmx,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e6 + 100;
int cnt[MAX];
int ptr[MAX];
int nn = 0;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] += 1e6;
  }
  int ans = -1;
  for (int d = 1; d < MAX; d++) {
    nn = 0;
    for (auto a : A) {
      int b = a;
      if (2 * a >= d) {
        b = a % d;
      } else if (a >= d) {
        b -= d;
      }
      cnt[b] += 1;
      ptr[++nn] = b;
    }
    int score = 0;
    for (int i = 1; i <= nn; i++) {
      score = max(score, cnt[ptr[i]]);
      cnt[ptr[i]] = 0;
    }
    if (score * 2 >= N) {
      ans = d;
    }
  }
  if (ans > 2e6) ans = -1;
  cout << ans << '\n';
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