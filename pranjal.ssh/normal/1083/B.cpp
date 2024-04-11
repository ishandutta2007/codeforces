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

int n, k;
string s, t;
const int N = 5e5 + 10;
int lv[N];

void dfs(int pos, bool gt, bool lt) {
	if (lt and gt) {
		FOR (it, 0, min(33, n - pos)) {
			lv[pos + it] += (1LL << it);
		}
		return;
	}
	lv[pos]++;
	if (pos == n) {
		return;
	}
	FOR (i, 'a', 'b') {
		if (gt or i >= s[pos])
			if (lt or i <= t[pos])
				dfs(pos + 1, gt or i > s[pos], lt or i < t[pos]);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	cin >> s >> t;
	dfs(0, 0, 0);
	ll num = 0;
	FOR (i, 0, n) {
		num += lv[i];
		if (lv[i] >= k) {
			ll ans = num + k * 1LL * (n - i) - (lv[i] - k);
			cout << ans - 1 << "\n";
			return 0;
		}
	}
	cout << accumulate(lv+1, lv+n+1, 0LL) << "\n";

	return 0;
}