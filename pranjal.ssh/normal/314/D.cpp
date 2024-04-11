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

	int n; cin >> n;
	vector<pair<ll,ll>> a(n);
	FOR (i, 0, n - 1) {
		ll x, y; cin >> x >> y;
		a[i].F = -2LL*(x + y);
		a[i].S = -2LL*(x - y);
	}
	sort(all(a));
	vector<ll> pmn(n), pmx(n), smn(n), smx(n);
	FOR (i, 0, n - 1) {
		pmn[i] = pmx[i] = a[i].S;
		if (i) pmn[i] = min(pmn[i], pmn[i - 1]), pmx[i] = max(pmx[i], pmx[i - 1]);
	}
	NFOR (i, n - 1, 0) {
		smn[i] = smx[i] = a[i].S;
		if (i + 1 < n) smn[i] = min(smn[i], smn[i + 1]), smx[i] = max(smx[i], smx[i + 1]);
	}
	
	ll st = 0, en = 1e10;
	while (st < en) {
		ll k = (st + en) / 2;
		int j = 0;
		bool can = false;
		FOR (i, 0, n - 1) {
			while (j + 1 < n and k + a[i].F >= a[j+1].F - k) ++j;
			ll mn = 1e18, mx = -1e18;
			if (i) mn = min(mn, pmn[i - 1] - k);
			if (j + 1 < n) mn = min(mn, smn[j + 1] - k);
			if (i) mx = max(mx, pmx[i - 1] - k);
			if (j + 1 < n) mx = max(mx, smx[j + 1] - k);
			if (mn != 1e18) {
				can = (mx - mn <= 2*k);
				if (can) break;
			}
		}
		if (can) en = k;
		else st = k + 1;
	}
	cout << fixed << setprecision(10) << st/2.0;
	
	return 0;
}