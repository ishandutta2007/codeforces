#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll;typedef pair <int, int> ii;typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ ";for (auto& it : p) os << it << " ";return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ ";for (auto& it : p) os << it << " ";return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ ";for (auto& it : p) os << it << " ";return os << "]";}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a) cerr << ", ";cerr << *i;}cerr << "]\n";}
int n;
int a[80];
string s;

int dp[75][1 << 20];

int f(int pos, int mask) {
	if (pos == n) {
		return ((mask&(mask+1)) == 0);
	}
	int & ans = dp[pos][mask];
	if (~ans) return ans;
	ans = 0;
	int val = 0;
	if (mask > 0 and ((mask&(mask+1)) == 0)) ++ans;
	FOR (j, pos, n - 1) {
		val = (val << 1) + a[j];
		if (val > 20) break;
		if (val == 0) continue;
		ans += f(j + 1, mask|(1 << (val - 1)));
		if (ans >= inf) ans -= inf;
	}

	return ans;
}

int main() 
{
   ios::sync_with_stdio(0); cin.tie(0);
   memset(dp, -1, sizeof dp);

   cin >> n >> s;
   FOR (i, 0, n - 1) a[i] = s[i] - '0';

   int ans = 0;
   FOR (i, 0, n - 1) {
   	ans += f(i, 0);
   	if (ans >= inf) ans -= inf;
   }
   cout << ans;

   return 0;
}