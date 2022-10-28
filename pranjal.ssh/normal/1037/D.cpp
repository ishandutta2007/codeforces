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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

const int N = 2e5+10;
vector<vi> g;
int p[N];
void dfs(int i) {
	for (int j : g[i]) {
		g[j].erase(find(all(g[j]), i));
		dfs(j);
	}
}

bool solve(vi& a, int l, int r) {
	int j = r+1, n = sz(a);
	if (l > r or l >= n) return true;
	FOR (it, l, r) {
		int no = sz(g[a[it]]);

		if (j + no - 1 >= n) {
			return false;
		}
		vi temp(a.begin()+j, a.begin()+j+no);
		j += no;
		sort(all(temp));

		if (temp != g[a[it]]) {
			return false;
		}
	}
	return solve(a, r+1, j-1);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	g.resize(n);
	FOR (i, 1, n - 1) {
		int x, y; cin >> x >> y;
		--x, --y;
		g[x].push_back(y), g[y].push_back(x);
	}
	FOR (i, 0, n - 1) sort(all(g[i]));
	vi a(n);
	FOR (i, 0, n - 1) cin >> a[i], --a[i];
	p[0] = -1;
	dfs(0);
	if (a[0] != 0) {
		cout << "No\n";
		return 0;
	}
	cout << (solve(a, 0, 0) ? "Yes\n" : "No\n");

	return 0;
}