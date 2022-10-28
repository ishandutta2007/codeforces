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


int f[1 << 19], mf[1 << 19];
#define get(f, it, mx) (((it) >= 0 and (it) <= mx) ? f[it] : 0)

vi solve(int mx) {
	if (mx == 0) return {};
	if (mx == 1) {
		vi ans;
		if (f[1]) ans.push_back(1);
		if (mf[1]) ans.push_back(-1);
		return ans;
	}
	int val = 0;
	bool must = false;
	FOR (it, 0, mx) {
		if (f[it] or mf[it]) {
			if (it & 1) {must = true; break;}
		}
	}
	
	vi tf(f, f + mx + 1), tmf(mf, mf + mx + 1);
	int x = 0;
	FOR (it, 0, mx) {
		f[it] = get(f, 2 * it, mx) + get(f, it * 2 + 1, mx);
		if (f[it]) x = max(x, it);
		
		mf[it] = get(mf, 2 * it, mx) + get(mf, it * 2 - 1, mx);
		if (mf[it]) x = max(x, it);
	}
	auto c1 = solve(x);
	for (int &i : c1) i *= 2;
	if (must) c1.push_back(1);
	val = sz(c1);

	if (must) {
		FOR (it, 0, mx) f[it] = tf[it], mf[it] = tmf[it];
		x = 0;
		FOR (it, 0, mx) {
			f[it] = get(f, 2 * it, mx) + get(f, it * 2 - 1, mx);
			if (f[it]) x = max(x, it);

			mf[it] = get(mf, 2 * it, mx) + get(mf, it * 2 + 1, mx);
			if (mf[it]) x = max(x, it);

		}
		auto c2 = solve(x);
		for (int &i : c2) i *= 2;
		c2.push_back(-1);
		if (val > sz(c2)) {
			c1 = c2;
		}
	}
	FOR (it, 0, mx) f[it] = tf[it], mf[it] = tmf[it];
	return c1;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	int mx = 0;
	vi a(n); FOR (i, 0, n - 1) {
		cin >> a[i];
		if (a[i] >= 0) f[a[i]] = 1;
		else mf[-a[i]] = 1;
		mx = max(mx, abs(a[i]));
	}
	vi ans = solve(mx);

	cout << sz(ans) << "\n";
	for (int i : ans) cout << i << " ";

	return 0;
}