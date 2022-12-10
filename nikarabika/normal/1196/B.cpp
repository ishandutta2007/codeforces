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
	int s[n];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		s[i] &= 1;
		cnt += s[i];
	}
	if (cnt < k or ((cnt - k) & 1)) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cnt = 0;
	for (int i = 0; i < n; i++)
		if ((s[i] and cnt + 1 < k) or i == n - 1)
			cout << i + 1 << ' ', cnt++;
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