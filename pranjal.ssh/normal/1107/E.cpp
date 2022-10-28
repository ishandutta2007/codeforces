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

ll dp[101][101][101];
vector<ll> b;
ll a[101];
int n;
string s;
ll f(int l, int r, int c) {
	if (l > r) return a[c];

	ll &ans = dp[l][r][c];
	if (~ans) return ans;

	if (c == 0) return ans = f(l+1, r, b[l]);

	ans = a[c] + f(l, r, 0);

	for (int i = l+1; i <= r; i += 2) {
		ans = max(ans, f(l, i-1, 0) + f(i+1, r, b[i]+c));
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	cin >> s;
	FOR (i, 1, n) cin >> a[i];
	FOR (i, 1, n) {
		FOR (j, 1, i - 1) {
			a[i] = max(a[i], a[j] + a[i-j]);
		}
	}
	int cur = 0, last = s[0];
	FOR (i, 0, n - 1) {
		if (last == s[i]) ++cur;
		else b.emplace_back(cur), cur = 1, last = s[i];
	}
	if (cur) b.emplace_back(cur);
	memset(dp, -1, sizeof dp);
	cout << f(0,sz(b)-1,0) << "\n";
	
	return 0;
}