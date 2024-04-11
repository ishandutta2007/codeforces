#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

const int B = 5;

int n;
vector<int> a[B];

bool cmp(const vector<int> &x, const vector<int> &y) {
	int cnt = 0;
	for (int i = 0; i < B; i++)
		if (x[i] < y[i]) cnt++;
	return cnt >= 3;
}

void solve() {
	cin >> n;
	for (int i = 0; i < B; i++) a[i].resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < B; j++)
			cin >> a[j][i];
	}
	int at = -1;
	vector<int> best(B, md);
	for (int i = 0; i < n; i++) {
		vector<int> x;
		for (int j = 0; j < B; j++) x.push_back(a[j][i]);
		if (!cmp(best, x)) best = x, at = i + 1;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		vector<int> x;
		for (int j = 0; j < B; j++) x.push_back(a[j][i]);
		if (cmp(best, x)) cnt++;
	}
	if (cnt == n - 1) {
		cout << at << '\n';
	}
	else {
		cout << "-1\n";
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	//srand(time(NULL));
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}