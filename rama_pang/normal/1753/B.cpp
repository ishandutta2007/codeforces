#include <bits/stdc++.h>
using namespace std;

using lint = long long;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

bool isPrime(int x) {
  if (x <= 1) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

const int MAX = 5e5 + 5;
int fact[MAX];
vector<int> divisor[MAX];

void Main() {
  int n, x;
  cin >> n >> x;
  // for (int i = 1; i < MAX; i++) {
  //   for (int j = i; j < MAX; j += i) {
  //     divisor[j].emplace_back(i);
  //   }
  // }  
  vector<int> cnt(MAX);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  // for (int i = MAX - 2; i >= 0; i--) {
  //   cnt[i] += cnt[i + 1];
  // }
  for (int i = 1; i < MAX; i++) {
    while (cnt[i] >= i + 1) {
      cnt[i] -= i + 1;
      cnt[i + 1]++;
    }
  } 
  for (int i = 0; i < x; i++) {
    if (cnt[i] != 0) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  return;

  for (int it = 0; it < 20; it++) {
    int P = 9e8 + rnd() % int(1e9 + 100);
    while (!isPrime(P)) {
      P = 9e8 + rnd() % int(1e9 + 100);
    }
    cout << P << '\n';
    fact[0] = 1;
    for (int i = 1; i <= x; i++) {
      fact[i] = 1ll * i * fact[i - 1] % P;
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
      ans += fact[a[i]];
    }
    ans %= P;
    cout << ans << ' ' << fact[x] << '\n';
    if (ans != fact[x]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}