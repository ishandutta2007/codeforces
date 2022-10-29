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


char a[555][555];
int val[555][555];
int dp[555][555];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, K; cin >> n >> m >> K;
	FOR (i, 0, n - 1) {
		int sum = 0;
		FOR (j, 0, m - 1) {
			cin >> a[i][j];
			a[i][j] -= '0';
			sum += a[i][j];
		}

		FOR (j, 0, m) val[i][j] = m;
		FOR (j, 0, m - 1) {
			int here = 0;
			FOR (k, j, m - 1) {
				here += a[i][k];
				val[i][sum - here] = min(val[i][sum - here], k - j + 1);
			}
		}
		FOR (j, sum, m) val[i][sum] = 0;
		FOR (j, 0, K) {
			dp[i][j] = dp[i-1][j] + m;
			FOR (k, 0, min(j, m)) {
				dp[i][j] = min(dp[i][j], dp[i-1][j-k] + val[i][k]);
			}
		}
	}

	cout << *min_element(dp[n-1], dp[n-1]+K+1);

	return 0;
}