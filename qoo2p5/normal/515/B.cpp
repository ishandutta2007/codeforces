#include <iostream>
#include <cmath>

using namespace std;

int n, m;
int b, g;
bool is_bhappy[100];
bool is_ghappy[100];

int main() {
	cin >> n >> m;
	cin >> b;
	for(int i = 0; i < b; i++) {
		int x;
		cin >> x;

		is_bhappy[x] = true;
	}

	cin >> g;
	for(int i = 0; i < g; i++) {
		int x;
		cin >> x;

		is_ghappy[x] = true;
	}

	for(int i = 0; i <= 2 * n * m; i++) {
		int boy = i % n;
		int girl = i % m;

		if(is_bhappy[boy]) {
			is_ghappy[girl] = true;
		}
		if(is_ghappy[girl]) {
			is_bhappy[boy] = true;
		}
	}

	bool ans = true;

	for(int i = 0; i < n; i++) {
		ans &= is_bhappy[i];
	}
	for(int i = 0; i < m; i++) {
		ans &= is_ghappy[i];
	}

	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}