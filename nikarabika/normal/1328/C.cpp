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
  int a[n],
    le[n],
    ri[n];
  bool found = false;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = c - '0';
    if (found) {
      le[i] = a[i];
      ri[i] = 0;
    }
    else if (a[i] == 1) {
      le[i] = 0;
      ri[i] = 1;
      found = true;
    }
    else
      le[i] = ri[i] = a[i] / 2;
  }
  for (int i = 0; i < n; i++)
    cout << le[i];
  cout << '\n';
  for (int i = 0; i < n; i++)
    cout << ri[i];
  cout << '\n';
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