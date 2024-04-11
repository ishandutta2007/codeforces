#include <iostream>

using namespace std;

void lol() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) cout << "W";
			else cout << "B";
		}
		cout << "\n";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}