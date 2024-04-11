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


int get(int x, int a) {
	if (x < 0 or x > a) return inf;
	if (x == 0) return a;
	if (x == a) return 1;
	if (x*((a+x)/(x+1)) <= a) return (a+x)/(x+1);
	return inf;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vi a(n); FOR (i, 0, n - 1) cin >> a[i];
	ll yo = 1e18;
	FOR (i, 1, 40000) {
		ll ans = 0;
		FOR (j, 0, n - 1) {
			int x = get(i, a[j]);
			if (x == inf) break;
			ans += x;
			if (j == n - 1) {
				yo = min(yo, ans);
			}
		}
	}
	FOR (i, 1, 40000) {
		ll ans = 0;
		FOR (j, 0, n - 1) {
			int x = get(a[0]/i, a[j]);
			if (x == inf) break;
			ans += x;
			if (j == n - 1) {
				yo = min(yo, ans);
			}
		}
	}
	FOR (i, 1, 40000) {
		ll ans = 0;
		FOR (j, 0, n - 1) {
			int x = get(a[0]/i-1, a[j]);
			if (x == inf) break;
			ans += x;
			if (j == n - 1) {
				yo = min(yo, ans);
			}
		}
	}
	cout << yo << "\n";

	return 0;
}