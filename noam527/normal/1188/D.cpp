#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
ll a[100005];
int dp[60][100005];
ll b[60][100005];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll M = *max_element(a, a + n);
	for (int i = 0; i < n; i++) a[i] = M - a[i];
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < n; j++) b[i][j] = a[j];
		sort(b[i], b[i] + n, [i](ll aa, ll bb) {
			return (aa % (1LL << (ll)i)) < (bb % (1LL << (ll)i));
		});
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += b[1][i] & 1;
	for (int j = 0; j <= n; j++) dp[1][j] = md;
	dp[1][0] = min(dp[1][0], cnt);
	dp[1][cnt] = min(dp[1][cnt], n - cnt);
	for (int i = 1; i + 1 < 60; i++) {
		if (OO) {
			cout << "starting " << i << '\n';
			cout << "dp: ";
			for (int j = 0; j <= n; j++) cout << dp[i][j] << " "; cout << '\n';
		}
		for (int j = 0; j <= n; j++) dp[i + 1][j] = md;
		int in[2], out[2];
		ll P = i;
		// put 0
		if (OO) cout << "put 0\n";
		in[0] = in[1] = out[0] = out[1] = 0;
		for (int j = 0; j < n; j++)
			out[b[i][j] >> P & 1]++;
		for (int j = 0; j <= n; j++) {
			int c = in[1];
			if (OO) {
				cout << "from " << i << " " << j << " to " << i + 1 << " " << c << " with addition of " << in[0] + out[1] << '\n';
			}
			dp[i + 1][c] = min(dp[i + 1][c], dp[i][j] + in[0] + out[1]);
			if (j == n) break;
			ll v = b[i][n - 1 - j];
			if (OO) cout << "upd " << v << " " << (v >> P & 1) << '\n';
			out[v >> P & 1]--;
			in[v >> P & 1]++;
		}
		// put 1
		if (OO) cout << "put 1\n";
		in[0] = in[1] = out[0] = out[1] = 0;
		for (int j = 0; j < n; j++)
			out[b[i][j] >> P & 1]++;
		for (int j = 0; j <= n; j++) {
			int c = in[0] + in[1] + out[1];
			if (OO) {
				cout << "from " << i << " " << j << " to " << i + 1 << " " << c << " with addition of " << in[1] + out[0] << '\n';
			}
			dp[i + 1][c] = min(dp[i + 1][c], dp[i][j] + in[1] + out[0]);
			if (j == n) break;
			ll v = b[i][n - 1 - j];
			out[v >> P & 1]--;
			in[v >> P & 1]++;
		}
	}
	cout << dp[59][0] << '\n';
}