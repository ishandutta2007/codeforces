#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  // 1: Aopen1 == Bopen1, Aclose1 == Bclose1
  // 0: Aopen0 == Bclose0, Aclose0 == Bopen0
  // Aopen1 + Aopen0 == Aclose1 + Aclose0
  // Bopen1 + Bopen0 == Bclose1 + Bclose0
  // Aopen1 - Aclose1 == Aclose0 - Aopen0 == Bclose0 - Bopen0
  // Aclose0 + Bopen0 == Aopen0 + Bclose0
  // cnt0 == even
  // S[0] == S[N - 1] == 1

  int N;
  cin >> N;
  string S;
  cin >> S;

  if (S.front() == '0' || S.back() == '0' || count(begin(S), end(S), '0') % 2 == 1 || S.size() % 2 == 1) {
    cout << "NO\n";
    return;
  }

  string A(N, '-'), B(N, '-');
  int cnt1 = count(begin(S), end(S), '1');
  for (int i = 0, j = 0, k = 0; i < N; i++) {
    if (S[i] == '0') {
      if (j == 0) {
        A[i] = '(';
        B[i] = ')';
      } else {
        A[i] = ')';
        B[i] = '(';
      }
      j ^= 1;
    } else {
      if (k < cnt1 / 2) {
        A[i] = '(';
        B[i] = '(';
      } else {
        A[i] = B[i] = ')';
      }
      k += 1;
    }
  }

  const auto Valid = [&](string s) {
    int cnt = 0;
    for (auto i : s) {
      if (i == '(') {
        cnt += 1;
      } else {
        cnt -= 1;
      }
      if (cnt < 0) return false;
    }
    return cnt == 0;
  };
  assert(Valid(A) && Valid(B));
  cout << "YES\n" << A << '\n' << B << '\n';
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