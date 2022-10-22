#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=2e5, INF=1e9;
int n, a[mxN];
vector<int> oc[mxN+1];
ar<int, 2> dp[mxN];
ll ans;

struct Node {
	int c[3], lz[3]; // 00, 01, 10
} st[1<<19];

void pll(int u) {
	for (int i=0; i<3; ++i)
		st[u].c[i]=st[2*u].c[i]+st[2*u+1].c[i];
}

void bld(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u].c[0]=1, st[u].lz[0]=st[u].lz[1]=st[u].lz[2]=-1;
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	pll(u);
}

void psh(int u, int l, int r) {
	if (st[u].lz[0]!=-1) {
		int nc[3]={};
		for (int i=0; i<3; ++i)
			nc[st[u].lz[i]]+=st[u].c[i];
		for (int i=0; i<3; ++i)
			st[u].c[i]=nc[i];
		if (l!=r) {
			for (int v : {2*u, 2*u+1})
				for (int i=0; i<3; ++i)
					st[v].lz[i]=st[v].lz[i]==-1?st[u].lz[i]:st[u].lz[st[v].lz[i]];
		}
		st[u].lz[0]=st[u].lz[1]=st[u].lz[2]=-1;
	}
}

void upd(int ql, int qr, int t, int u=1, int l=0, int r=n-1) {
	//if (u==1)
	//	cout << ql << " " << qr << " " << t << endl;
	psh(u, l, r);
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		if (t==1) { // update dp[i][0] --> 01
			st[u].lz[0]=1, st[u].lz[1]=1, st[u].lz[2]=0;
			ans+=st[u].c[2];
		} else if (t==2) { // update dp[i][1] --> 10
			st[u].lz[0]=2, st[u].lz[1]=0, st[u].lz[2]=2;
			ans+=st[u].c[1];
		} else { // update everything
			for (int i=0; i<3; ++i) {
				st[u].lz[i]=0;
				ans+=st[u].c[i];
			}
		}
		psh(u, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd(ql, qr, t, 2*u, l, mid);
	upd(ql, qr, t, 2*u+1, mid+1, r);
	pll(u);
}

void deactivate(int i, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (l==r) {
		st[u].c[0]=st[u].c[1]=st[u].c[2]=0;
		return;
	}
	int mid=(l+r)/2;
	i<=mid?deactivate(i, 2*u, l, mid):deactivate(i, 2*u+1, mid+1, r);
	pll(u);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	bld();
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (a[i]) {
			++ans;
			oc[a[i]].push_back(i);
		} else
			deactivate(i);
	}
	for (int i=1; i<=n; ++i) {
		if (oc[i].empty())
			continue;
		/*for (int j : oc[i])
			ans+=min(dp[j][0], dp[j][1])+1;
		int lb=oc[i][0], rb=oc[i].back();
		for (int j=lb+1; j<rb; ++j)
			dp[j][0]=dp[j][1]=min(dp[j][0], dp[j][1])+1;
		for (int j=0; j<lb; ++j) // this is from the right side
			dp[j][1]=min(dp[j][0], dp[j][1])+1;
		for (int j=rb+1; j<n; ++j) // from left side
			dp[j][0]=min(dp[j][0], dp[j][1])+1;*/
		int lb=oc[i][0], rb=oc[i].back();
		for (int j : oc[i])
			deactivate(j);
		if (rb+1<n) upd(rb+1, n-1, 1); // update dp[j][0]
		if (lb) upd(0, lb-1, 2); // update dp[j][1]
		if (lb<rb) upd(lb+1, rb-1, 3);
	}
	cout << ans;
	return 0;
}