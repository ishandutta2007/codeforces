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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector<ii> e;
	vi d(n);
	vector<vi> g(n);
	FOR (i, 0, m - 1) {
		int x, y; cin >> x >> y; --x, --y;
		e.emplace_back(x, y);
		d[x]++, d[y]++;
		g[x].push_back(y), g[y].push_back(x);
	}
	vi rm, taken(n, 1);
	FOR (i, 0, n - 1) if (d[i] < k) rm.push_back(i), taken[i] = 0;
	while (!rm.empty()) {
		int x = rm.back(); rm.pop_back();
		for (int y : g[x]) {
			--d[y];
			if (taken[y] == 1 and d[y] < k) {
				taken[y] = 0;
				rm.push_back(y);
			}
		}
	}
	int no = accumulate(all(taken), 0);

	reverse(all(e));
	vector<int> ans;
	set<ii> er;
	for (auto it : e) {
		ans.push_back(no);
		int x = it.F, y = it.S;
		er.insert({x, y}); er.insert({y, x});
		if (!(taken[x] and taken[y])) continue;
		d[x]--, d[y]--;
		if (d[x] < k) rm.push_back(x), --no, taken[x] = 0;
		if (d[y] < k) rm.push_back(y), --no, taken[y] = 0;
		while (!rm.empty()) {
			int x = rm.back(); rm.pop_back();
			for (int y : g[x]) if (!er.count({x, y})) {
				--d[y];
				if (taken[y] == 1 and d[y] < k) {
					taken[y] = 0;
					--no;
					rm.push_back(y);
				}
			}
		}
	}
	reverse(all(ans));
	for (int i : ans) cout << i << "\n";


	return 0;
}