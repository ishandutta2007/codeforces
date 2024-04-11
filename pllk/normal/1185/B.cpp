#include <iostream>

using namespace std;

int n;


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s, t;
		cin >> s >> t;
		int k = 0;
		char p = 'X';
		bool ok = true;
		for (auto c : s) {
			if (k == t.size()) {ok = false; break;}
			if (t[k] == c) {k++; p = c; continue;}
			while (t[k] == p) k++;
			if (t[k] == c) {k++; p = c; continue;}
			ok = false; break;
		}
		while (k < t.size() && t[k] == p) k++;
		if (k != t.size()) ok = false;
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}