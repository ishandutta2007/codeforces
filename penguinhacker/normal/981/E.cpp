#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e4;
int n, q;
vector<int> v[1<<15];
bitset<10001> vis;
vector<bitset<10001>> dp;

void add(int ql, int qr, int x, int u=1, int l=0, int r=n-1) {
	if (ql<=l&&r<=qr) {
		v[u].push_back(x);
		return;
	}
	int mid=(l+r)/2;
	if (ql<=mid)
		add(ql, qr, x, 2*u, l, mid);
	if (qr>mid)
		add(ql, qr, x, 2*u+1, mid+1, r);
}

void dfs(int u=1, int l=0, int r=n-1) {
	bitset<10001> cur=dp.back();
	for (int i : v[u])
		cur|=cur<<i;
	if (l==r) {
		vis|=cur;
	} else {
		int mid=(l+r)/2;
		dp.push_back(cur);
		dfs(2*u, l, mid);
		dfs(2*u+1, mid+1, r);
		dp.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<q; ++i) {
		int l, r, x;
		cin >> l >> r >> x, --l, --r;
		add(l, r, x);
	}
	dp.emplace_back();
	dp[0][0]=1;
	dfs();
	vector<int> ans;
	for (int i=1; i<=n; ++i)
		if (vis[i])
			ans.push_back(i);
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i << " ";
	return 0;
}