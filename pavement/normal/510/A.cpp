#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	bool r = true;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) for (int i = 0; i < m; i++) cout << "#";
		else {
			if (r) {
				for (int i = 0; i < m - 1; i++) cout << ".";
				cout << "#";
			} else {
				cout << "#";
				for (int i = 0; i < m - 1; i++) cout << ".";
			}
			r = !r;
		}
		cout << "\n";
	}
}