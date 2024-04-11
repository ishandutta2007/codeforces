#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
using namespace std;

int n, x;
map<int, ll> M;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		M[x - i] += x;
	}
	ll ans = -inf;
	for (const auto &i : M)
		ans = max(ans, i.second);
	cout << ans << '\n';
}