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

	int n, r; cin >> n >> r; ll k; cin >> k;
	vector<ll> a(n); FOR (i, 0, n - 1) cin >> a[i];
	ll st = 0, en = 2e18;
	vector<ll> b = a;
	while (st < en) {
		ll K = k;
		ll mid = (st + en + 1) >> 1;
		bool can = true;
		int curL = 0, curR = 0;
		ll sum = a[0];
		FOR (i, 0, n - 1) {
			int L = max(0, i - r);
			int R = min(n - 1, i + r);
			while (R > curR) sum += a[++curR];
			while (L > curL) sum -= a[curL++];
			if (sum < mid) {
				ll val = mid - sum;
				K -= val;
				a[R] += val;
				sum += val;
				if (K < 0) {can = false; break;}
			}
		}
		FOR (i, 0, n - 1) a[i] = b[i];
		if (can) st = mid;
		else en = mid - 1;
	}
	cout << st;

	return 0;
}