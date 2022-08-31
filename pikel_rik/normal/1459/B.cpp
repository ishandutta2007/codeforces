#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int first = (n + 1) / 2, second = n / 2;
	cout << (first != second ? 2 : 1) * (first + 1) * (second + 1) << '\n';
	return 0;
}