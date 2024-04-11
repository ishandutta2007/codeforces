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

	int n, m; cin >> n >> m;
	vi a(m), l(m), r(m);
	vi L(n), R(n);
	FOR (i, 0, n - 1) {
		cin >> L[i] >> R[i]; --L[i], --R[i];
		a[L[i]]++;
		if (R[i] + 1 < m) a[R[i]+1]--;
	}
	FOR (i, 1, m - 1) a[i] += a[i - 1];

	vi dp{-inf};
	FOR (i, 0, m - 1) {
		auto it = upper_bound(all(dp), a[i]);
		if (it == dp.end()) dp.push_back(a[i]), it = dp.end() - 1;
		else *it = min(*it, a[i]);
		l[i] = it - dp.begin();
	}
	
	dp = {-inf};
	int ans = 0;
	NFOR (i, m - 1, 0) {
		auto it = upper_bound(all(dp), a[i]);
		if (it == dp.end()) dp.push_back(a[i]), it = dp.end() - 1;
		else *it = min(*it, a[i]);
		r[i] = it - dp.begin();	
		ans = max(ans, l[i] + r[i] - 1);
	}
	
	cout << ans;



	return 0;
}