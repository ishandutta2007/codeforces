#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int B = 1 << 17;
int k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	if (k == 0) {
		cout << "1 1\n1";
		return 0;
	}
	cout << "3 3\n";
	cout << (B | k) << " " << B << " 0\n";
	cout << k << " " << (B | k) << " " << k << "\n";
	cout << "0 " << k << " " << k;
	return 0;
}