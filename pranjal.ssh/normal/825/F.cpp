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

vector<int> fail(string s) {
	int n = s.length();
	vector<int> p(n);
	for (int i = 1; i < n; ++i) {
		int x = p[i-1];
		while (1) {
			if (s[x] == s[i]) {
				p[i] = x+1;
				break;
			}
			if (x == 0) break;
			x = p[x-1];
		}
	}
	return p;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	int n = s.length();
	vector<int> dp(n + 1);
	vector<int> lg10(n+1);
	int x = 1;
	for (int i = 1; i <= n; ++i) {
		if (i == x) ++lg10[i], x *= 10;
		lg10[i] += lg10[i-1]; 
	}
	dp[n] = 0;
	for (int i = n-1; i >= 0; --i) {
		vector<int> p = fail(s.substr(i, s.length()-i));
		dp[i] = 2 + dp[i+1];
		for (int j = i+1; j <= n-1; ++j) {
			int len = j-i+1;
			int prefix = p[j-i];
			if (len % (len - prefix) == 0) {
				int cost = len-prefix + lg10[len/(len-prefix)];
				dp[i] = min(dp[i], dp[j+1] + cost);
			} else {
				int cost = 1 + len;
				dp[i] = min(dp[i], dp[j+1] + cost);
			}
		}
	}
	cout << dp[0] << "\n";

	return 0;
}