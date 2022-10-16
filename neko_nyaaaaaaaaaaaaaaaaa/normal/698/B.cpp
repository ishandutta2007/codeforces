#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, root = -1, ans = 0; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == a[i]) root = i;
	}
	if (root == -1) {
		ans++;
		vector<int> vis(n+1);
		int x = 1;
		while (vis[x] == 0) {
			vis[x] = 1;
			x = a[x];
		}
		root = a[x] = x;
	}
	
	vector<int> b = a;
	vector<int> vis(n+1);
	vis[root] = 2;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 2) continue;
		
		int x = i;
		while (vis[x] == 0) {
			vis[x] = 1;
			x = a[x];
		}
		
		if (vis[x] == 1) {
			b[x] = root;
			ans++;
		}
		
		x = i;
		while (vis[x] != 2) {
			vis[x] = 2;
			x = a[x];
		}
	}
	
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		cout << b[i] << " ";
	}
	
	return 0;
}