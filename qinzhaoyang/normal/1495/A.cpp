#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int T, n, x[N], y[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n; int ca = 0, cb = 0;
		for (int i = 1; i <= n * 2; i++) {
			int x1, y1; cin >> x1 >> y1;
			if (y1 == 0) x[++ca] = abs(x1);
			else y[++cb] = abs(y1);
		}
		sort (x + 1, x + n + 1);
		sort (y + 1, y + n + 1);
		double ans = 1e20, sum = 0;
		for (int i = 1; i <= n; i++)
			sum += sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
		ans = min(ans, sum);
		for (int i = 1; i <= n; i++)
			sum += sqrt(1ll * x[i] * x[i] + 1ll * y[n - i + 1] * y[n - i + 1]);
		cout << fixed << setprecision(15) << ans << endl;
	}
	return 0;
}