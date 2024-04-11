#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m;
vector<int> a;
vector<int> pos;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	a.resize(m);
	for (auto &i : a) cin >> i;
	int nxt = 0;
	for (auto &i : a) {
		if (nxt + i > n) finish(-1);
		pos.push_back(nxt);
		nxt++;
	}
	pos.back() = n - a.back();
	for (int i = m - 2; i >= 0; i--) {
		if (pos[i] + a[i] < pos[i + 1])
			pos[i] = pos[i + 1] - a[i];
	}
	if (pos[0] != 0) finish(-1);
	for (auto &i : pos) cout << 1 + i << " "; cout << endl;
}