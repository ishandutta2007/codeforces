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
	string s;
	cin >> s;
	string tmp = "[:";
	int lptr = 0,
		pos = 0;
	while (pos != 2 and lptr < sz(s)) {
		if (s[lptr] == tmp[pos])
			pos++;
		lptr++;
	}
	if (pos != 2) {
		cout << -1 << endl;
		return 0;
	}
	int rptr = sz(s) - 1;
	pos = 0;
	tmp = "]:";
	while (pos != 2 and rptr >= 0) {
		if (s[rptr] == tmp[pos])
			pos++;
		rptr--;
	}
	if (pos != 2 or lptr - 1 >= rptr + 1) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 4 + rptr - lptr + 1;
	for (int i = lptr; i <= rptr; i++)
		if (s[i] != '|')
			ans--;
	cout << ans << endl;
	return 0;
}