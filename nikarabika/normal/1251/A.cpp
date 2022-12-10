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
	bool bad[256];
	memset(bad, false, sizeof bad);
	bool app[256];
	memset(app, false, sizeof app);
	string s;
	cin >> s;
	s += '0';
	int cnt = 0;
	for (int i = 0; i < sz(s); i++) {
		app[s[i]] = true;
		if (i and s[i] != s[i - 1]) {
			bad[s[i - 1]] |= cnt & 1;
			cnt = 0;
		}
		cnt++;
	}
	for (int i = 0; i < 256; i++)
		if (app[i] and bad[i])
			cout << char(i);
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