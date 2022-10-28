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

int dp[450][450];
inline int add(int x, int y) {return (x += y) >= inf ? x-inf : x;}
inline int mul(int x, int y) {return (x*1LL*y)%inf;}
int f(int k, int c) {
	if (c == 0) return 1;
	if (k == 1) return c == 1;
	int &ans = dp[k][c];
	if (~ans) return ans;
	ans = 0;
	FOR (i, 0, c) ans = add(ans, mul(f(k-1, i), mul(f(k-1, c-i), 1+2*c)));
	FOR (i, 0, c+1) ans = add(ans, mul(f(k-1, i), mul(f(k-1, c+1-i), c*c+c)));
	FOR (i, 0, c-1) ans = add(ans, mul(f(k-1, i), f(k-1, c-1-i)));
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int k; cin >> k;
	memset(dp, ~0, sizeof dp);
	cout << f(k, 1) << "\n";

	return 0;
}