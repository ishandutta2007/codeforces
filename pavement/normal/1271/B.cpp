#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> fl;

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s, ts;
    cin >> n >> s;
    ts = s;
    for (int i = 0, l = s.size(); i < l - 1; i++) {
		if (s[i] == 'W' && s[i + 1] == 'W') fl.push_back(i), s[i] = s[i + 1] = 'B';
		else if (s[i] == 'B' && s[i + 1] == 'B') continue;
		else if (s[i] == 'W' && s[i + 1] == 'B') fl.push_back(i), s[i] = 'B', s[i + 1] = 'W';
		else continue;
	}
	bool cn = 0;
	for (char c : s)
		if (c == 'W') cn = 1;
	if (!cn) {
		cout << fl.size() << '\n';
		for (int i : fl) cout << i + 1 << ' ';
		cout << '\n';
		return 0;
	}
	fl.clear();
	s = ts;
	for (int i = 0, l = s.size(); i < l - 1; i++) {
		if (s[i] == 'B' && s[i + 1] == 'B') fl.push_back(i), s[i] = s[i + 1] = 'W';
		else if (s[i] == 'W' && s[i + 1] == 'W') continue;
		else if (s[i] == 'B' && s[i + 1] == 'W') fl.push_back(i), s[i] = 'W', s[i + 1] = 'B';
		else continue;
	}
	cn = 0;
	for (char c : s)
		if (c == 'B') cn = 1;
	if (!cn) {
		cout << fl.size() << '\n';
		for (int i : fl) cout << i + 1 << ' ';
		cout << '\n';
		return 0;
	} else cout << "-1\n";
}