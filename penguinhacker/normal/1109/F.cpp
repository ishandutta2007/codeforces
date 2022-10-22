#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000, MX=2e5, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};

struct LCT {
	int p[MX+1], pp[MX+1], c[MX+1][2];
	bool lz[MX+1];
	bool state=0;

	void dbg() {
		if (!state)
			return;
		cout << "------------\n";
		for (int i=1; i<=4; ++i)
			cout << p[i] << " " << pp[i] << " " << c[i][0] << " " << c[i][1] << " " << lz[i] << endl;
		cout << "------------" << endl;
	}

	void attach(int u, int v, int k) {
		assert(u);
		c[u][k]=v;
		if (v)
			p[v]=u;
	}

	void app(int u) {
		assert(u);
		swap(c[u][0], c[u][1]);
		lz[u]^=1;
	}

	void psh(int u) {
		assert(u);
		if (lz[u]) {
			lz[u]=0;
			if (c[u][0])
				app(c[u][0]);
			if (c[u][1])
				app(c[u][1]);
		}
	}

	void psh_all(int u) {
		if (p[u])
			psh_all(p[u]);
		psh(u);
	}

	void rot(int u) {
		int v=p[u], d=c[v][1]==u;
		//cout << "rot " << u << " " << d << endl;
		assert(v);
		if (p[v])
			attach(p[v], u, c[p[v]][1]==v);
		else
			p[u]=0;
		attach(v, c[u][d^1], d);
		attach(u, v, d^1);
		swap(pp[u], pp[v]);
	}

	int splay(int u) {
		//cout << "splay" << u << endl;
		//dbg();
		psh_all(u);
		//dbg();
		while(p[p[u]]) {
			//cout << u << " " << p[u] << " " << p[p[u]] << endl;
			int v=p[u], w=p[v];
			if ((c[w][1]==v)==(c[v][1]==u))
				rot(v), rot(u);
			else
				rot(u), rot(u);
		}
		if (p[u])
			rot(u);
		return u;
	}

	int pr(int u) { // path root
		for (; c[u][0]; u=c[u][0], psh(u));
		return splay(u);
	}

	int xp(int u) { // expose
		for (u=splay(u); pp[u]; u=splay(u)) {
			//dbg();
			//cout << u << " " << pp[u] << endl;
			int v=pr(u);
			assert(!c[v][0]);
			int w=pp[v];
			splay(w);
			//cout << "new parent of " << v << " is " << w << endl;
			if (c[w][1])
				p[c[w][1]]=0, pp[c[w][1]]=w;
			pp[v]=0;
			attach(w, v, 1);
			//for (int i : {1, 2})
			//	cout << p[i] << " " << pp[i] << " " << c[i][0] << " " << c[i][1] << endl;
		}
		return u;
	}

	int gr(int u) { // get root of a tree
		xp(u);
		return pr(u);
	}

	int mr(int u) { // make root
		xp(u);
		if (c[u][0]) {
			app(c[u][0]);
			pp[c[u][0]]=u;
			p[c[u][0]]=0;
			c[u][0]=0;
		}
		return u;
	}

	void link(int u, int v) {
		//cout << "linking " << u << " " << v << endl;
		pp[mr(v)]=mr(u);
		//cout << "finished linking" << endl;
		//dbg();
	}

	void cut(int u, int v) {
		//cout << "cutting " << u << " " << v << endl;
		//dbg();
		//mr(u), dbg(), state|=v==3, xp(v), dbg();
		//dbg();
		mr(u), xp(v);
		assert(p[u]==v);
		rot(u);
		c[u][1]=0, p[v]=0;
		//cout << "finished cutting" << endl;
		//dbg();
	}
} lct;

int n, m, a[mxN][mxN];
ar<int, 2> pos[MX+1];
bool vis[mxN][mxN];

