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

#define NO return cout << "0", 0
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	set<int> B, S;
	set<int> active;
	int ans = 1;
	FOR (i, 0, n - 1) {
		string s; int x;
		cin >> s >> x;
		if (s == "ADD") {
			if (!B.empty() and x <= *(--B.end())) {
				B.insert(x);
			} else if (!S.empty() and x >= *(S.begin())) {
				S.insert(x);
			} else {
				active.insert(x);
			}
		} else {
			if (!B.empty() and *(--B.end()) > x) NO;
			if (!S.empty() and *(S.begin()) < x) NO;
			if (!B.count(x) and !S.count(x)) {
				ans += ans;
				if (ans >= inf) ans -= inf;
			}
			B.erase(x), S.erase(x);
			active.erase(x);
			for (auto it : active) {
				if (it < x) B.insert(it);
				else S.insert(it);
			}
			active.clear();
		}
	}
	ans = (ans * 1LL * (sz(active) + 1)) % inf;
	cout << ans << "\n";


	return 0;
}