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
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

vector<vi> g;
vector<ll> w, p, rd, sub;
vector<ii> order;
void check(int i) {
	for (int j : g[i]) {
		check(j);
		sub[i] += sub[j] + w[j] - rd[j];
	}
	if (i and sub[i] > p[i]) {
		cout << "-1\n";
		exit(0);
	}
	rd[i] = min(p[i] - sub[i], w[i] - 1);
}

ll rectify(int i, ll le) {
	ll x = rd[i];
	rd[i] = max(0LL, rd[i] - le);
	le -= x - rd[i];
	ll sum = x - rd[i];
	le = min(le, p[i] - sub[i]);
	for (int j : g[i]) {
		ll now = rectify(j, le);
		le -= now;
		sum += now;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	g = vector<vi>(n);
	sub = w = p = rd = vector<ll>(n);
	FOR (i, 0, n - 2) {
		int X, Y, W, P; cin >> X >> Y >> W >> P; --X, --Y;
		g[X].push_back(Y);
		w[Y] = W;
		p[Y] = P;
		order.push_back({X, Y});
	}
	check(0);
	for (int i : g[0]) rectify(i, 1e18);
	cout << n << "\n";
	for (ii it : order) {
		cout << it.F + 1 << " " << it.S + 1 << " " << w[it.S] - rd[it.S] << " " << p[it.S] - rd[it.S] << "\n";
	}
	return 0;
}