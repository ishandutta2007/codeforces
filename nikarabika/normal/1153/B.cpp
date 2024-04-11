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

const int maxn = 200;
int ans[maxn][maxn],
	a[maxn],
	b[maxn],
	n, m, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			ans[i][j] = h * x;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			smin(ans[i][j], min(a[i], b[j]));
			cout << ans[i][j] << " \n"[j == m - 1];
		}
	return 0;
}