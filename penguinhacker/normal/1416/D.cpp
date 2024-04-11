#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, mxM=3e5, mxQ=5e5;
int n, m, q, p[mxN], n2, par[2*mxN], anc[2*mxN][18], tin[2*mxN], tout[2*mxN], t, val[2*mxN];
ar<int, 2> edge[mxM], qry[mxQ], child[2*mxN];
bool deleted[mxM], nodeGone[2*mxN];
int toDelete[mxQ];

int find(int i) {
	return i^par[i]?par[i]=find(par[i]):i;
}

int cmb(int u, int v) {
	par[u]=par[v]=anc[u][0]=anc[v][0]=n2;
	par[n2]=n2;
	anc[n2][0]=-1;
	child[n2]={u, v};
	return n2++;
}

void dfs(int u) {
	//cout << t << " " << u << endl;
	val[t]=u<n?p[u]:0;
	tin[u]=t++;
	if (u>=n) {
		dfs(child[u][0]);
		dfs(child[u][1]);
	}
	tout[u]=t-1;
}

struct {
	ar<int, 2> st[1<<20];
	void bld(int u=1, int l=0, int r=n2-1) {
		if (l==r) {
			st[u]={val[l], l};
			//cout << st[u][0] << " " << l << " <- " << endl;
			return;
		}
		int mid=(l+r)/2;
		bld(2*u, l, mid);
		bld(2*u+1, mid+1, r);
		st[u]=max(st[2*u], st[2*u+1]);
	}
	void upd(int i, int u=1, int l=0, int r=n2-1) {
		if (l==r) {
			assert(st[u][0]);
			st[u][0]=0;
			return;
		}
		int mid=(l+r)/2;
		i<=mid?upd(i, 2*u, l, mid):upd(i, 2*u+1, mid+1, r);
		st[u]=max(st[2*u], st[2*u+1]);
	}
	ar<int, 2> qry(int ql, int qr, int u=1, int l=0, int r=n2-1) {
		if (ql<=l&&r<=qr)
			return st[u];
		int mid=(l+r)/2;
		return max(ql<=mid?qry(ql, qr, 2*u, l, mid):ar<int, 2>{-1, -1}, qr>mid?qry(ql, qr, 2*u+1, mid+1, r):ar<int, 2>{-1, -1});
	}
} st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i=0; i<n; ++i)
		cin >> p[i];
	for (int i=0; i<m; ++i)
		cin >> edge[i][0] >> edge[i][1], --edge[i][0], --edge[i][1];
	for (int i=0; i<q; ++i) {
		cin >> qry[i][0] >> qry[i][1], --qry[i][1];
		if (qry[i][0]==2)
			deleted[qry[i][1]]=1;
	}
	n2=n;
	for (int i=0; i<n; ++i) {
		par[i]=i;
		anc[i][0]=-1;
	}
	for (int i=0; i<m; ++i)
		if (!deleted[i]) {
			int u=find(edge[i][0]), v=find(edge[i][1]);
			//cout << edge[i][0] << " " << edge[i][1] << " " << u << " " << v << "\n";
			if (u^v)
				cmb(u, v);
		}
	for (int i=q-1; ~i; --i) {
		toDelete[i]=-1;
		if (qry[i][0]==2) {
			int e=qry[i][1];
			int u=find(edge[e][0]), v=find(edge[e][1]);
			if (u^v)
				toDelete[i]=cmb(u, v);
		}
	}
	for (int j=1; j<18; ++j)
		for (int i=0; i<n2; ++i)
			anc[i][j]=anc[i][j-1]^-1?anc[anc[i][j-1]][j-1]:-1;
	for (int i=0; i<n2; ++i)
		if (anc[i][0]==-1)
			dfs(i);
	assert(t==n2);
	st.bld();
	for (int i=0; i<q; ++i) {
		if (qry[i][0]==1) {
			int u=qry[i][1];
			for (int j=17; ~j; --j)
				if (anc[u][j]^-1&&!nodeGone[anc[u][j]])
					u=anc[u][j];
			// query subtree of u
			//cout << u << " " << tin[u] << " " << tout[u] << " ";
			ar<int, 2> x=st.qry(tin[u], tout[u]);
			cout << x[0] << "\n";
			if (x[0])
				st.upd(x[1]);
		} else if (toDelete[i]^-1)
			nodeGone[toDelete[i]]=1; // , cout << i << " " << toDelete[i] << endl;
	}
	/*cout << "debugging time\n";
	cout << n2 << "\n";
	for (int i=n; i<n2; ++i)
		cout << i << " " << child[i][0] << " " << child[i][1] << "\n";*/
	return 0;
}