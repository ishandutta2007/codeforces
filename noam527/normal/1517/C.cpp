#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;
int b[505][505];

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < n; i++) b[i][i] = a[i];
	for (int rem = 1; rem < n; rem++) {
		int col = -1;
		for (int j = 0; j + rem - 1 < n; j++) {
			if (b[j + rem - 1][j] == rem) {
				col = j;
				break;
			}
		}
		for (int j = 0; j < col; j++) {
			b[j + rem][j] = b[j + rem - 1][j];
		}
		for (int j = col; j + rem < n; j++) {
			b[j + rem][j] = b[j + rem][j + 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << b[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}