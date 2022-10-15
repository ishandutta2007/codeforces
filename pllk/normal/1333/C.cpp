#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

map<ll,int> m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	m[0] = 0;
	int r = -1;
	ll s = 0;
	ll u = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s += x;
		if (m.count(s)) r = max(r,m[s]);
		u += i-r-1;
		m[s] = i;
	}
	cout << u << "\n";
}