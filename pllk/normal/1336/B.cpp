#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

int n[3];
set<int> s[3];
vector<int> v[3];

int up(int k, int x) {
	auto it = s[k].lower_bound(x);
	if (it == s[k].end()) return -1;
	else return *it;
}

int down(int k, int x) {
	auto it = s[k].lower_bound(x);
	if (it != s[k].end() && *it == x) return *it;
	if (it == s[k].begin()) return -1;
	it--;
	return *it;
}

void lol() {
	cin >> n[0] >> n[1] >> n[2];
	for (int k = 0; k <= 2; k++) {
		s[k].clear();
		v[k].clear();
		for (int i = 0; i < n[k]; i++) {
			int x;
			cin >> x;
			s[k].insert(x);
			v[k].push_back(x);
		}
	}
	ll rr = 5e18;
	for (int k = 0; k <= 2; k++) {
		int a, b;
		if (k == 0) {a = 1; b = 2;}
		if (k == 1) {a = 0; b = 2;}
		if (k == 2) {a = 0; b = 1;}
		for (int i = 0; i < n[k]; i++) {
			ll x = v[k][i];
			ll y = up(a,x);
			ll z = down(b,x);
			if (y != -1 && z != -1) rr = min(rr,(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x));
			y = down(a,x);
			z = up(b,x);
			if (y != -1 && z != -1) rr = min(rr,(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x));
		}
	}
	cout << rr << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) lol();
}