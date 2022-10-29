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

const int N = 1e5 + 10;
ll A[3][N];
ll dp[27][N];
int n;
const ll inf2 = 1e18;

ll f(int pos, vi a) {
	if (pos == n) {
		if (a == vi({0,0,1})) return 0;
		return -inf2;
	}
	ll & ans = dp[a[0] * 9 + a[1] * 3 + a[2]][pos];
	if (~ans) return ans;
	ans = -inf2;
	ll already = (a[0] > 0) * A[0][pos] + (a[1] > 0) * A[1][pos] + (a[2] > 0) * A[2][pos];
	ans = max(ans, already + f(pos + 1, a));

	if (a==vi({1,2,2}))
		ans = max(ans, already + f(pos + 1, vi({0, 0, 1})));
	
	if (a==vi({2,2,1}))
		ans = max(ans, already + f(pos + 1, vi({1, 0, 0})));
	
	if (a==vi({0,0,1}))
		ans = max(ans, already + A[0][pos] + A[1][pos] + f(pos + 1, vi({2, 2, 1})));
	
	if (a==vi({1,0,0}))
		ans = max(ans, already + A[2][pos] + A[1][pos] + f(pos + 1, vi({1, 2, 2})));
	

	if (a[0] + a[1] + a[2] == 1) {
		int i = find(all(a),1)-a.begin();
		ll sum = 0;
		FOR(j,i,2){
			sum += A[j][pos];
			a[i] = 0, a[j] = 1;
			ans = max(ans, sum + f(pos + 1, a));
			a[j] = 0, a[i] = 1;
		}
		sum=0;
		NFOR(j,i,0){
			sum += A[j][pos];
			a[i] = 0, a[j] = 1;
			ans = max(ans, sum + f(pos + 1, a));
			a[j] = 0, a[i] = 1;
		}
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR(i, 0, 2) FOR(j, 0, n - 1) cin >> A[i][j];

	memset(dp, -1LL, sizeof dp);
	ll ans = f(0, vi({1, 0, 0}));
	cout << ans << "\n";
	return 0;
}