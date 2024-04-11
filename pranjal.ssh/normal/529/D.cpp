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

const int N = 86400;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, M, T; cin >> n >> M >> T;

	vector<int> a(N+1);

	FOR (i, 0, n - 1) {
		string s; cin >> s;
		int x = stoi(s.substr(0, 2))*3600 + stoi(s.substr(3, 2))*60 + stoi(s.substr(6, 2));
		a[x+1]++;
	}


	vector<vi> ans(N+1);
	int ctr = 0;
	map<int, int> s;

	FOR (i, 1, T) {
		FOR (it, 1, a[i]) {
			if (sz(s) < M) ++ctr;
			ans[i].push_back(ctr);
			s[ctr]++;
		}
	}
	bool can = false;
	can |= sz(s) == M;

	FOR (i, T + 1, N) {
		for (int x : ans[i - T]) {
			s[x]--;
			if (s[x] == 0) s.erase(x);
		}
		FOR (it, 1, a[i]) {
			if (sz(s) < M) ++ctr;
			ans[i].push_back(ctr);
			s[ctr]++;
		}
		can |= sz(s) == M;
	}
	if (not can) return cout << "No solution\n", 0;
	cout << ctr << "\n";
	FOR (i, 1, N) for (int j : ans[i]) cout << j << "\n";


	return 0;
}