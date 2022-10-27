#include <algorithm>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <random>

using namespace std;

typedef long long ll;

const int N = 200005;
int n, cnt;
ll a[N], b[N];

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void get(ll x) {
  if (x < 2) return;
  for (int i = 2; 1ll * i * i <= x; i++)
    if (x % i == 0) {
      b[++cnt] = i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) b[++cnt] = x;
}

ll query(ll x) {
  ll ans = 0;
  for (int i = 0; i < n; i++)
    if (a[i] < x)
      ans += x - a[i];
    else
      ans += min(a[i] % x, x - a[i] % x);
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int t = 1; t <= 20; t++) {
    int x = rnd() % n;
    get(a[x]), get(a[x] - 1), get(a[x] + 1);
  }
  sort(b + 1, b + cnt + 1), cnt = unique(b + 1, b + cnt + 1) - b - 1;

  ll ans = n;
  for (int i = 1; i <= cnt; i++) ans = min(ans, query(b[i]));
  cout << ans;
}