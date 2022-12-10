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

const int maxn = 1e6;
LL card[maxn],
   want[maxn],
   dif[maxn],
   h[maxn];
LL dp[600][6000];
int n, k;

LL get(int cnt, int people) {
	smin(cnt, people * k);
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < people; i++)
		for (int j = 0; j <= cnt; j++)
			for (int l = 0; l <= k; l++)
				if (j - l >= 0)
					smax(dp[i][j], (i == 0 ? 0 : dp[i - 1][j - l]) + h[l]);
	return dp[people - 1][cnt];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n * k; i++) {
		int x;
		cin >> x;
		card[x]++;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		want[x]++;
	}
	for (int i = 1; i <= k; i++)
		cin >> h[i];
	for (int i = k + 1; i < maxn; i++)
		h[i] = h[i - 1];
	for (int i = 0; i + 1 < maxn; i++)
		dif[i] = h[i + 1] - h[i];
	LL ans = 0;
	for (int i = 0; i < maxn; i++)
		if (want[i]) {
			ans += get(card[i], want[i]);
		}
	cout << ans << endl;
	return 0;
}