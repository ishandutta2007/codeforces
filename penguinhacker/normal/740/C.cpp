#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, large=999999;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m--) {int l, r; cin >> l >> r; large=min(large, r-l+1); }
	cout << large << '\n';
	for (int i=0; i<n; ++i)
		cout << i%large << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/