#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000;
int n, m, a[mxN][mxN], ans[mxN][mxN];
ar<int, 2> p[3];
string s;

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> a[i][j], --a[i][j];
	for (int i=0; i<3; ++i)
		p[i]={i, 0};
	cin >> s;
	for (char t : s) {
		if (t=='R'||t=='L')
			p[1][1]+=t=='R'?1:-1;
		else if (t=='U'||t=='D')
			p[0][1]+=t=='D'?1:-1;
		else if (t=='I')
			swap(p[1], p[2]);
		else
			swap(p[0], p[2]);
	}
	for (int i=0; i<3; ++i)
		p[i][1]=(p[i][1]%n+n)%n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			ar<int, 3> c={i, j, a[i][j]};
			ar<int, 3> c2;
			for (int k=0; k<3; ++k)
				c2[k]=(c[p[k][0]]+p[k][1])%n;
			ans[c2[0]][c2[1]]=c2[2]+1;
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
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