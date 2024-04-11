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
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	ll n, k; cin >> n >> k;
	vector<ll> a(n + 1), p(n + 1);
	FOR (i, 1, n) cin >> a[i], p[i] = p[i - 1] + a[i];

	map<ll, ll> mp;
	mp[0]++;
	ll ans = 0;
	FOR (i, 1, n) {
		if (k == 1) {
			ans += mp[p[i]-1];
		}
		else if (k == -1) {
			ans += mp[p[i]-1];
			ans += mp[p[i]+1];	
		}
		else {
			ll st = 1;
			while (1) {
				ans += mp[p[i]-st];
				st *= k;
				if (abs(st) > 1e15) break;
			}
		}
		mp[p[i]]++;
	}
	cout << ans;

	return 0;
}