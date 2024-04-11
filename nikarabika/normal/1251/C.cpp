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
	string s;
	cin >> s;
	string vec[2];
	string ans;
	for (auto c : s)
		vec[c & 1] += (c);
	int l = 0,
		r = 0;
	for (int i = 0; i < sz(s); i++) {
		if (l == sz(vec[0]))
			ans += vec[1][r++];
		else if (r == sz(vec[1]))
			ans += vec[0][l++];
		else if (vec[0][l] < vec[1][r])
			ans += vec[0][l++];
		else
			ans += vec[1][r++];
	}
	cout << ans << '\n';
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