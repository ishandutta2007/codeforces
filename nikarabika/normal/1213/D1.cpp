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

const int maxn = 2e5 + 10;
vector<int> vec[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int cur = 0;
		while (x) {
			vec[x].PB(cur);
			cur++;
			x >>= 1;
		}
		vec[0].PB(cur);
	}
	int ans = 1e9;
	for (int i = 0; i < maxn; i++) if (sz(vec[i]) >= k) {
		sort(all(vec[i]));
		int cur = 0;
		for (int j = 0; j < k; j++)
			cur += vec[i][j];
		smin(ans, cur);
	}
	cout << ans << endl;
	return 0;
}