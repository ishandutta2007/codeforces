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

	int n; cin >> n;
	map<int, int> mp;
	FOR (i, 0, 7) mp[i] = 1e8;
	FOR (i, 0, n - 1) {
		int x; cin >> x;
		string s; cin >> s;
		int mask = 0;
		for (char ch : s) {
			mask |= (1 << (ch - 'A'));
		}
		mp[mask] = min(mp[mask], x);
	}

	mp[1] = min({mp[1], mp[3], mp[5], mp[7]});
	mp[2] = min({mp[2], mp[3], mp[6], mp[7]});
	mp[4] = min({mp[4], mp[5], mp[6], mp[7]});

	mp[3] = min({mp[7], mp[3], mp[1] + mp[2]});
	mp[5] = min({mp[7], mp[5], mp[4] + mp[1]});
	mp[6] = min({mp[7], mp[6], mp[4] + mp[2]});

	int ans = min({mp[7], mp[1] + mp[6], mp[2] + mp[5], mp[4] + mp[3]});
	if (ans >= 1e8) ans = -1;
	cout << ans;

	return 0;
}