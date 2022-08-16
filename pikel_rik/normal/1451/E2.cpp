#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = (1 << 16) + 5;

int AND(int i, int j) {
	cout << "AND " << i + 1 << ' ' << j + 1 << endl;
	int answer;
	cin >> answer;
	return answer;
}

int OR(int i, int j) {
	cout << "OR " << i + 1 << ' ' << j + 1 << endl;
	int answer;
	cin >> answer;
	return answer;
}

int XOR(int i, int j) {
	cout << "XOR " << i + 1 << ' ' << j + 1 << endl;
	int answer;
	cin >> answer;
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int lg = 32 - __builtin_clz(n) - 1;

	vector<int> a(n), x(n);
	for (int i = 1; i < n; i++) {
		x[i] = XOR(0, i);
	}

	vector<int> visited(n, -1);
	visited[0] = 0;

	int qi = -1, qj = -1;
	for (int i = 1; i < n; i++) {
		if (visited[x[i]] != -1) {
			qi = visited[x[i]];
			qj = i;
			break;
		}
		visited[x[i]] = i;
	}

	if (qi != -1) {
		a[qi] = a[qj] = AND(qi, qj);
		for (int i = 0; i < n; i++) {
			if (i == qi || i == qj) continue;
			a[i] = x[i] ^ x[qi] ^ a[qi];
		}
		cout << "! ";
		for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
	} else {
		int ii = find(x.begin(), x.end(), (1 << lg) - 1) - x.begin();
		int jj = (ii == 1 ? 2 : 1);
		int and1 = AND(0, jj), and2 = AND(ii, jj);
		for (int k = 0; k < lg; k++) {
			if (x[jj] & (1 << k)) {
				if (!(and2 & (1 << k))) {
					a[0] |= (1 << k);
				}
			} else {
				if (and1 & (1 << k)) {
					a[0] |= (1 << k);
				}
			}
		}
		for (int i = 1; i < n; i++) {
			a[i] = x[i] ^ a[0];
		}
		cout << "! ";
		for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
	}
	return 0;
}