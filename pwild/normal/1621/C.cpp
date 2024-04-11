#include <bits/stdc++.h>
using namespace std;

int query(int i) {
	cout << "? " << i+1 << endl;
	int res; cin >> res;
	if (res == 0) exit(0);
	return res-1;
}

void solve() {
	int n; cin >> n;
	vector<int> done(n), perm(n);

	for (int i = 0; i < n; i++) if (!done[i]) {
		vector<int> cycle;
		while (true) {
			int j = query(i);
			if (done[j]) break;
			done[j] = true;
			cycle.push_back(j);
		}
		
		int len = size(cycle);
		for (int j = 0; j < len; j++) {
			perm[cycle[j]] = cycle[(j+1)%len];
		}
	}
	
	cout << "!";
	for (int x: perm) cout << " " << x+1;
	cout << endl;
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}