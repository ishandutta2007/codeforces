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
typedef vector<ii> vii;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vii a(n);vi as(n); FOR (i, 0, n - 1) cin >> a[i].F >> a[i].S, as[i] = a[i].F;
	int m; cin >> m;
	vii b(m);vi bs(m); FOR (i, 0, m - 1) cin >> b[i].F >> b[i].S, bs[i] = b[i].F;

	sort(all(a)); sort(all(b));sort(all(as));sort(all(bs));
	int ans = 0;
	auto it = max_element(all(bs));
	FOR (i, 0, n - 1) {
		if (*it >= a[i].S)
			ans = max(ans, -a[i].S + *it);
	}
	it = max_element(all(as));
	FOR (i, 0, m - 1) {
		if (*it >= b[i].S)
			ans = max(ans, -b[i].S + *it);
	}
	cout<<ans;

	
	return 0;
}