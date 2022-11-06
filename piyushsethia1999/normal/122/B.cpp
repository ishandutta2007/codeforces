#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s; cin >> s;
	int ii = 0, jj = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '7') {
			ii++;
		} else if(s[i] == '4') {
			jj++;
		}
	}
	if (ii == 0 && jj == 0) {
		cout << -1;
	} else if (jj >= ii) {
		cout << 4;
	} else {
		cout << 7;
	}
}