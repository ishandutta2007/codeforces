#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, cnt[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		memset(cnt, 0, sizeof(cnt));
		cin >> n >> m;
		for (int i=1, u, v; i<n; ++i) {
			cin >> u >> v;
			++cnt[u], ++cnt[v];
		}
		if (cnt[m]<=1) {
			cout << "Ayush\n";
			continue;
		}
		cout << (n&1?"Ashish":"Ayush") << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/