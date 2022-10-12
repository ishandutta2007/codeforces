#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];

int ans;
vector<int> primes[N];

map<int, int> cntp[N];
map<int, int> cntallp[N];

void add(int i, int x) {
  for (int p : primes[x]) {
    int cnt = cntp[i][p];
    ++cntp[i][p];
    if (++cntallp[p][cnt + 1] == n) {
      ans = 1LL * ans * p % MOD;
    }
  }
}

void sieve() {
  for (int i = 2; i < N; ++i) {
    if (primes[i].size() > 0) continue;
    for (int j = i; j < N; j += i) {
      int num = j;
      do {
        primes[j].push_back(i);
        num /= i;
      } while (num % i == 0);
    }
  }
  // cerr << "Done sieve" << endl;
}

int solve() {
  sieve();
  scanf("%d %d", &n, &m);
  ans = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    add(i, a[i]);
  }

  while (m--) {
    int i, x;
    scanf("%d %d", &i, &x);
    add(--i, x);
    printf("%d\n", ans);
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}