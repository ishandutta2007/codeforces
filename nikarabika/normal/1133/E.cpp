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

const int maxn = 5050;
int dp[maxn][maxn],
	a[maxn],
	cnt[maxn],
	n, k;
vector<int> all;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		all.PB(a[i]);
	}
	all.PB(-100);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for (int i = 0; i < n; i++)
		cnt[lower_bound(all(all), a[i]) - all.begin()]++;
	for (int i = 1; i < sz(all); i++)
		for (int j = 1; j <= k; j++) {
			smax(dp[i][j], dp[i - 1][j]);
			int sum = 0;
			for (int t = i; t >= 0 and all[i] - all[t] <= 5; t--) {
				sum += cnt[t];
				smax(dp[i][j], dp[t - 1][j - 1] + sum);
			}
		}
	cout << dp[sz(all) - 1][k] << endl;
	return 0;
}