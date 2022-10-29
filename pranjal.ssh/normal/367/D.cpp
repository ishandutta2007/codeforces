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

	int n, m, d; cin >> n >> m >> d;
	vi a(n);
	FOR (i, 0, m - 1) {
		int s; cin >> s;
		FOR (j, 0, s - 1) {
			int x; cin >> x; --x;
			a[x] = i;
		}
	}

	vi f(m);
	FOR (i, 0, d - 1) f[a[i]]++;
	vi chi(1 << m);
	FOR (i, 0, n - 1) {
		int j = i + d - 1;
		if (j >= n) break;
		if (i) {
			f[a[j]]++;
			f[a[i-1]]--;
		}
		int mask = (1 << m) - 1;
		FOR (k, 0, m - 1) if (f[k]) mask ^= (1 << k);
		chi[mask] = 1;
	}
	NFOR (i, (1 << m) - 1, 0) {
		FOR (j, 0, m - 1) chi[i] |= chi[i | (1 << j)];
	}
	int ans = m;
	FOR (i, 0, (1 << m) - 1) if (!chi[i]) ans = min(ans, __builtin_popcount(i));
	cout << ans;

	return 0;
}