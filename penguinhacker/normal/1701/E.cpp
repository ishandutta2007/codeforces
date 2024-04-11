#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5000;
const short INF=32000;
int n, m;
short pre[mxN][mxN+1], suf[mxN][mxN+1];
string s, t; // s->t

void solve() {
	cin >> n >> m >> s >> t;
	for (int i=0; i<n; ++i)
		for (int j=0; j<=m; ++j)
			pre[i][j]=suf[i][j]=-1;
	pre[0][0]=1;
	pre[0][1]=s[0]==t[0]?0:-1;
	for (int i=1; i<n; ++i) {
		for (int j=0; j<=m; ++j) {
			if (pre[i-1][j]!=-1)
				pre[i][j]=i+1;
			if (j&&pre[i-1][j-1]!=-1&&s[i]==t[j-1]&&(pre[i][j]==-1||pre[i-1][j-1]<pre[i][j]))
				pre[i][j]=pre[i-1][j-1];
		}
	}
	suf[n-1][0]=n-1;
	suf[n-1][1]=s[n-1]==t[m-1]?n:-1;
	for (int i=n-2; ~i; --i) {
		for (int j=0; j<=m; ++j) {
			if (suf[i+1][j]!=-1)
				suf[i][j]=i;
			if (j&&suf[i+1][j-1]!=-1&&s[i]==t[m-j]&&(suf[i][j]==-1||suf[i+1][j-1]>suf[i][j]))
				suf[i][j]=suf[i+1][j-1];
		}
	}
	if (suf[0][m]==-1) {
		cout << "-1\n";
		return;
	}
	int ans=n-suf[0][m];
	for (int i=0; i+1<n; ++i) {
		for (int j=0; j<=m; ++j) {
			if (pre[i][j]==-1||suf[i+1][m-j]==-1)
				continue;
			//cout << i << " " << j << " " << 1+pre[i][j]+(i+1-j) << " " << n-suf[i+1][m-j] << endl;
			ans=min(ans, (1+pre[i][j]+(i+1-j))+(n-suf[i+1][m-j]));
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}