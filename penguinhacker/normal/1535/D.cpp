#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, rt, st[1<<19], lc[1<<19], rc[1<<19];
ar<int, 2> rg[1<<19];
string s;

void recalc(char c, int u) {
	st[u]=0;
	if (c=='?'||c=='0')
		st[u]+=st[lc[u]];
	if (c=='?'||c=='1')
		st[u]+=st[rc[u]];
}

void bld(int u=rt, int l=0, int r=(1<<n)-1) {
	char c=s[u-(1<<n)];
	if (l==r) {
		st[u]=1;
		return;
	}
	rg[u-(1<<n)]={l, r};
	int mid=(l+r)/2;
	bld(lc[u], l, mid);
	bld(rc[u], mid+1, r);
	recalc(c, u);
	//cout << l << " " << r << " " << u << " " << st[u] << "\n";
}

void upd(int i, int u=rt, int l=0, int r=(1<<n)-1) {
	if (l>rg[i][1]||r<rg[i][0])
		return;
	char c=s[u-(1<<n)];
	if (rg[i]==ar<int, 2>{l, r}) {
		recalc(c, u);
		return;
	}
	int mid=(l+r)/2;
	upd(i, lc[u], l, mid);
	upd(i, rc[u], mid+1, r);
	recalc(c, u);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s >> q;
	vector<int> v(1<<n);
	iota(v.begin(), v.end(), 0);
	for (int j=0; j<n; ++j) {
		int start=v.back()+1;
		vector<int> nv;
		for (int i=0; i<(1<<(n-j-1)); ++i) {
			lc[start+i]=v[2*i];
			rc[start+i]=v[2*i+1];
			//cout << start+i << " " << lc[start+i] << " " << rc[start+i] << "\n";
			nv.push_back(start+i);
		}
		swap(v, nv);
	}
	rt=v[0];
	bld();
	while(q--) {
		int i;
		char c;
		cin >> i >> c, --i;
		s[i]=c;
		upd(i);
		cout << st[rt] << "\n";
	}
	return 0;
}