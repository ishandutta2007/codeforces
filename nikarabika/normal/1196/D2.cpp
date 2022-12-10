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

const int maxn = 3e5 + 10;
int sum[3][maxn][3];
int mp[1000];

int get(int l, int r, int val) {
	r -= (r - l) % 3;
	int id = l % 3;
	l /= 3;
	r /= 3;
	r++;
	return (r - l) - (sum[id][r][val] - sum[id][l][val]);
}

void solve() {
	int n, k;
	string s, t[3];
	cin >> n >> k
		>> s;
	for (int i = 0; i < n; i++) {
		t[i % 3] += s[i];
		for (int j = 0; j < 3; j++)
			sum[i % 3][i / 3 + 1][j] = sum[i % 3][i / 3][j];
		sum[i % 3][i / 3 + 1][mp[s[i]]]++;
	}
	int ans = k;
	for (int i = 0; i + k <= n; i++) {
		int l = i,
			r = i + k - 1;
		for (int j = 0; j < 3; j++) {
			int cur = 0;
			for (int jj = 0; jj < 3 and jj < k; jj++) {
				int nval = (j + jj) % 3;
				cur += get(l + jj, r, nval);
			}
			smin(ans, cur);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	mp['R'] = 0;
	mp['G'] = 1;
	mp['B'] = 2;
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}