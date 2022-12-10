//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  a[n] = a[0];
  bool one = true;
  for (int i = 0; i < n; i++)
    if (a[i] != a[i + 1])
      one = false;
  if (one) {
    cout << 1 << '\n';
    for (int i = 0; i < n; i++)
      cout << 1 << ' ';
    cout << '\n';
    return 0;
  }
  if (n % 2 == 0) {
    cout << 2 << '\n';
    for (int i = 0; i < n; i++)
      cout << 1 + (i & 1) << ' ';
    cout << '\n';
    return 0;
  }
  int pos = 0;
  while (pos < n and a[pos] != a[pos + 1]) pos++;
  if (pos == n) {
    cout << 3 << '\n';
    for (int i = 0; i + 1 < n; i++)
      cout << 1 + (i & 1) << ' ';
    cout << 3 << '\n';
    return 0;
  }
  cout << 2 << '\n';
  for (int i = 0; i <= pos; i++)
    cout << 1 + (i & 1) << ' ';
  for (int i = pos + 1; i < n; i++)
    cout << 1 + (i & 1 ^ 1) << ' ';
  cout << '\n';
  return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}