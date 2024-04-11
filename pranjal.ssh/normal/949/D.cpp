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

	int n, D, b; cin >> n >> D >> b;

	vi a(n); FOR (i, 0, n - 1) cin >> a[i];
	int st = 0, en = n/2+1;
	while (st < en) {
		int mid = (st + en) >> 1;
		int l = mid, r = n-1-mid;
		
		deque<ii> d; FOR (i, 0, n - 1) d.emplace_back(i, a[i]);
		bool can = 1;

		while (l <= r) {
			int tl = l;
			int tr = n-1-r;
			// pr(l, r);
			if (tr < tl) {
				int need = b;
				while (need and (abs(d.back().F - r)+D-1)/D <= n - r) {
					int take = min(need, d.back().S);
					d.back().S -= take, need -= take;
					if (d.back().S == 0) d.pop_back();
				}
				if (need) {can = false; break;}
				--r;
			} else {
				int need = b;
				while (need and (abs(d.front().F - l)+D-1)/D <= l + 1) {
					int take = min(need, d.front().S);
					d.front().S -= take, need -= take;
					if (d.front().S == 0) d.pop_front();
				}
				if (need) {can = false; break;}
				++l;
			}
		}
		if (can) en = mid;
		else st = mid + 1;
	}
	cout << st;


	return 0;
}