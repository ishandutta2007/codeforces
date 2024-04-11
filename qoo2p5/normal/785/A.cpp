#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) (int) (x).size()

void run();

signed main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

int n;

void run() {
	map<string, int> q;
	q["Tetrahedron"] += 4;
	q["Cube"] += 6;
	q["Octahedron"] += 8;
	q["Dodecahedron"] += 12;
	q["Icosahedron"] += 20;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ans += q[s];
	}
	cout << ans << endl;
}