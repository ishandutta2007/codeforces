#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=150000;
int n, m, h, a[mxN], b[mxN], ans;
vector<int> d;
ar<int, 2> st[4*mxN];

// {cnt unpaired b, cnt unpaired a}

ar<int, 2> comb(ar<int, 2> l, ar<int, 2> r) {
	ar<int, 2> res={l[0]+r[0], l[1]+r[1]};
	int mn=min(l[0], r[1]);
	res[0]-=mn, res[1]-=mn;
	return res;
}

void upd(int i, ar<int, 2> x, int u=1, int l=0, int r=d.size()-1) {
	if (l==r) {
		st[u][0]+=x[0];
		st[u][1]+=x[1];
		int mn=min(st[u][0], st[u][1]);
		st[u][0]-=mn;
		st[u][1]-=mn;
		//cout << "[" << l << "] = [" << st[u][0] << ", " << st[u][1] << "]" << endl;
		return;
	}
	int mid=(l+r)/2;
	if (i<=mid)
		upd(i, x, 2*u, l, mid);
	else
		upd(i, x, 2*u+1, mid+1, r);
	st[u]=comb(st[2*u], st[2*u+1]);
}

void dbg(int u=1, int l=0, int r=d.size()-1) {
	cout << "[" << l << ", " << r << "] = [" << st[u][0] << ", " << st[u][1] << "]" << endl;
	if (l==r)
		return;
	int mid=(l+r)/2;
	dbg(2*u, l, mid);
	dbg(2*u+1, mid+1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> h;
	for (int i=0; i<m; ++i)
		cin >> b[i];
	for (int i=0; i<n; ++i)
		cin >> a[i];
	d=vector<int>(a, a+n);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<m; ++i) {
		int x=lower_bound(d.begin(), d.end(), h-b[i])-d.begin();
		if (x==d.size()) {
			cout << 0;
			return 0;
		}
		//cout << x << "\n";
		upd(x, {1, 0});
	}
	for (int i=0; i<n; ++i) {
		a[i]=lower_bound(d.begin(), d.end(), a[i])-d.begin();
		//cout << a[i] << " ";
		upd(a[i], {0, 1});
		if (i>=m)
			upd(a[i-m], {0, -1});
		//dbg();
		//cout << endl;
		ans+=st[1][0]==0;
	}
	cout << ans;
	return 0;
}