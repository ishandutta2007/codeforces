#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=500, M=998244353;
int n, a[2*mxN][mxN], cnt[mxN][mxN];
bool e[2*mxN][2*mxN], vis[2*mxN];

void rem(int i) {
	assert(!vis[i]);
	vis[i]=1;
	for (int j=0; j<n; ++j)
		--cnt[j][a[i][j]];
	for (int j=0; j<2*n; ++j)
		e[i][j]=e[j][i]=0;
}

void solve() {
	cin >> n;
	for (int i=0; i<2*n; ++i)
		for (int j=0; j<n; ++j) {
			cin >> a[i][j], --a[i][j];
			++cnt[j][a[i][j]];
		}
	for (int i=0; i<2*n; ++i)
		for (int j=i+1; j<2*n; ++j) {
			bool same=0;
			for (int k=0; k<n; ++k)
				if (a[i][k]==a[j][k]) {
					same=1;
					break;
				}
			e[i][j]=e[j][i]=same;
		}
	int ans=1;
	vector<int> p;
	for (int k2=0; k2<n; ++k2) {
		int ind=-1;
		for (int i=0; i<n&&ind==-1; ++i)
			for (int j=0; j<n&&ind==-1; ++j)
				if (cnt[i][j]==1)
					for (int k=0; k<2*n&&ind==-1; ++k)
						if (!vis[k]&&a[k][i]==j)
							ind=k;
		if (ind==-1) {
			for (int i=0; i<2*n&&ind==-1; ++i)
				if (!vis[i])
					ind=i;
			ans=2*ans%M;
		}
		assert(ind!=-1);
		for (int i=0; i<2*n; ++i)
			if (e[ind][i])
				rem(i);
		rem(ind);
		p.push_back(ind);
	}
	cout << ans << "\n";
	for (int i : p)
		cout << i+1 << " ";
	cout << "\n";
	memset(vis, 0, 2*n);
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