#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a, b;
vector<int> p;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	p.resize(n);
	for (auto &i : a) cin >> i, --i;
	for (auto &i : b) cin >> i, --i;
	for (int i = 0; i < n; i++)
		p[a[i]] = i;
	for (auto &i : b) i = p[i];
	//for (const auto &i : b) cout << i << " "; cout << '\n';
	int cnt = 0, mn = b.back();
	for (int i = n - 2; i >= 0; i--) {
		if (b[i] > mn) cnt++;
		mn = min(mn, b[i]);
	}
	cout << cnt << '\n';
}