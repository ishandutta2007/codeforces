#include <iostream>
#include <set>

using namespace std;

int n, k;
int a[111];

void lol() {
	cin >> n >> k;
	set<int> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	if (s.size() > k) {
		cout << "-1\n";
		return;
	}
	cout << n*k << "\n";
	for (int i = 1; i <= n; i++) {
		for (auto x : s) cout << x << " ";
		for (int j = 1; j <= k-s.size(); j++) cout << 1 << " ";
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}