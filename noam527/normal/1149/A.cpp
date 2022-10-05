#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
int c1 = 0, c2 = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) c1++;
		else c2++;
	}
	if (!c1) {
		for (int i = 0; i < n; i++) cout << "2 ";
		return 0;
	}
	if (!c2) {
		for (int i = 0; i < n; i++) cout << "1 ";
		return 0;
	}
	cout << "2 1 ";
	c2--, c1--;
	while (c2--) cout << "2 ";
	while (c1--) cout << "1 ";
}