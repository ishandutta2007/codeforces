#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vi a(n);
	vi pos(n+1);
	FOR (i, 0, n - 1) cin >> a[i], pos[a[i]] = i;
	vi dp(n);
	dp[pos[n]] = 0;
	NFOR (i, n-1, 1) {
		int x = pos[i];
		dp[x] = 0;
		for (int j = a[x]; j <= n; j += a[x]) {
			if (x + j < n and !dp[x + j] and a[x+j] > a[x]) dp[x] = 1;
			if (x - j >= 0 and !dp[x - j] and a[x-j] > a[x]) dp[x] = 1;
		}
	}
	FOR (i, 0, n - 1) cout << char(!dp[i] + 'A');
	
	return 0;
}