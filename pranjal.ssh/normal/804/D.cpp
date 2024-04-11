#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}


const int N = 1e5 + 10;
vi g[N];
int sz[N], p[N], lup[N], l[N], d[N];
vector<ll> qs[N], qf[N];
ii ld1[N], ld2[N];
int ctr;

void dfs(int i, int par) {
	p[i] = ctr;
	sz[ctr]++;
	for (int j: g[i]) if (j ^ par) {
		dfs(j, i);
		ii now(ld1[j].F + 1, j);
		if(now > ld1[i]) {
			ld2[i] = ld1[i], ld1[i] = now;
		}
		else if (now > ld2[i]) {
			ld2[i] = now;
		}
	}
}

void dfsfir(int i, int par) {
	l[i] = max(ld1[i].F, lup[i]);
	d[ctr] = max(d[ctr], l[i]);
	qf[ctr][l[i]]++;
	for (int j: g[i]) if (j ^ par) {
		lup[j] = max(1 + lup[i], 1 + (ld1[i].S == j ? ld2[i].F : ld1[i].F));
		dfsfir(j, i);
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, q; cin >> n >> m >> q;
	while (m--) {
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	ctr = 0;
	FOR (i, 1, n) if (p[i] == 0) {
		++ctr;
		dfs(i, 0);
		qs[ctr].resize(sz[ctr] + 10);
		qf[ctr] = qs[ctr];
		dfsfir(i, 0);
		NFOR (i, sz[ctr], 0) {
			qs[ctr][i] = qs[ctr][i + 1] + qf[ctr][i] * i;
			qf[ctr][i] += qf[ctr][i + 1];
		}
	}

	map<ii, double> mp;	
	while (q--) {
		int u, v; cin >> u >> v;
		int x = p[u], y = p[v];
		if (x == y) {
			cout << "-1\n";
			continue;
		}
		if (sz[x] > sz[y]) swap(x, y);
		if (mp.count(ii(x, y))) {
			cout << fixed << setprecision(10) << mp[{x, y}] << "\n";
			continue;
		}
		double & ans = mp[{x, y}];
		ans = 0;
		ll num = 0, denom = 0;
		int D = max(d[x], d[y]);
		int no = sz[x];
		NFOR (i, no, 0) {
			if (D - i > sz[y]) {
				break;
			}
			num += (qf[x][i] - qf[x][i + 1]) * qs[y][max(0,D-i)];
			num += (qf[x][i] - qf[x][i + 1]) * (qf[y][max(0,D-i)]) * (i + 1);
			denom += (qf[x][i] - qf[x][i + 1]) * (qf[y][max(0,D-i)]);
		}
		ll tot = sz[x] * 1LL * sz[y];
		num += (tot - denom) * D;
		ans = num;
		ans /= tot;
		cout << fixed << setprecision(10) << ans << "\n";
	}
	return 0;
}