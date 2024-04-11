#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s; cin >> s;
	std::map<char, char> m;
	m['A'] = 'A';
	m['H'] = 'H';
	m['I'] = 'I';
	m['M'] = 'M';
	m['O'] = 'O';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['X'] = 'X';
	m['Y'] = 'Y';
	m['b'] = 'd';
	m['d'] = 'b';
	m['o'] = 'o';
	m['p'] = 'q';
	m['q'] = 'p';
	m['v'] = 'v';
	m['w'] = 'w';
	m['x'] = 'x';
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] != m[s[n - i - 1]]) {
			cout << "NIE";
			exit(0);
		}
	}

	cout << "TAK";
}