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

const int N = 5010;
int dp[N][N / 2][3];
int a[N];
int n;

int f(int i, int k, int st) {
	if (k == 0) {
		return 0;
	}
	if (i >= n + 1) {
		return inf;
	}
	int &ans = dp[i][k][st];
	if (~ans) return ans;
	ans = inf;

	int prev = a[i - 1];
	if (st == 1) prev = a[i - 2] - 1;
	else if (st == 2) prev = a[i] - 1;


	ans = min(ans, f(i + 1, k, 0));
	if (i + 1 <= n and a[i] > a[i + 1] - 1) {
		ans = min(ans, f(i + 1, k, 2) + a[i] - (a[i + 1] - 1));
	}


	if (a[i] > prev) {
		if (a[i + 1] < a[i]) {
			ans = min(ans, f(i + 2, k - 1, 0));
		} else {
			ans = min(ans, f(i + 2, k - 1, 1) + a[i + 1] - (a[i] - 1));
		}
		if (i + 2 <= n and a[i + 1] > a[i + 2] - 1 && a[i+2]-1  < a[i])
			ans = min(ans, f(i + 2, k - 1, 2) + a[i + 1] - (a[i + 2] - 1));
		
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR (i, 0, n + 2) a[i] = -100;
	FOR (i, 1, n) cin >> a[i];
	// FOR (i, 1, n) a[i] = 1;

	memset(dp, -1, sizeof dp);

	NFOR (i, n, 0) {
		FOR (j, 1, (n+1)/2) {
			FOR (k, 0, 2) {
				f(i, j, k);
			}
		}
	}

	FOR (k, 1, (n + 1) / 2) {
		cout << f(1, k, 0) << " ";
	}

	return 0;
}