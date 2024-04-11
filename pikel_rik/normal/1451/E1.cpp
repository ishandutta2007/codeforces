#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = (1 << 16) + 5;

int n, a[N];

int AND(int i, int j) {
	cout << "AND " << i << ' ' << j << endl;
	int answer;
	cin >> answer;
	return answer;
}

int OR(int i, int j) {
	cout << "OR " << i << ' ' << j << endl;
	int answer;
	cin >> answer;
	return answer;
}

int XOR(int i, int j) {
	cout << "XOR " << i << ' ' << j << endl;
	int answer;
	cin >> answer;
	return answer;
}

void guess() {
	cout << "! ";
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	int lg = 32 - __builtin_clz(n) - 1;

	int xor12 = XOR(1, 2), and12 = AND(1, 2);
	int xor13 = XOR(1, 3), and13 = AND(1, 3);
	int xor23 = xor12 ^ xor13, and23 = AND(2, 3);

	int sum12 = xor12 + 2 * and12;
	int sum13 = xor13 + 2 * and13;
	int sum23 = xor23 + 2 * and23;

	a[1] = (sum12 + sum13 - sum23) / 2;
	a[2] = (sum12 + sum23 - sum13) / 2;
	a[3] = (sum13 + sum23 - sum12) / 2;

	for (int i = 4; i <= n; i++) {
		a[i] = a[1] ^ XOR(1, i);
	}
	guess();
	return 0;
}