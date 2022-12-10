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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  int a[n];
  int dp[n + 1][h];
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  dp[0][0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < h; j++) if (~dp[i][j]) {
      int newpos = (j + a[i]) % h;
      smax(dp[i + 1][newpos], dp[i][j] + (l <= newpos and newpos <= r));
      newpos = (j + a[i] - 1) % h;
      smax(dp[i + 1][newpos], dp[i][j] + (l <= newpos and newpos <= r));
    }
  cout << *max_element(dp[n], dp[n] + h) << endl;
	return 0;
}