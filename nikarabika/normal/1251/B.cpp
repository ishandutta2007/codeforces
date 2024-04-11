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
	int len[n];
	int cnt[2] = {0};
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (auto c : s)
			cnt[c - '0']++;
		len[i] = sz(s);
	}
	sort(len, len + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		bool bad = false;
		for (int j = 0; j < len[i] / 2; j++)
			if (cnt[0] > 1)
				cnt[0] -= 2;
			else if (cnt[1] > 1)
				cnt[1] -= 2;
			else
				bad = true;
		if (!bad)
			ans++;
	}
	cout << ans << endl;
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