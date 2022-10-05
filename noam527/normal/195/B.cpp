#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<int> a(1, (m + 1) / 2);
	if (m & 1)
		for (int i = m / 2; i > 0; i--) a.push_back(i), a.push_back(m + 1 - i);
	else {
		a.push_back(m / 2 + 1);
		for (int i = m / 2 - 1; i > 0; i--) a.push_back(i), a.push_back(m + 1 - i);
	}
	for (int i = 0; i < n; i++) cout << a[i % m] << '\n';
}