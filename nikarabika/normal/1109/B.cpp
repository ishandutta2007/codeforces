// sobskdrbhvk...
// remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define all(x) ((x).begin()),((x).end())
#define sz(x) ((int)(x).size())

int main() {
	string s;
	cin >> s;
	if (sz(s) <= 2)
			return cout << "Impossible" << endl, 0;
	for (int i = 0; i < sz(s) / 2; i++) {
		if (s[i] != s[sz(s) - i - 1] or (i and s[i] != s[i - 1]))
			break;
		if (i == sz(s) / 2 - 1)
			return cout << "Impossible" << endl, 0;
	}
	for (int i = 1; i < sz(s); i++) {
		string t = s.substr(i, sz(s) - i) + s.substr(0, i);
		if (s == t)
			continue;
		string u = t;
		reverse(all(u));
		if (u == t)
			return cout << 1 << endl, 0;
	}
	cout << 2 << endl;
	return 0;
}