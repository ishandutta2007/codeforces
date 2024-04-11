#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

bool iseq(int i) {
	int u = 0;
	for (int o = 0; o < 3; ++o) {
		u += (i % 10);
		i /= 10;
	}
	for (int o = 0; o < 3; ++o) {
		u -= (i % 10);
		i /= 10;
	}
	return (u == 0); 
}

int chn(const string& s, int I) {
	int ii = 0;
	for (int i = 0; i < 6; ++i) { 
		ii += ((I % 10) != (s[5 - i] - '0'));
		I /= 10;
	}
	return ii;
}
int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s; cin >> s;
	int u = 6;
	for (int i = 0; (i < 1000000 && u); ++i) {
		if (iseq(i)) {
			u = min(u, chn(s, i));
		}
	}
	cout << u;
}