#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m, cnt;
string g[50], g2[50];
bool vis[50][50];

void dfs(int i, int j) {
	vis[i][j]=1;
	for (int k=0; k<4; ++k) {
		int a=i+di[k], b=j+dj[k];
		if (0<=a&&a<n&&0<=b&&b<m&&!vis[a][b]&&g[a][b]=='B')
			dfs(a, b);
	}
}

bool good(ar<int, 2> a, ar<int, 2> b) { // a is larger
	return a[0]<=b[0]&&b[1]<=a[1];
}

void rot() {
	for (int i=0; i<m; ++i)
		g2[i].resize(n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			g2[j][n-i-1]=g[i][j];
	swap(n, m);
	for (int i=0; i<n; ++i)
		g[i]=g2[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> g[i];
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!vis[i][j]&&g[i][j]=='B')
				dfs(i, j), ++cnt;
	if (cnt>1) {
		cout << "NO";
		return 0;
	}
	bool ok=1;
	for (int k=0; k<2; ++k) {
		vector<ar<int, 2>> v;
		for (int i=0; i<n; ++i) {
			vector<int> oc;
			for (int j=0; j<m; ++j)
				if (g[i][j]=='B')
					oc.push_back(j);
			for (int j=1; j<oc.size(); ++j)
				if (oc[j]-oc[j-1]>1) {
					cout << "NO";
					return 0;
				}
			if (oc.size())
				v.push_back({oc[0], oc.back()});
		}
		for (int i=0; i<v.size(); ++i)
			for (int j=i+1; j<v.size(); ++j)
				ok&=good(v[i], v[j])||good(v[j], v[i]);
		rot();
	}
	cout << (ok?"YES":"NO");
	return 0;
}