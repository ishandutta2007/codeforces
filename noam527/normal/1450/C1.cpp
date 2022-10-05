#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
char c[303][303];

void solve() {
	cin >> n;
	int cnt[3] = {};
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> c[i][j];
		if (c[i][j] == 'X') cnt[(i + j) % 3]++;
	}
	int mn = 0;
	for (int i = 0; i < 3; i++)
		if (cnt[i] < cnt[mn]) mn = i;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if ((i + j) % 3 == mn && c[i][j] == 'X') c[i][j] = 'O';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << c[i][j];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}