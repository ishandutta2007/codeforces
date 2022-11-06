#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define pb push_back

const int maxn = int(5e5)+10;
int n, m, k;
int col[maxn];
bool hasoc[maxn];
bool voc[maxn];
bool moc[maxn];

struct UF {
	int p[maxn];
	int r(int x) { return (x == p[x]) ? x : (p[x] = r(p[x])); }
	void init() { iota(p+1, p+n+1, 1); }
	bool join(int a, int b) {
		a = r(a); b = r(b);
		if (a == b) return false;
		p[a] = b; return true;
	}
} sc;

struct UF2 {
	int p[maxn];
	int e[maxn];
	int r(int x) { return (x == p[x]) ? x : (p[x] = r(p[x])); }
	void init(int n) { iota(p+1, p+n+1, 1); fill(e+1, e+n+1, 0); }
	bool join(int a, int b) {
		a = r(a); b = r(b);
		if (a == b) return true;
		if (e[a] == b) return false;
		p[a] = b;

		int ea = e[a], eb = e[b];
		if (ea && eb) e[b] = p[ea] = eb;
		else e[b] = (ea | eb);
		if (e[b]) { e[b] = r(e[b]); e[e[b]] = b; }
		return true;
	}

	bool dis(int a, int b) {
		a = r(a); b = r(b);
		if (a == b) return false;
		if (e[a] == b) return true;
		int ea = e[a], eb = e[b];
		if (ea) p[ea] = b;
		if (eb) p[eb] = a;
		e[a] = b; e[b] = a;
		return true;
	}
} ufo;

vector<int> e[maxn];
vector<int> cm[maxn];

void doc(int x) {
	voc[x] = 1;
	for(int y:e[x]) {
		if (col[y] != col[x]) continue;
		if (!voc[y]) { moc[y]=!moc[x]; sc.join(x, y); doc(y); }
		else if(moc[y] == moc[x]) { hasoc[col[x]] = 1; }
	}
}

ll dpair;

void occ() {
	ll dc = 0;
	sc.init();
	for(int c=1; c<=k; ++c) {
		for(int x:cm[c]) if (!voc[x]) doc(x);
		if (hasoc[c]) ++dc;
	}
	dpair += dc*(dc-1)/2 + dc * (k-dc);
}

pp el[maxn];

map<pp, vector<int>> cmap;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i) {
		cin >> col[i];
		cm[col[i]].pb(i);
	}

	for(int i=1; i<=m; ++i) {
		int a, b; cin >> a >> b;
		if(col[a]>col[b]) swap(a, b);
		e[a].pb(b); e[b].pb(a);

		el[i] = {a, b};
		cmap[pp{col[a], col[b]}].pb(i);
	}

	occ();

	for(auto &tmp:cmap) {
		auto [c1, c2] = tmp.x;
		if (hasoc[c1] || hasoc[c2]) continue;
		static vector<int> vl; vl.clear();

		dpair += [&]()->int {
		map<int, vector<int>> gvs;
		for (int ei:tmp.y) {
			auto [x, y] = el[ei];
			vl.pb(x); vl.pb(y);
		}
		sort(all(vl)); vl.erase(unique(all(vl)), vl.end());
		int vn = vl.size();
		ufo.init(vn);
		for(int i=0; i<vn; ++i) {
			int v = vl[i];
			gvs[sc.r(v)].pb(v);
		}
		for(auto &tt:gvs) {
			auto &u = tt.y;
			int us = u.size();
			for(int i=1; i<us; ++i) {
				int a = u[i-1], b = u[i];
				int va = lower_bound(all(vl), a) - vl.begin() + 1;
				int vb = lower_bound(all(vl), b) - vl.begin() + 1;
				if (moc[a] == moc[b]) ufo.join(va, vb);
				else ufo.dis(va, vb);
			}
		}

		for(int ei:tmp.y) {
			auto [x, y] = el[ei];
			x = lower_bound(all(vl), x) - vl.begin() + 1;
			y = lower_bound(all(vl), y) - vl.begin() + 1;
			if (!ufo.dis(x, y)) return 1;
		}
		return 0;
		}();
	}

	ll ans = k * (k-1ll) / 2 - dpair;
	cout << ans << endl;
	
	return 0;
}