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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	
	set<int> cand;
	FOR(i,1,n) cand.insert(i);

	vi a(m+1);
	vi vis(n+1);
	int yo = -1;
	set<int> cur;
	FOR(i,1,m) {
		char ch; int id; cin >> ch >> id;

		if (ch == '-') id *= -1;
		a[i] = id;
		cand.erase(abs(id));
		if (a[i] < 0 and vis[-id] == 0) cur.insert(-id), yo = -id;
		if (id < 0) vis[-id] = 0;
		else vis[id] = 1;
	}
	if (yo == -1) yo = a[1];

	bool can = true;

	FOR (i, 1, m) {
		if (a[i] < 0) cur.erase(-a[i]);
		else cur.insert(a[i]);
		if (!cur.empty())
		can &= cur.count(yo);
	}
	if (can) cand.insert(yo);

	cout << sz(cand) << "\n";
	for (int x : cand) cout << x << " ";
	



	return 0;
}