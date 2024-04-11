#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()
const int mn2 = int(1e6) + 10;

int n;
int col[mn2];

vector<pp> event[30];

void E() {
	static int me[1<<21];
	const int M = 1<<20;
	for(int i=1; i<=2*n; ++i) {
		int v = M+col[i];
		for(int j=0; j<10; ++j) {
			int a = v&(1<<(19-j)), b = v&(1<<j);
			v^=a; v^=b;
			if (a) v^=(1<<j);
			if (b) v^=(1<<(19-j));
		}
		if (me[v]) {
			event[20].eb(me[v], i);
		} else me[v] = i;
	}

	for(int i=M-1, lev=19; 1<=i; --i) {
		int a = me[i*2], b = me[i*2+1];
		if (a && b) {
			event[lev].eb(a, b);
			me[i] = a;
		} else if (a|=b) me[i] = a;
		if (!(i&(i-1))) --lev;
	}
}

struct UF {
	int p[mn2], nxt[mn2], lst[mn2], sz[mn2];
	int r(int x){ return (p[x] == x) ? x : (p[x]=r(p[x])); }

	void init(){
		iota(p+1, p+2*n+1, 1);
		iota(lst+1, lst+2*n+1, 1);
		fill(sz+1, sz+2*n+1, 1);
	}

	int join(int a, int b) {
		a = r(a); b = r(b);
		if (a == b) return 0;
		p[a] = b; sz[b] += sz[a];
		nxt[lst[b]]=a; lst[b]=lst[a];
		return b;
	}
} uf, uf2;

vector<int> edge[mn2*2];
int ei[mn2*2];
int hist[mn2], an;

void dfs(int x, int p) {
	if (ei[x] == sz(edge[x])) return;
	for(;ei[x]<sz(edge[x]);) {
		int y=edge[x][ei[x]++];
		if (y == p) continue;
		dfs(y, x);
	}
	if (x <= 2*n)
		hist[++an] = x;
}

int main()
{
	cppio(); cin >> n;
	rrep(i, 2*n) cin >> col[i];

	E();
	uf.init();
	uf2.init();
	rrep(i, n) uf.join(2*i-1, 2*i);

	for(int lev=20; 0<=lev; --lev) {
		for(auto [a, b]:event[lev]) {
			uf.join(a, b);
			uf2.join(a, b);
		}

		if(uf.sz[uf.r(1)] == 2*n && []{
			for(int i=1; i<=2*n; ++i) {
				int u = uf2.r(i);
				if (uf2.sz[u]&1) return false;
			}
			return true;
		}()) {
			cout << (lev) << '\n';

			for(int i=1; i<=2*n; ++i)
				edge[i].pb(1+((i-1)^1));

			for(int i=1; i<=2*n; ++i) if (uf2.p[i] == i) {
				for(int j=i; j; j=uf2.nxt[j]) {
					edge[2*n+i].pb(j);
					edge[j].pb(2*n+i);
				}
			}

			dfs(1, -1);

			if (1+((hist[1]-1)^1) != hist[2])
				rotate(hist+1, hist+2, hist+2*n+1);

			rrep(i, 2*n) cout << hist[i] << (i==2*n ? '\n':' ');

			return 0;
		}
	}

	return 0;
}