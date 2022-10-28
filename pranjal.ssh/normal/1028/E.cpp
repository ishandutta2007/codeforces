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
	vector<ll> a(n);
	FOR (i, 0, n - 1) cin >> a[i];
	int mx = *max_element(all(a));
	vector<ll> b(n);
	if (mx == 0) {
		cout << "YES\n";
		FOR (i, 0, n - 1) cout << "1 ";
		return 0;
	}
	int pos = -1;
	FOR (i, 0, n - 1) if (a[i] == mx and a[(i-1+n)%n] != mx) pos = i;
	if (pos == -1) {
		cout << "NO\n";
		return 0;
	}
	b[pos] = a[pos];
	FOR (i, 1, n - 1) {
		int it = (pos - i + n) % n;
		int itt = (pos - i + n + 1) % n;
		b[it] = b[itt] + a[it];
		if (i == 1 and b[it] == mx) {
			b[it] = 2*b[itt] + a[it];
		}
	}
	cout << "YES\n";
	FOR (i, 0, n - 1) cout << b[i] << " ";

	return 0;
}