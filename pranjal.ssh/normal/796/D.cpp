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

vector<vector<ii>> g;
vector<ii> cl;
vi P;

void dfs(int i, int par) {
	if (P[i]) {
		cl[i] = {0, i};
	}
	for (ii &k: g[i]) {
		int j = k.F;
		if (j == par) continue;
		dfs(j, i);
		cl[i] = min(cl[i], ii(cl[j].F + 1, cl[j].S));
	}
}
void dfs2(int i, int par) {
	if (par != -1) {
		cl[i] = min(cl[i], ii(cl[par].F + 1, cl[par].S));
	}
	for (ii &k: g[i]) {
		int j = k.F;
		if (j == par) continue;
		dfs2(j, i);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k, d; cin >> n >> k >> d;
	vi p(k);
	P = vi(n);
	for (int &i : p) {
		cin >> i;
		--i;
		P[i] = 1;
	}
	sort(all(p)); p.erase(unique(all(p)), p.end());
	k = sz(p);
	
	g.resize(n);
	FOR (i, 1, n-1) {
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].push_back({v, i}), g[v].push_back({u, i});
	}
	cout << k-1 << "\n";
	cl.resize(n);
	FOR (i, 0, n - 1) cl[i] = {inf, -1};

	dfs(0, -1);dfs2(0, -1);
	
	FOR (i, 0, n - 1) {
		for (ii j: g[i]) {
			if (i < j.F and cl[i].S != cl[j.F].S) {
				cout << j.S << " ";
			}
		}
	}
	return 0;
}