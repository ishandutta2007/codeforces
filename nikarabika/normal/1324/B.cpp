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
  int a[n], rpos[n];
  memset(rpos, 0, sizeof rpos);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    smax(rpos[a[i]], i);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (rpos[a[j]] > i)
        return cout << "YES\n", 0;
  cout << "NO\n";
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