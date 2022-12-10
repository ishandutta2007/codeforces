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
int le[maxn],
	ri[maxn],
	ans[maxn],
	ord[maxn];

bool lcmp(int i, int j) {
	return le[i] < le[j];
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> le[i] >> ri[i];
		ord[i] = i;
	}
	sort(ord, ord + n, lcmp);
	int rm = le[ord[0]];
	for (int i = 0; i < n; i++) {
		int id = ord[i];
		if (le[id] <= rm) {
			smax(rm, ri[id]);
			ans[id] = 1;
		}
		else
			ans[id] = 2;
	}
	if (rm >= le[ord[n - 1]])
		cout << -1 << '\n';
	else
		for (int i = 0; i < n or (cout << '\n' and 0); i++)
			cout << ans[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}