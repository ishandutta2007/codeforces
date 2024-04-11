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
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int N = 1e6;
int dp[4][N + 1];
#define sq(x) ((x)*(x))
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	dp[0][0] = dp[0][1] = 1;
	
	FOR (i, 1, N) {
		int ans = 0;
		ll l = ceil(pow(i, 0.25L)), r = pow(i, 0.5L);
		if (sq(sq(l-1)) >= i) --l;
		if (sq(r+1) <= i) ++r;
		FOR (j, 0, 3) dp[j][i] += dp[j][i - 1];
		while (dp[ans][r] - dp[ans][l - 1]) ++ans, assert(ans <= 3);
		dp[ans][i]++;
	}
	int x = 0;
	FOR (i, 0, n - 1) {
		ll a; cin >> a;
		if (a == 1) {continue;}
		int v = 0;
		ll l = ceil(pow(a, 0.25L)), r = pow(a, 0.5L);
		if (sq(sq(l-1)) >= a) --l;
		if (sq(r+1) <= a) ++r;
		if (l > r) continue;
		while (v < 4 and dp[v][r] - dp[v][l - 1]) ++v;
		x ^= v;
	}
	cout << (x ? "Furlo" : "Rublo") << "\n";
	
	return 0;
}