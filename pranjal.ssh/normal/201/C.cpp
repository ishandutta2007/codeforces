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
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<ll> a(n);
	FOR (i, 1, n - 1) cin >> a[i];

	vector<ll> jal(n), jar(n), jalc(n), jarc(n);

	FOR (i, 1, n - 1) {
		if (a[i] & 1) {
			jal[i] = a[i] + max(jal[i - 1], jalc[i - 1]);
			if (a[i] > 1)
				jalc[i] = a[i] - 1 + jalc[i - 1];
		}
		else {
			jal[i] = a[i] - 1 + max(jal[i - 1], jalc[i - 1]);
			jalc[i] = a[i] + jalc[i - 1];	
		}
	}
	NFOR (i, n - 2, 0) {
		if (a[i + 1] & 1) {
			jar[i] = a[i + 1] + max(jar[i + 1], jarc[i + 1]);
			if (a[i + 1] > 1)
				jarc[i] = a[i + 1] - 1 + jarc[i + 1];
		}
		else {
			jar[i] = a[i + 1] - 1 + max(jar[i + 1], jarc[i + 1]);
			jarc[i] = a[i + 1] + jarc[i + 1];	
		}
	}
	ll ans = 0;
	FOR (i, 0, n - 1) {
		ans = max(ans, jalc[i] + jar[i]);
		ans = max(ans, jal[i] + jarc[i]);
		ans = max(ans, jalc[i] + jarc[i]);
	}
	cout << ans << "\n";

	return 0;
}