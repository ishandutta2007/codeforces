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

	int n, U; cin >> n >> U;
	vi e(n); FOR (i, 0, n -1) cin >> e[i];
	bool can = false;
	FOR (i, 0, n - 1) {
		if (i + 2 < n) {
			if (e[i + 2] - e[i] <= U) can = true;
		}
	}
	if (not can) return cout << "-1\n", 0;
	double st = 0, en = 1e9;
	FOR (_, 1, 100) {
		double mid = (st + en) / 2;
		int j = 0;
		bool yo = false;
		FOR (i, 0, n - 1) {
			while (j + 1 < n and e[j + 1] - e[i] <= U) ++j;
			if (j - i >= 2) {
				if ((mid-1)*e[i+2] + e[i+1] <= mid*e[i]) {	
					yo = true;
				}
				if ((mid - 1) * e[j] + e[i+1] <= mid*e[i]) {
					yo = true;	
				}
			}
		}
		if (yo) st = mid;
		else en = mid;
	}
	cout << fixed << setprecision(10) << st;

	return 0;
}