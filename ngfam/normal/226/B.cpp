#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n);
  vector<long long> s(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  for(int i = 0; i < n; ++i) {
    s[i] = a[i];
    if(i > 0) s[i] += s[i - 1];
  }

  auto f = [&](int l, int r) {
    long long ret = s[r];
    if(l) ret -= s[l - 1];
    return ret;
  };

  vector<long long> risan(100005);

  for(int k = 1; k <= 100004; ++k) {
    long long cur = 1;
    for(int i = 0, j = 0; i < n; j++) {
      long long w = min(1LL * n - 1, i + cur - 1);
      risan[k] += 1LL * f(i, w) * j;
      i = w + 1;
      cur *= k;
    }
  }

  int q; cin >> q;
  for(int i = 1; i <= q; ++i) {
    int x; cin >> x;
    cout << risan[x] << "\n";
  }

  return 0;
}