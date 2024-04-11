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
	vector<ll> a(n); FOR (i, 0, n - 1) cin >> a[i], a[i] *= 2;
	string s; cin >> s;
	ll g = 0, w = 0, ga = 0, wa = 0, l = 0;

	FOR (i, 0, n - 1) {
		if (s[i] == 'G') {
			if (wa > 0) {
				ll x = min(wa, a[i] / 2);
				wa -= x;
				a[i] -= 2 * x;
				ga += 2*x;
				w += x;
			}
			g += a[i] / 2;
			ga += a[i]/2;
		} else if (s[i] == 'W') {
			w += a[i] / 2;
			wa += a[i] / 2;
		} else {
			l += a[i];
			if (wa > 0) {
				ll x = min(wa, a[i]/2);
				wa -= x;
				a[i] -= 2*x;
				w += x;
			}

			if (ga > 0) {
				ll x = min(ga, a[i]/2);
				ga -= x;
				a[i] -= 2*x;
				g += x;
			}

			if (a[i] > 0) {
				if (w > 0) w += a[i];
				else g += a[i];
				a[i] = 0;
			}
		}
	}

	cout << (5*g + 3*w + ga + wa + l) / 2 << "\n";

	
	return 0;
}