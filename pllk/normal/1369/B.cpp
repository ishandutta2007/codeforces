#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string a, b, r;
		int z = 0;
		for (auto c : s) {
			if (c == '1') z = 1;
			if (z == 0) a += c;
			else r += c;
		}
		while (r.size() && r.back() == '1') {
			b += '1';
			r.pop_back();
		}
		if (r.size()) r = "0";
		cout << a << r << b << "\n";
	}
}