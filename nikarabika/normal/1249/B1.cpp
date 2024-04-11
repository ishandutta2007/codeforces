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

int solve() {
	int n;
	cin >> n;
	int a[n],
	mark[n];
	memset(mark, 0, sizeof mark);
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i]--;
	int ans[n];
	for (int i = 0; i < n; i++) {
		if (mark[i] == 0) {
			int cur = i,
				len = 0;
			while (!mark[cur])
				mark[cur] = 1, len++, cur = a[cur];
			cur = i;
			while (mark[cur] == 1)
				ans[cur] = len, mark[cur] = 2, cur = a[cur];
		}
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}