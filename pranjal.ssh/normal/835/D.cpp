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

const int N = 5010;
int dp[N][N];
int pal[N][N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	int n = s.length();
	vector<ll> ans(n+1);
	FOR (len, 1, n) {
		FOR (i, 0, n-1) {
			int j = (i+len-1);
			if (j >= n) continue;
			if (len == 1) {
				dp[i][j] = 1;
				pal[i][j] = 1;
			}
			if (len == 2) {
				pal[i][j] = s[i] == s[j];
				dp[i][j] = pal[i][j] ? 2 : 0;
			}
			if (len > 2) {
				pal[i][j] = (s[i]==s[j]) and pal[i+1][j-1];
				if (pal[i][j]) {
					dp[i][j] = 1 + min(dp[i][i+len/2-1], dp[j-len/2+1][j]);
				}
			}
			ans[dp[i][j]]++;
		}
	}
	NFOR (i, n-1, 1) ans[i] += ans[i+1];

	FOR (i,1,n) cout << ans[i] << " ";

	return 0;
}