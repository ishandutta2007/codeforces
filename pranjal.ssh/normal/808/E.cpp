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
	vector<vi> a(3);
	FOR (i, 0, n - 1) {
		int w, c; cin >> w >> c;
		--w;
		a[w].push_back(c);
	}
	FOR (i, 0, 2) sort(all(a[i])), reverse(all(a[i]));
	a[0].emplace_back(0);

	ll ans = 0, sum = accumulate(all(a[2]), 0LL), curc = 0, curw = 0;
	int p1 = 0, p2 = 0; ll curc1 = 0, curw1 = 0;
	int p3 = 1, p4 = 0; ll curc2 = a[0][0], curw2 = 1;

	NFOR (i, sz(a[2]), 0) {
		{
			#define z (a[0][p1]+a[0][p1 + 1])
			while (curw1 + 3 * i + 2 <= m) {
				if (p1 + 1 >= sz(a[0]) and p2 >= sz(a[1])) break;
				
				if (p1 + 1 < sz(a[0]) and (p2 >= sz(a[1]) or a[1][p2] <= z)) {
					curc1 += z, curw1 += 2; p1 += 2;
				} else {
					curc1 += a[1][p2], curw1 += 2; p2 += 1;
				}
			}
			ll lol = curc1;
			if (p1 < sz(a[0]) and curw1 + 3 * i < m) lol += a[0][p1];
			if (curw1 + 3 * i <= m) ans = max(ans, sum + lol);
			#undef z
		}


		{
			#define z (a[0][p3]+a[0][p3 + 1])
			while (curw2 + 3 * i + 2 <= m) {
				if (p3 + 1 >= sz(a[0]) and p4 >= sz(a[1])) break;
				if (p3 + 1 < sz(a[0]) and (p4 >= sz(a[1]) or a[1][p4] <= z)) {
					curc2 += z, curw2 += 2; p3 += 2;
				} else {
					curc2 += a[1][p4], curw2 += 2; p4 += 1;
				}
			}
			ll lol = curc2;
			if (p3 < sz(a[0]) and curw2 + 3 * i < m) lol += a[0][p3];
			if (curw2 + 3 * i <= m) ans = max(ans, sum + lol);
			#undef z
		}

		if (i > 0) sum -= a[2][i - 1];
	}
	cout << ans << "\n";

	return 0;
}