#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[] = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 777, 774};
	int n;
	cin >> n;
	for (auto i : a) {
		if (n % i == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}