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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vi s(m), d(m), c(m);
	set<int> e;
	FOR (i, 0, m - 1) cin >> s[i] >> d[i] >> c[i], e.insert(d[i]);

	vi op;

	FOR (i, 1, n) {
		int id = -1, md = inf;
		if (e.count(i)) {
			op.push_back(m + 1);
			continue;
		}
		FOR (it, 0, m - 1) if (s[it] <= i and d[it] > i and c[it]) {
			if (d[it] < md) id = it, md = d[it];
		}
		if (id == -1) op.push_back(0);
		else op.push_back(id + 1), c[id]--;
	}
	FOR (i, 0, m - 1) if (c[i]) {
		cout << "-1\n";
		return 0;
	}
	for (int i : op) cout << i << " ";

	return 0;
}