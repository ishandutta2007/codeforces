#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

vector<vi> g;
int go(int u, int p) {
	if (sz(g[u]) > 2) return -1;
	if (sz(g[u]) == 1) return u;
	for (auto it : g[u]) if (it != p) {
			return go(it, u);
		}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	g.resize(n);
	vi d(n);
	FOR (i, 0, n - 2) {
		int a, b; cin >> a >> b;
		--a, --b;
		g[a].push_back(b), g[b].push_back(a);
		d[a]++, d[b]++;
	}
	int root = max_element(all(d)) - d.begin();
	vector<ii> ans;
	int poss = 1;
	for (auto it : g[root]) {
		int yo = go(it, root);
		if (yo == -1) poss = 0;
		else ans.emplace_back(root, yo);
	}
	if (poss) {
		cout << "Yes\n";
		cout << sz(ans) << "\n";
		for (auto it : ans) cout << it.F + 1 << " " << it.S + 1 << "\n";
	}
	else {
		cout << "No\n";
	}

	return 0;
}