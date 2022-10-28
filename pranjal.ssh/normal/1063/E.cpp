#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	int x = 0, y = 0;
	vi a(n); FOR (i, 0, n - 1) cin >> a[i], --a[i];
	vector<string> ans(n, string(n, '.'));

	vi vis(n);
	int bc = n;
	int yo = 0;
	NFOR (i, n-1, 0) {
		if (vis[i] or a[i] == i) continue;
		if (bc == n) bc--;
		vi cyc;
		int x = i;
		do {cyc.push_back(x); vis[x] = 1; x = a[x];} while (x != i);
		int p = yo;
		++yo;
		FOR (j, 1, sz(cyc) - 1) {
			int it = cyc[j];
			char ch = a[it] > it ? '/' : '\\';
			ans[yo][it] = ch, ans[yo++][a[it]] = ch; 
		}

		if (i != n - 1) {
			ans[yo-1][n-1] = '/'; ans[p][n-1] = '\\'; ans[p][a[i]] = '\\';
		}
	}
	cout << bc << "\n";
	FOR (i, 0, n - 1) cout << ans[i] << "\n";
	
	
	return 0;
}