#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		ll u = 0;
		int d = 0;
		ll k = 0;
		for (auto c : s) {
			k++;
			if (c == '+') d++;
			else (d--);
			if (d == -1) {
				u += k;
				d = 0;
			}
		}
		u += s.size();
		cout << u << "\n";
	}
}