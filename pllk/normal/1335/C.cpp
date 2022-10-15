#include <iostream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int,int> m;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			m[x]++;
		}
		int a = 0, b = 0, c = 1;
		bool ok = true;
		for (auto x : m) {
			if (x.second == 1) {
				a++;
			} else {
				c = max(c,x.second);
				a++;
			}
		}
		if (n == 1) cout << "0\n";
		else {
			int u = min(a-1,c);
			if (c >= u+2) u++;
			cout << u << "\n";
		}
	}
}