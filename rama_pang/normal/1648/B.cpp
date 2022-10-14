#include <bits/stdc++.h>
using namespace std;

using lint = long long;

int readInt() {
  int x = 0;
  char c = getchar();
  while (!('0' <= c && c <= '9')) c = getchar();
  while ('0' <= c && c <= '9') {
    x = 10 * x + (c - '0');
    c = getchar();
  }
  return x;
}

void Main() {
  int N, C;
  N = readInt();
  C = readInt();
  vector<int> A(N);
  vector<int> inArray(C + 1);
  for (int i = 0; i < N; i++) {
    A[i] = readInt();
    inArray[A[i]] = 1;
  }
  vector<int> isOk(C + 1);
  for (int i = 1; i <= C; i++) {
    if (!inArray[i]) {
      continue;
    }
    for (int j = 1; 1ll * i * j <= C; j++) {
      if (inArray[j]) {
        // [ij, i(j+1)-1] is ok
        isOk[i * j] += 1;
        if (i * (j + 1) <= C) {
          isOk[i * (j + 1)] -= 1;
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= C; i++) {
    cnt += inArray[i];
    isOk[i] += isOk[i - 1];
    if (inArray[i] && isOk[i] < cnt) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);

  int T = 1;
  T = readInt();
  while (T--) {
    Main();
  }
  return 0;
}