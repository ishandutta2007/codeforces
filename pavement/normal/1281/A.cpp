#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	string s;
	while (t--) {
		cin >> s;
		int l = s.size();
		if (l >= 2 && s.substr(l - 2) == "po") cout << "FILIPINO\n";
		else if ((l >= 4) && (s.substr(l - 4) == "desu" || s.substr(l - 4) == "masu")) cout << "JAPANESE\n";
		else cout << "KOREAN\n";
	}
}