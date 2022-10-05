#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

struct triple {
	ll l, r;
	int i;
	triple(ll l = 0, ll r = 0, int i = 0) : l(l), r(r), i(i) {};
	bool operator < (triple &x) {
		return r < x.r;
	}
};

ll n, m, l1, r1, l2, r2, b;
vector<int> output;
vector<triple> a;

int main() {
	fast;
	cin >> n >> m >> l1 >> r1;
	output.resize(n - 1);
	for (int i = 1; i < n; i++) {
		cin >> l2 >> r2;
		a.push_back(triple(l2 - r1, r2 - l1, i - 1));
		l1 = l2, r1 = r2;
	}
	sort(a.begin(), a.end());
	multimap<ll, int> bri;
	for (int i = 0; i < m; i++) cin >> b, bri.insert({ b, i + 1 });
	for (auto &i : a) {
		auto it = bri.upper_bound(i.l - 1);
		if (it == bri.end() || it->first > i.r) {
			cout << "No" << endl;
			return 0;
		}
		output[i.i] = it->second;
		bri.erase(it);
	}
	cout << "Yes" << endl;
	for (auto i : output) cout << i << " "; cout << endl;
}