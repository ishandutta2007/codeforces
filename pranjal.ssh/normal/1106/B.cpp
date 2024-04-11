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

	int n, m; cin >> n >> m;
	vi a(n), c(n);
	FOR (i, 0, n - 1) cin >> a[i];	
	vector<ii> cs;
	FOR (i, 0, n - 1) cin >> c[i], cs.emplace_back(c[i], i);
	sort(all(cs)); reverse(all(cs));

	while (m--) {
		int t, d; cin >> t >> d; --t;
		ll ans = 0;
		while (d) {
			if (a[t]) {
				int can = min(a[t], d);
				a[t] -= can;
				d -= can;
				ans += c[t] * 1LL * can;
				continue;
			}
			if (cs.empty()) {
				ans = 0;
				break;
			}
			int id = cs.back().S;
			if (a[id] == 0) {
				cs.pop_back();
				continue;
			}
			
			int can = min(a[id], d);
			a[id] -= can;
			d -= can;
			ans += c[id] * 1LL * can;
			
		}
		cout << ans << "\n";
	}
	
	return 0;
}