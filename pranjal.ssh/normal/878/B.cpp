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

ll n, k, m;
vector<ii> a;


ll solve(int l, int r) {
	if (l > r) return 0;
	if (l == r) return (a[l].S*m)%k;
	if (l == r || a[l].F != a[r].F) {
		int sum = 0; FOR (i, l, r) sum += a[i].S;
		return sum*m;
	}
	ll x = (a[0].S + a.back().S) % k;
	if (x == 0) {
		ll y = solve(l+1, r-1);
		if (y == 0) return x;
		return a[0].S + y + a.back().S;
	}
	int sum = 0; FOR (i, 1, sz(a)-2) sum += a[i].S;
	return a[0].S + sum*m + x*(m-1) + a.back().S;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> m;
	FOR (i, 0, n - 1) {
		int x; cin >> x;
		if (a.empty() or a.back().F != x) {
			a.emplace_back(x, 1);
		} else {
			a.back().S++;
			if (a.back().S == k) a.pop_back();
		}
	}
	cout << solve(0, sz(a) - 1);

	return 0;
}