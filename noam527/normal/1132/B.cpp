#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 9e18;
const int OO = 1;
using namespace std;

int n;
vector<ll> a;
ll S = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, S += i;

	sort(a.begin(), a.end());

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << S - a[(int)a.size() - x] << '\n';
	}
}