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

const int N = 1e5 + 10;
int n, k;
vector<ii> g[N];
vector<pair<ll, ll>> A1[N];

pair<ll, ll> f(int u, int p) {
	auto &a1 = A1[u];

	for (auto it: g[u]) if (it.F != p) {
		int v = it.F, c = it.S;
		auto now = f(v, u);
		a1.emplace_back(now.F+c, max(now.F, now.S)+c);
	}
	sort(all(a1)); reverse(all(a1));
	pair<ll, ll> ans(0, 0);
	FOR (i, 0, min(sz(a1), k-1)-1) {
		ans.F += a1[i].F;
		ans.S += a1[i].F;
	}
	ll cur = ans.S;
	FOR (i, 0, sz(a1) - 1) {
		if (i <= k-2) {
			ans.S = max(ans.S, cur - a1[i].F + a1[i].S + (k-1 < sz(a1) ? a1[k-1].F : 0));
		} else {
			ans.S = max(ans.S, cur + a1[i].S);
		}
	}

	return ans;
	
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	FOR (i, 1, n - 1) {
		int x, y, c; cin >>x >> y >> c;
		g[x].emplace_back(y,c);
		g[y].emplace_back(x,c);
	}
	ii ans = f(0, -1);
	cout << max(ans.F, ans.S) << "\n";
	
	return 0;
}