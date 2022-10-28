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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}


const int N = 701;
bool dp[N][N][2];
int a[N];
bool g[N][N];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	FOR (i, 1, n) cin >> a[i];
	

	FOR (i, 1, n) {
		FOR (j, 1, n) {
			g[i][j] = __gcd(a[i], a[j]) > 1;
		}
	}

	FOR (len, 1, n) {
		FOR (i, 1, n - len + 1) {
			int j = i + len - 1;
			FOR (it, 0, 1) {
				if (i == 1 and it == 0) continue;
				if (j == n and it == 1) continue;
				int v = it ? j + 1 : i - 1;
				FOR (k, i, j) {
					if (g[v][k]) {
						bool now = true;
						if (k - 1 >= i) now &= dp[i][k - 1][1];
						if (k + 1 <= j) now &= dp[k + 1][j][0];
						if (now) {
							dp[i][j][it] = 1;
							break;
						}
					}
				}
			}
		}
	}

	bool ans = 0;
	FOR (k, 1, n) {
		bool now = 1;
		if (k - 1 >= 1) now &= dp[1][k - 1][1];
		if (k + 1 <= n) now &= dp[k + 1][n][0];
		ans |= now;
	}
	cout << (ans ? "Yes" : "No");

	return 0;
}