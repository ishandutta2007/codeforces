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
string to_string(char s) { return string(1, s);}
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (auto it = v.begin(); it != v.end(); ++it) {if (!f)r += ", "; f = 0; r += to_string(*it);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; while (t--) {
		ll k; cin >> k;
		int s = 0;
		vi a(7); FOR (i, 0, 6) cin >> a[i], s += a[i];
		ll ans = 1e18;
		FOR (st, 0, 6) {
			ll d = 7 * (k / s);
			ll K = k;
			if (d > 50) {
				d -= 14;
				K -= s * (d / 7);
			} else {
				d = 0;
			}
			while (K) {
				K -= a[(st + d) % 7];
				++d;
			}
			ans = min(ans, d);
		}
		cout << ans << "\n";
	}

	return 0;
}