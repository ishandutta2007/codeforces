#include <iostream>
#include <vector>

using namespace std;

void lol() {
	int n;
	cin >> n;
	int d = 0;
	for (int i = 0; i < 9; i++) {
		vector<int> a, b;
		for (int x = 1; x <= n; x++) {
			if (x&(1<<i)) a.push_back(x);
			else b.push_back(x);
		}
		if (a.size() == 0 || b.size() == 0) continue;
		cout << a.size() << " ";
		cout << b.size() << " ";
		for (auto x : a) cout << x << " ";
		for (auto x : b) cout << x << " ";
		cout << endl;
		int u;
		cin >> u;
		d = max(d,u);
	}
	cout << "-1 " << d << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}