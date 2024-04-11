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
	vector<ii> a(n), b(n);
	FOR (i, 0, n - 1) cin >> a[i].F >> a[i].S;
	FOR (i, 0, n - 1) cin >> b[i].F >> b[i].S;
	if (n == 1) {
		cout << a[0].F + b[0].F << " " << a[0].S + b[0].S << "\n";
		return 0;
	}
	sort(all(b));

	FOR (i, 0, n - 1) {
		ii t(a[0].F + b[i].F, a[0].S + b[i].S);
		vector<ii> c = {b[i]};
		FOR (j, 1, n - 1) {
			c.emplace_back(t.F - a[j].F, t.S - a[j].S);
		}
		sort(all(c));
		if (b == c) {
			cout << t.F << " " << t.S << "\n";
			return 0;
		}
	}
	assert(0);
	
	return 0;
}