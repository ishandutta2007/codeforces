#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			while (v.size() > 1 && x > v.back()) v.pop_back();
			if (v.size() == 0) {
				v.push_back(x);
			} else if (v.size() == 1) {
				if (x < v.back()) v.push_back(x);
			} else v.push_back(x);
		}
		if (v.size() == 1) cout << "YES\n";
		else cout << "NO\n";
	}
}