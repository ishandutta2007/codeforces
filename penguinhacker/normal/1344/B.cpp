#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int n, m, ans=0;
string g[1000];
bool vis[1000][1000];

bool chk(string s) {
	int state=0;
	for (char c : s) {
		if (state==0&&c=='#')
			++state;
		else if (state==1&&c=='.')
			++state;
		else if (state==2&&c=='#') {
			cout << -1;
			exit(0);
		}
	}
	return state==0;
}

void dfs(int i, int j) {
	vis[i][j]=1;
	for (int k=0; k<4; ++k) {
		int a=i+dx[k], b=j+dy[k];
		if (a>=0&&a<n&&b>=0&&b<m&&!vis[a][b]&&g[a][b]=='#')
			dfs(a, b);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> g[i];
	bool b1=0, b2=0;
	for (int i=0; i<n; ++i)
		if (chk(g[i]))
			b1=1;
	for (int i=0; i<m; ++i) {
		string s="";
		for (int j=0; j<n; ++j)
			s.push_back(g[j][i]);
		if (chk(s))
			b2=1;
	}
	if (b1^b2==1) {
		cout << -1;
		return 0;
	}
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!vis[i][j]&&g[i][j]=='#')
				dfs(i, j), ++ans;
	cout << ans;
	return 0;
}