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


template<class T>
struct Spt {
	vector<T> a;
	vector<vector<int>> dp;
	int n;
	Spt(const vector<T> &a) : a(a), dp(21), n(a.size()) {
		FOR (i, 0, 20) dp[i].resize(n);
		FOR (i, 0, n - 1) dp[0][i] = i;
		FOR (i, 1, 20) {
			FOR (j, 0, n - 1) if (j + (1 << i) <= n) {
				int x = dp[i-1][j];
				int y = dp[i-1][j + (1<<(i-1))];
				dp[i][j] = a[x] < a[y] ? x : y;
			}
		}
	}
	int rmq(int i, int j) {
		int lg = 31 - __builtin_clz(j-i+1);
		int x = dp[lg][i];
		int y = dp[lg][j - (1 << lg) + 1];
		return a[x] < a[y] ? x : y;
	}
};

#define get(i) (i >= 0 ? dp[i] : 0)
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, c; cin >> n >> c;
	vi a(n);
	vector<ll> dp(n);
	FOR (i, 0, n-1) cin >> a[i];
	Spt<int> spt(a);
	FOR (i, 0, n - 1) {
		dp[i] = get(i-1);
		if (i-c+1 >= 0) dp[i] = max(dp[i], get(i-c) + a[spt.rmq(i-c+1, i)]);
	}
	cout << accumulate(all(a), 0LL) - dp[n-1];


	return 0;
}