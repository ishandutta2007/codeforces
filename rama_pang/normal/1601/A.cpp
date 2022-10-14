#include <bits/stdc++.h>
using namespace std;

int Gcd(int a, int b) {
  if (a == 0 || b == 0) return a + b;
  return __gcd(a, b);
}

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int g = 0;
  for (int b = 0; b < 30; b++) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      cnt += (A[i] >> b) & 1;
    }
    g = Gcd(g, cnt);
  }
  for (int i = 1; i <= N; i++) {
    if (Gcd(g, i) == i) {
      cout << i << ' ';
    }
  }
  cout << '\n';
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