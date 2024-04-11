#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int a = -1, b = -1, c = -1;
		int p = 1e9;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') a = i;
			if (s[i] == '2') b = i;
			if (s[i] == '3') c = i;
			if (a == -1 || b == -1 || c == -1) continue;
			int u = i-min(a,min(b,c))+1;
			p = min(p,u);
		}
		if (p == 1e9) p = 0;
		cout << p << "\n";
	}
}