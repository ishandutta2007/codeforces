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

ll dp[1001][2001];
int n, k, p;
int a[1001], b[2001];

ll f(int i, int j) {
	if (i==n) return 0;
	if (j==k) return 1e18;
	ll &ans = dp[i][j];
	if (~ans) return ans;
	ans = min({max(abs(a[i]-b[j]) + abs(b[j]-p) +0LL, f(i+1, j+1)), f(i, j+1)});
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> p;
	FOR (i, 0, n-1) cin >> a[i];
	FOR (i, 0, k-1) cin >> b[i];
	sort(a,a+n), sort(b,b+k);

	memset(dp, -1LL, sizeof dp);
	cout << f(0, 0) << "\n";
	return 0;
}