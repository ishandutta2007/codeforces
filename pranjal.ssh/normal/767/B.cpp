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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]" << endl;}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	ll ts, tf, t; cin >> ts >> tf >> t;
	int n; cin >> n;
	map<ll, int> mp;
	set<ll> s;
	int x = 0;
	FOR (i, 0, n - 1) {
		ll t; cin >> t;
		x += t <= ts;
		mp[t]++;
	}
	if (n==0) {
		cout<<ts<<"\n";;
		return 0;
	}
	pair<ll, ll> ans(1e18, -1);
	ans = min(ans, make_pair(ts + mp[0]*t, 0LL));
	if (ts + x*t + t <= tf)
		ans = min(ans, make_pair(x*t, ts));

	int no = 0;
	for (auto it : mp) {
		if (it.S == 0) continue;
		if (it.F >= ts) {
			while (not s.empty() and * s.begin() < it.F) {
				no--;
				if (no) s.insert(t + *s.begin());
				else if (*s.begin() + t <= tf) {
					ans.F = 0, ans.S = *s.begin();
				}
				s.erase(s.begin());
			}
			if (it.F - 1 >= 0 and it.F + no * t + t - 1 <= tf)
				ans = min(ans, make_pair(no ? (no-1)*t + (*s.begin()-it.F+1): 0LL, it.F - 1));
			no += it.S;
			if (s.empty()) s.insert(it.F + t);
			while (not s.empty() and *s.begin() <= it.F) {
				no--;
				if (no) s.insert(t + *s.begin());
				else if (*s.begin() + t <= tf) {
					ans.F = 0, ans.S = *s.begin();
				}
				s.erase(s.begin());
			}
			if (it.F + no * t + t <= tf)
				ans = min(ans, make_pair(no ? (no-1)*t + (*s.begin()-it.F): 0LL, it.F));
		}
		else {
			if (it.F - 1 >= 0 and no*t + ts + t <= tf)
				ans = min(ans, make_pair(ts - it.F + 1 + no*t, it.F - 1));
			no += mp[it.F];
			s.insert(ts + t);
			if (no*t + ts + t <= tf)
				ans = min(ans, make_pair(ts - it.F + no*t, it.F));
		}
	}
	while (not s.empty()) {
		no--;
		if (no) s.insert(t + *s.begin());
		else if (*s.begin() + t <= tf) {
			ans.F = 0, ans.S = *s.begin();
		}
		s.erase(s.begin());
	}
	cout << ans.S << "\n";


	return 0;
}