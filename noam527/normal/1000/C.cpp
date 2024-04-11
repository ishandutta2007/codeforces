#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
ll l, r;
map<ll, int> m;
vector<ll> ans;

int main() {
	fast;
	cin >> n;
	ans.resize(n, 0);
	for (int i = 0; i < n; i++)
		cin >> l >> r, m[l]++, m[r + 1]--;
	for (auto it = next(m.begin()), pit = m.begin(); it != m.end(); it++, pit++) {
		it->second += pit->second;
		if (pit->second)
			ans[pit->second - 1] += it->first - pit->first;
	}
	for (const auto &i : ans) cout << i << " "; cout << endl;
}