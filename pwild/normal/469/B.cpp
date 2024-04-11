#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main() {
	ios_base::sync_with_stdio(false);
	
	int p, q, l, r;
	cin >> p >> q >> l >> r;

	bool x[1001], z[1001];
	FOR(i, 0, 1001) x[i] = z[i] = false;
	FOR(i, 0, p) {
		int a, b; cin >> a >> b;
		FOR(j, a, b + 1) z[j] = true;
	}
	FOR(i, 0, q) {
		int a, b; cin >> a >> b;
		FOR(j, a, b + 1) x[j] = true;
	}
	int res = 0;
	FOR(t, l, r + 1) {
		FOR(i, 0, 1001 - t) if (z[i + t] && x[i]) {
			res++; break;
		}
	}
	cout << res << endl;

}