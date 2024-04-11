#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 998244353;
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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	vi a(n);
	FOR (i, 0, n - 1) cin >> a[i];

	vector<vector<ll>> dp(2, vector<ll>(n+1,-1));


	function<ll(int,int,int)> solve = [&](int len, int l, int r) -> ll {
		if (len == 0) return (l != r);

		if (l == -1 and r == -1) return (k * solve(len-1, 1, r)) % inf;
		if (l == -1) {
			return (solve(len-1, r, r) + (k-1) * solve(len-1, r^3, r)) % inf;
		}
		if (r == -1) {
			return (solve(len-1, l, l) + (k-1) * solve(len-1, l, l^3)) % inf;	
		}

		ll &ans = dp[l == r][len];
		if (~ans) return ans;
		if (l == r) {
			ans = ((k-1LL) * solve(len-1, r^3, r))%inf;
		} else {
			ans = (solve(len-1, r, r) + (k-2LL) * solve(len-1, r, r^3))%inf;
		}
		
		return ans;
	};

	int yo = 0;
	ll ans = 1;


	FOR (st, 0, 1) {
		vi x;
		for (int i = st; i < n; i += 2) {
			x.push_back(a[i]);
		}
		FOR (i, 0, sz(x) - 2) {
			if (x[i] == x[i+1] and x[i] != -1) {
				cout << "0\n";
				return 0;
			}
		}

		FOR (i, 0, sz(x) - 1) {
			if (x[i] == -1) {
				int j = i;
				while (j+1 < sz(x) and x[j+1] == -1) ++j;
				int l = i == 0 ? -1 : x[i-1];
				int r = j==sz(x)-1 ? -1 : x[j+1];
				
				ans = (ans * 1LL * solve(j-i+1, l, r)) % inf;
				i = j;
			}
		}
	}

	cout << ans << "\n";
	
	return 0;
}