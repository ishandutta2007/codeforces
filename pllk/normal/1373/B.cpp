#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<char> v;
		int u = 0;
		for (auto c : s) {
			if (v.size() && v.back() != c) {
				v.pop_back();
				u++;
			}
			else v.push_back(c);
		}
		if (u%2 == 0) cout << "NET\n";
		else cout << "DA\n";
	}
}