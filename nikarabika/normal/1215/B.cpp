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
	int n;
	cin >> n;
	vector<LL> vec;
	LL sum[2][n + 10];
	sum[0][0] = sum[1][0] = 0;
	LL ans[2] = {0};
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 0)
			cnt++;
		else
			vec.PB(cnt), cnt = 0;
	}
	vec.PB(cnt);
	n = sz(vec);
	for (int i = 0; i < n; i++) {
		sum[0][i + 1] = sum[0][i];
		sum[1][i + 1] = sum[1][i];
		sum[i & 1][i + 1] += vec[i] + 1;
	}
	for (int i = 0; i < n; i++) {
		ans[0] += vec[i] * (vec[i] + 1) / 2;
		ans[0] += (vec[i] + 1) * sum[i & 1][i];
		ans[1] += (vec[i] + 1) * sum[i & 1 ^ 1][i];
	}
	cout << ans[1] << ' ' << ans[0] << endl;
	return 0;
}