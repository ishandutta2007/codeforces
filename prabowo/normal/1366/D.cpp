#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;

int largest_primes[N];
void sieve(int n) {
  for (int i = 2; i < N; ++i) {
    if (largest_primes[i] > 0) continue;
    for (int j = i; j < N; j += i) {
      largest_primes[j] = i;
    }
  }
}

const int NN = 500005;

int n;
int ans[NN][2];

int solve() {
  sieve(N);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);

    int p = largest_primes[a];

    int _a = a;
    // cerr << a << " " << p << endl;

    int d1 = 1;
    while (a % p == 0) {
      d1 *= p;
      a /= p;
    }
    int d2 = _a / d1;

    if (d1 > 1 && d2 > 1) {
      ans[i][0] = d1;
      ans[i][1] = d2;
    } else {
      ans[i][0] = ans[i][1] = -1;
    }
  }

  for (int i = 0; i < n; ++i) printf("%d ", ans[i][0]); printf("\n");
  for (int i = 0; i < n; ++i) printf("%d ", ans[i][1]); printf("\n");
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}