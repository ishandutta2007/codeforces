#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n/2; i++) {
		for (int j = 1; j <= m; j++) {
			cout << i << " " << j << "\n";
			cout << n-i+1 << " " << m-j+1 << "\n";
		}
	}
	if (n%2 == 1) {
		for (int i = 1; i <= m/2; i++) {
			cout << n/2+1 << " " << i << "\n";
			cout << n/2+1 << " " << m-i+1 << "\n";
		}
		if (m%2 == 1) {
			cout << n/2+1 << " " << m/2+1 << "\n";
		}
	}
}