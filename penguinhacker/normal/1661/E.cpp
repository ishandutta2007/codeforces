#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, q, cnt, p[3][mxN+1], who[3][mxN], pos[3*mxN], nxt0[mxN], nxt1[mxN], prv0[mxN], prv1[mxN], pref0[3][mxN+1];
string g[3];

void dfs(int i, int j) {
	who[i][j]=cnt;
	for (int k=0; k<4; ++k) {
		int ni=i+dx[k], nj=j+dy[k];
		if (0<=ni&&ni<3&&0<=nj&&nj<n&&who[ni][nj]==-1&&g[ni][nj]=='1')
			dfs(ni, nj);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> g[0] >> g[1] >> g[2] >> q;
	memset(who, -1, sizeof(who));
	for (int j=0; j<n; ++j)
		for (int i=0; i<3; ++i)
			if (g[i][j]=='1'&&who[i][j]==-1) {
				pos[cnt]=j;
				++p[i][j+1];
				dfs(i, j);
				++cnt;
			}
	/*for (int i=0; i<3; ++i) {
		for (int j=1; j<=n; ++j)
			cout << p[i][j];
		cout << "\n";
	}*/
	for (int i=0; i<3; ++i)
		for (int j=1; j<=n; ++j) {
			p[i][j]+=p[i][j-1];
			pref0[i][j]=pref0[i][j-1]+(g[i][j-1]=='0');
		}
	for (int i=0; i<n; ++i) {
		prv0[i]=g[0][i]=='0'||g[2][i]=='0'?i:i?prv0[i-1]:-1;
		prv1[i]=g[0][i]=='1'&&g[1][i]=='1'&&g[2][i]=='1'?i:i?prv1[i-1]:-1;
	}
	for (int i=n-1; ~i; --i) {
		nxt0[i]=g[0][i]=='0'||g[2][i]=='0'?i:i+1<n?nxt0[i+1]:-1;
		nxt1[i]=g[0][i]=='1'&&g[1][i]=='1'&&g[2][i]=='1'?i:i+1<n?nxt1[i+1]:-1;
	}
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		int ans=0;
		for (int i=0; i<3; ++i)
			ans+=p[i][r+1]-p[i][l];
		set<int> extra, extra2;
		auto Consider=[&](int i, int j) {
			if (g[i][j]=='0')
				return;
			int x=who[i][j];
			if (l<=pos[x]&&pos[x]<=r)
				return;
			extra.insert(x);
		};
		for (int i=0; i<3; ++i) {
			Consider(i, l);
			Consider(i, r);
		}
		int found1=-1, found2=-1;
		if (g[0][l]=='1'&&g[1][l]=='0'&&g[2][l]=='1'&&who[0][l]==who[2][l])
			if (nxt1[l]==-1||nxt1[l]>r||(nxt0[l]!=-1&&nxt0[l]<nxt1[l]))
				extra2.insert(who[0][l]), found1=who[0][l];
		if (g[0][r]=='1'&&g[1][r]=='0'&&g[2][r]=='1'&&who[0][r]==who[2][r])
			if (prv1[r]==-1||prv1[r]<l||(prv0[r]!=-1&&prv0[r]>prv1[r]))
				extra2.insert(who[0][r]), found2=who[0][r];
		if (l<r&&found1!=-1&&found1==found2&&(pref0[0][l+1]!=pref0[0][r]||pref0[2][l+1]!=pref0[2][r]))
			++ans;
		//cout << ans << " " << extra.size() << " " << extra2.size() << "\n";
		cout << ans+extra.size()+extra2.size() << "\n";
	}
	return 0;
}