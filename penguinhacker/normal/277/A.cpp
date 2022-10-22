#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
bool vis[100]={};
bool p[100][101]={};

void dfs(int u) {
	vis[u]=1;
	for (int i=1; i<=m; ++i) {
		if (p[u][i]==0)
			continue;
		for (int j=0; j<n; ++j)
			if (!vis[j]&&p[j][i]==1)
				dfs(j);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	bool FUCKINGEVERYTHINGISA0=1;
	cin >> n >> m;
	for (int i=0, a, x; i<n; ++i) {
		cin >> a;
		if (a)
			FUCKINGEVERYTHINGISA0=0;
		while (a--) {
			cin >> x;
			p[i][x]=1;
		}
	}

	int ans=(FUCKINGEVERYTHINGISA0?0:-1);
	for (int i=0; i<n; ++i) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}