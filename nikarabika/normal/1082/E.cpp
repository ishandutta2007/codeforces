//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;

#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)
#define PB push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define L first
#define R second

const int maxn = 5e5 + 10;
int a[maxn],
	dp[maxn],
	ps[maxn],
	n, c;
vector<int> vec[maxn];

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vec[a[i]].PB(i);
		ps[i + 1] = ps[i] + (a[i] == c);
	}
	int ans = ps[n];
	for (int i = 0; i < n; i++) if (a[i] != c) {
		dp[i] = ps[n] + 1;
		if (vec[a[i]][0] != i) {
			int prv = *(lower_bound(all(vec[a[i]]), i) - 1);
			smax(dp[i], dp[prv] + 1 - (ps[i] - ps[prv]));
		}
		smax(ans, dp[i]);
	}
	cout << ans << endl;

	return 0;
}