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

	string s; cin >> s;
	int n = s.length();
	list<ii> l;
	FOR (i, 0, n - 1) {
		if (l.empty() or l.back().F != s[i])
			l.emplace_back(s[i], 1);
		else
			l.back().S++;
	}


	int ans = 0;
	while (sz(l) > 1) {
		auto f = l.begin();
		for (auto it = l.begin(); it != l.end();) {
			if (it == f) {
				--it->S;
			} else {
				it->S -= 2;
			}
			auto itt = it;
			if ((++it) == l.end()) itt->S += 1;
			if (itt->S <= 0) l.erase(itt);
		}
		
		for (auto it = l.begin(); it != l.end();) {
			auto itt = it;
			++itt;
			if (itt != l.end() and itt->F == it->F) {
				itt->S += it->S;
				l.erase(it);
			}
			it = itt;
		}
		++ans;
	}
	cout << ans << "\n";

	return 0;
}