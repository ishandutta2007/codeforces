#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, INF=1e9+5;
int n, di[mxN], last[mxN];
ar<int, 4> spell[mxN];
vector<int> d;
set<ar<int, 2>> stuff[2*mxN];
ar<int, 2> st[1<<19];
queue<int> q;

void bld(int u=1, int l=0, int r=d.size()-1) {
	if (l==r) {
		st[u]={stuff[l].size()?(*stuff[l].begin())[0]:INF, l};
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=min(st[2*u], st[2*u+1]);
}

void upd(int i, int u=1, int l=0, int r=d.size()-1) {
	if (l==r) {
		st[u]={stuff[l].size()?(*stuff[l].begin())[0]:INF, l};
		return;
	}
	int mid=(l+r)/2;
	i<=mid?upd(i, 2*u, l, mid):upd(i, 2*u+1, mid+1, r);
	st[u]=min(st[2*u], st[2*u+1]);
}

ar<int, 2> qry(int qr, int u=1, int l=0, int r=d.size()-1) {
	if (l>qr)
		return {INF, -1};
	if (r<=qr)
		return st[u];
	int mid=(l+r)/2;
	return min(qry(qr, 2*u, l, mid), qry(qr, 2*u+1, mid+1, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memset(di, -1, sizeof(di));
	memset(last, -1, sizeof(last));
	for (int i=0; i<n; ++i) {
		cin >> spell[i][0] >> spell[i][1] >> spell[i][2] >> spell[i][3];
		if (!spell[i][0]&&!spell[i][1]) {
			di[i]=1;
			q.push(i);
		}
		d.push_back(spell[i][0]);
		d.push_back(spell[i][2]);
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<n; ++i) {
		spell[i][0]=lower_bound(d.begin(), d.end(), spell[i][0])-d.begin();
		spell[i][2]=lower_bound(d.begin(), d.end(), spell[i][2])-d.begin();
		if (di[i]==-1)
			stuff[spell[i][0]].insert({spell[i][1], i});
	}
	bld();
	for (; q.size(); q.pop()) {
		int i=q.front();
		int x=spell[i][2], y=spell[i][3];
		while(1) {
			ar<int, 2> mn=qry(x);
			if (mn[0]>y)
				break;
			assert(stuff[mn[1]].size()&&(*stuff[mn[1]].begin())[0]<=y);
			int j=(*stuff[mn[1]].begin())[1];
			di[j]=di[i]+1;
			last[j]=i;
			q.push(j);
			stuff[mn[1]].erase(stuff[mn[1]].begin());
			upd(mn[1]);
		}
	}
	if (di[n-1]==-1) {
		cout << -1;
		return 0;
	}
	cout << di[n-1] << "\n";
	vector<int> path;
	for (int i=n-1; ~i; i=last[i])
		path.push_back(i);
	reverse(path.begin(), path.end());
	assert(path.size()==di[n-1]);
	for (int i : path)
		cout << i+1 << " ";
	return 0;
}