#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, o, z;
vector<int> p(200001);
vector<int> v(200001);
vector<int> b(200001);

void dfs(int now) {
	v[now] = 1;
	if (b[now]) o++;
	
	if (v[p[now]]) return;
	dfs(p[now]);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i]) continue;
		
		ans++;
		dfs(i);
	}
	if (ans == 1) ans = 0;
	if ((o & 1) == 0) ans++;

	cout << ans;
	
	return 0;
}