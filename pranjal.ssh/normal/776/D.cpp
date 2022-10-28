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
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}

struct dis_set
{
	vi p, r;
	vector<vi> col, vert;
	vi ind;
	dis_set(int n):p(n),r(n), col(n),vert(n),ind(n){FOR(i, 0, n - 1)p[i] = i, col[i].push_back(0), vert[i]={i}, ind[i] = 0;}

	int get(int i)
	{
		if (p[i] != i)p[i] = get(p[i]);
		return p[i];
	}
	int connect(int i, int j)
	{
		int x = get(i), y = get(j);
		if (x == y) {
			if (col[x][ind[i]] != col[x][ind[j]]) {
				cout << "NO\n";
				exit(0);
			}
			return 0;
		}
		int c1 = col[x][ind[i]];
		int c2 = col[y][ind[j]];
		if (r[x] < r[y])swap(x,y),swap(i,j);
		// else {
			p[y] = x;
			for (auto it : vert[y]) vert[x].push_back(it);
			int t = sz(col[x]);
			for (auto it : col[y]) col[x].push_back(it ^ (c1 != c2));
			for (auto it : vert[y]) ind[it] = t, t++;
			if (r[x] == r[y])++r[x];
		// }
		return 1;
	}
	int connect2(int i, int j)
	{
		int x = get(i), y = get(j);
		if (x == y) {
			if (col[x][ind[i]] == col[x][ind[j]]) {
				cout << "NO\n";
				exit(0);
			}
			return 0;
		}
		int c1 = col[x][ind[i]];
		int c2 = col[y][ind[j]];
		if (r[x] < r[y])swap(x,y),swap(i,j);
		// else {
			p[y] = x;
			for (auto it : vert[y]) vert[x].push_back(it);
			int t = sz(col[x]);
			for (auto it : col[y]) col[x].push_back(it ^ (c1 == c2));
			for (auto it : vert[y]) ind[it] = t, t++;
			if (r[x] == r[y])++r[x];
		// }
		return 1;
	}
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vi r(n); FOR (i, 0, n - 1) cin >> r[i];

	vector<vi> d(n);
	
	FOR (i, 0, m - 1) {
		int x; cin >> x;
		while (x--) {
			int y; cin >> y; --y;
			d[y].push_back(i);
		}
	}


	
	dis_set dsu(m);
	FOR (i, 0, n - 1) {
		if (r[i]) {
			dsu.connect(d[i][0], d[i][1]);
		}
		else {
			dsu.connect2(d[i][0], d[i][1]);
		}
	}
	cout << "YES\n";

	return 0;
}