#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

const int MOD = 1e9+7;

ll x, ans;
string s;

void solve() {
	cin >> x >> s;
	ans = s.size();
	ll toRight = s.size();
	for (int l=0; l<x; ++l) {
		int repeat = s[l]-'0';
		if (s.size() < x) {
			string sr = s.substr(l+1, s.size()-l-1);
			for (int i=1; i<repeat; ++i)
				s += sr;
		}
		toRight--;
		if (toRight < 0)
			toRight += MOD;
		ans = (ans+(repeat-1)*toRight)%MOD;
		toRight = repeat*toRight%MOD;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}