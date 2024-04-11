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

int di(int x, int y) {
	return min((x - y + 26) % 26, (y - x + 26) % 26);
}

int n;
vector<int> a;
vector<int> opt = { 'A' - 'A', 'C' - 'A', 'T' - 'A', 'G' - 'A' };

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) {
		char c;
		cin >> c;
		i = c - 'A';
	}
	int ans = md, cur;
	for (int i = 0; i + 3 < n; i++) {
		cur = 0;
		for (int j = i; j < i + 4; j++)
			cur += di(a[j], opt[j - i]);
		ans = min(ans, cur);
	}
	finish(ans);
}