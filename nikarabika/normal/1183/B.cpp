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

void solve() {
	int n, k;
	cin >> n >> k;
	int le = 0,
		ri = 200 * 1000 * 1000;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		smax(le, x - k);
		smin(ri, x + k);
	}
	if (le > ri) {
		cout << -1 << endl;
		return;
	}
	cout << ri << '\n';
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