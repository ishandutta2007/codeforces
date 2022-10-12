#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
long long a[N];

set<long long> done;

long long dist(long long u, long long p) {
  if (u <= p) return p - u;
  long long m = u % p;
  if (m*2 <= p) return m;
  return p - m;
}

vector<long long> factorize(long long n) {
  vector<long long> ret;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i > 0) continue;
    do {
      n /= i;
    } while (n % i == 0);

    ret.push_back(i);
  }

  if (n > 1) ret.push_back(n);
  return ret;
}

long long mindist(long long x) {
  long long ret = n;
  for (long long p: factorize(x)) {
    if (done.find(p) != done.end()) continue;
    done.insert(p);

    long long sum = 0;
    for (int j = 0; j < n; ++j) {
      sum += dist(a[j], p);
    }
    ret = min(ret, sum);
  }

  return ret;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }

  vector<int> p = {2, 3, 5, 7, 11, 13, 17};
  int ans = n;

  done.clear();
  for (int pp: p) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += dist(a[i], pp);
    }

    done.insert(pp);
    ans = min(ans, sum);
  }

  for (int i = 0; i < 32; ++i) {
    long long x = a[1LL * rand() * rand() % n];
    ans = min(1LL*ans, mindist(x));
    ans = min(1LL*ans, mindist(x+1));
    ans = min(1LL*ans, mindist(x-1));
  }

  printf("%d\n", ans);
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