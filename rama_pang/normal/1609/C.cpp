#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;

int prime[MAX];

void Main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  vector<int> b;
  const auto Get = [&](int x) {
    if (x == 1) return 0;
    if (prime[x]) return 1;
    return 2;
  };
  for (int mod = 0; mod < q; mod++) {
    b.clear();
    for (int i = mod; i < n; i += q) {
      b.emplace_back(a[i]);
    }
    int cnt = 0;
    for (int i = 0, j = -1; i < int(b.size()); i++) {
      while (j + 1 < int(b.size()) && cnt + Get(b[j + 1]) <= 1) {
        j += 1;
        cnt += Get(b[j]);
      }
      ans += j - i + 1;
      cnt -= Get(b[i]);
    }
    cnt = 0;
    for (int i = 0, j = -1; i < int(b.size()); i++) {
      while (j + 1 < int(b.size()) && cnt + Get(b[j + 1]) <= 0) {
        j += 1;
        cnt += Get(b[j]);
      }
      ans -= j - i + 1;
      cnt -= Get(b[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    ans -= prime[a[i]];
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i < MAX; i++) prime[i] = 1;
  prime[0] = prime[1] = 0;
  for (int i = 2; i < MAX; i++) if (prime[i]) {
    for (int j = i + i; j < MAX; j += i) {
      prime[j] = 0;
    }
  }

  int T = 1;
  cin >> T;
  while (T--) Main();  
}