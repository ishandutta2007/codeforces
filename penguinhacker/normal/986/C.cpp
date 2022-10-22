#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, ans;
bitset<1<<22> has;
bitset<1<<23> vis;

void dfs(int i) {
	vis[i]=1;
	if (i<1<<n)
		dfs(i^(1<<n)-1|1<<n);
	else {
		for (int j=0; j<n; ++j)
			if (i&1<<j&&!vis[i^1<<j])
				dfs(i^1<<j);
		i^=1<<n;
		if (!vis[i]&&has[i])
			dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int a;
		cin >> a;
		has[a]=1;
	}
	for (int i=0; i<1<<n; ++i)
		if (has[i]&&!vis[i])
			dfs(i), ++ans;
	cout << ans;
	return 0;
}