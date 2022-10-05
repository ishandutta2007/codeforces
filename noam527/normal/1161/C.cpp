#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
int a[51] = {};

void fin(int player) {
	if (player == 1) cout << "Alice\n";
	else cout << "Bob\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	int v = 1;
	while (!a[v]) v++;
	if (a[v] > n / 2) fin(2);
	fin(1);
}