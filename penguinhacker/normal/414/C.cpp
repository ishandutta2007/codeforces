#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[1<<20];
ll tot_inv[21], tot_norm[21];

struct Node {
	ll inv, norm;
	vector<int> val;
	Node() {inv=norm=0;}
	Node(ll inv, ll norm) : inv(inv), norm(norm) {}
};
Node seg[1<<21];

Node combine(const Node& a, const Node& b) {
	const vector<int> &v1=a.val;
	const vector<int> &v2=b.val;
	int x=a.val.size();
	assert(v1.size()==v2.size());
	Node ret(a.inv+b.inv, a.norm+b.norm);
	ret.val.resize(2*x);
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), ret.val.begin());
	for (int i=0, j=0; i<x; ++i) {
		while(j<x&&v2[j]<v1[i]) {
			++j;
		}
		ret.inv+=j;
	}
	for (int i=0, j=0; j<x; ++j) {
		while(i<x&&v1[i]<v2[j]) {
			++i;
		}
		ret.norm+=i;
	}
	return ret;
}

void build(int u=1, int l=0, int r=(1<<n)-1, int h=n) {
	if (l==r) {
		assert(h==0);
		seg[u].val={a[l]};
	}
	else {
		int mid=(l+r)/2;
		build(2*u, l, mid, h-1);
		build(2*u+1, mid+1, r, h-1);
		seg[u]=combine(seg[2*u], seg[2*u+1]);
	}
	tot_inv[h]+=seg[u].inv;
	tot_norm[h]+=seg[u].norm;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<(1<<n); ++i) {
		cin >> a[i];
	}
	build();
	//Node &cur=seg[1];
	//cout << cur.inv << " " << cur.norm << "\n";
	//for (int i=0; i<=n; ++i) {
	//	cout << tot_inv[i] << " " << tot_norm[i] << "\n";
	//}
	cin >> m;
	for (int i=0; i<m; ++i) {
		int x; cin >> x;
		for (int i=0; i<=x; ++i) {
			swap(tot_inv[i], tot_norm[i]);
		}
		ll inc=tot_inv[x]-tot_norm[x];
		for (int i=x+1; i<=n; ++i) {
			tot_inv[i]+=inc;
			tot_norm[i]-=inc;
		}
		cout << tot_inv[n] << "\n";
	}
	return 0;
}