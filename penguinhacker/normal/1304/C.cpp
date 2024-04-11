#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m;

void solve() {
	cin >> n >> m;
	int lb = m;
	int rb = m;
	int lastT = 0;
	bool pos = 1;
	for (int i=0, t, a, b; i<n; ++i) {
		cin >> t >> a >> b;
		lb = max(lb-(t-lastT), a);
		rb = min(rb+(t-lastT), b);
		if (lb>rb)
			pos = 0;
		lastT = t;
	}
	cout << (pos?"YES":"NO") << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while(q--)
		solve();
	return 0;
}