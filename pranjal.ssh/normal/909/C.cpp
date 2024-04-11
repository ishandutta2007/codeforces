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

char a[5012];
int dp[5012][5012];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	
	FOR (i, 1, n) cin >> a[i];

	NFOR (i, n, 1) {
		NFOR (j, n, 0) {
			int &ans = dp[i][j];
			if (i == n) {
				ans = (j<=1);
				continue;
			}
			if (a[i] == 'f') {
				ans = dp[i][j+1];
				if (j)
					ans += dp[i+1][j];
				if (ans >= inf) ans -= inf;
			} else {
				ans = dp[i+1][max(0,j-1)];
			}
		}
	}
	cout << dp[1][1] << "\n";

	return 0;
}