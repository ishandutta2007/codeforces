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
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}

int n; string s;
int dp[76][76][76][3];
int f(int v, int k, int x, int last) {
	if (v+k+x == n) return 0;
	int &ans = dp[v][k][x][last];
	if (~ans) return ans;
	ans = inf;
	FOR (cur, 0, 2) {
		if (last == 0 and cur == 1) continue;
		int now = 0;
		int A[] = {v, k, x};
		bool can = 0;
		FOR (i, 0, n - 1) {
			if (A[s[i]] == 0) {
				if (s[i] == cur){can=1;break;}
				now++;
			}
			else
				A[s[i]]--;
		}
		if (can)
			ans = min(ans, now + f(v + (cur==0), k + (cur==1), x + (cur==2), cur));
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	for (char &ch : s) {
		if (ch == 'V') ch =0;
		else if (ch == 'K') ch = 1;
		else ch = 2;
	}
	memset(dp, -1, sizeof dp);
	cout << f(0, 0, 0, 2) << "\n";
	
	return 0;
}