struct {
	ar<int, 2> st[1<<19];
	int lz[1<<19];
	ar<int, 2> cmb(ar<int, 2> x, ar<int, 2> y) {
		return x[0]!=y[0]?x[0]>y[0]?x:y:ar<int, 2>{x[0], x[1]+y[1]};
	}
	void bld(int u=1, int l=0, int r=n*m-1) {
		if (l==r) {
			st[u]={-l, 1};
			return;
		}
		int mid=(l+r)/2;
		bld(2*u, l, mid);
		bld(2*u+1, mid+1, r);
		st[u]=cmb(st[2*u], st[2*u+1]);
	}
	void psh(int u, int l, int r) {
		if (lz[u]) {
			st[u][0]+=lz[u];
			if (l!=r)
				lz[2*u]+=lz[u], lz[2*u+1]+=lz[u];
			lz[u]=0;
		}
	}
	void upd(int ql, int qr, int x, int u=1, int l=0, int r=n*m-1) {
		psh(u, l, r);
		if (l>qr||r<ql)
			return;
		if (ql<=l&&r<=qr) {
			lz[u]+=x;
			psh(u, l, r);
			return;
		}
		int mid=(l+r)/2;
		upd(ql, qr, x, 2*u, l, mid);
		upd(ql, qr, x, 2*u+1, mid+1, r);
		st[u]=cmb(st[2*u], st[2*u+1]);
	}
	ar<int, 2> qry(int ql, int qr, int u=1, int l=0, int r=n*m-1) {
		psh(u, l, r);
		if (l>qr||r<ql)
			return {-69696969, 0};
		if (ql<=l&&r<=qr)
			return st[u];
		int mid=(l+r)/2;
		return cmb(qry(ql, qr, 2*u, l, mid), qry(ql, qr, 2*u+1, mid+1, r));
	}
} st;

const unsigned long long SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED); //mt19937_64 rng(SEED);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	/*n=rng()%2+3, m=rng()%2+3;
	cout << n << " " << m << endl;
	vector<int> perm(n*m);
	iota(perm.begin(), perm.end(), 1);
	shuffle(perm.begin(), perm.end(), rng);*/
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> a[i][j];
			//a[i][j]=perm[i*m+j];
			pos[a[i][j]]={i, j};
			//cout << a[i][j] << " ";
		}
		//cout << endl;
	}
	st.bld();
	ll ans=0;
	for (int l=1, r=1; l<=n*m; ++l) {
		//cout << l << endl;
		while(r<=n*m) {
			// check if you can add r
			auto [i, j]=pos[r];
			set<int> seen;
			bool ok=1;
			for (int k=0; k<4; ++k) {
				int ni=i+dx[k], nj=j+dy[k];
				if (ni<0||ni>=n||nj<0||nj>=m||!vis[ni][nj])
					continue;
				int rt=lct.gr(ni*m+nj+1);
				if (seen.find(rt)!=seen.end()) {
					ok=0;
					break;
				}
				seen.insert(rt);
			}
			if (!ok)
				break;
			for (int k=0; k<4; ++k) {
				int ni=i+dx[k], nj=j+dy[k];
				if (0<=ni&&ni<n&&0<=nj&&nj<m&&vis[ni][nj]) {
					//cout << r-1 << " " << n*m-1 << endl;
					lct.link(i*m+j+1, ni*m+nj+1);
					st.upd(r-1, n*m-1, 1);
					//cout << "finished" << endl;
				}
			}
			vis[i][j]=1;
			++r;
		}
		//cout << l << " " << r << endl;
		ans+=st.qry(l-1, r-2)[1];
		auto [i, j]=pos[l];
		for (int k=0; k<4; ++k) {
			int ni=i+dx[k], nj=j+dy[k];
			if (0<=ni&&ni<n&&0<=nj&&nj<m&&vis[ni][nj]) {
				lct.cut(i*m+j+1, ni*m+nj+1);
				st.upd(a[ni][nj]-1, n*m-1, -1);
			}
		}
		vis[i][j]=0;
	}
	cout << ans;
	return 0;
}