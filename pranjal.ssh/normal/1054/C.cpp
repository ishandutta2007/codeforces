#include <bits/stdc++.h>
using namespace std;

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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vi l(n), r(n), val(n);
	FOR (i, 0, n - 1) cin >> l[i];
	FOR (i, 0, n - 1) cin >> r[i];	
	vi a(n); iota(all(a), 0);
	stable_sort(all(a), [&](int x, int y) {return l[x]+r[x] > l[y] + r[y];});
	
	int ctr = 1;
	FOR (i, 0, n - 1) {
		if (i > 0 and l[a[i]]+r[a[i]] == l[a[i - 1]]+r[a[i-1]]) val[a[i]] = val[a[i - 1]];
		else val[a[i]] = ctr++;
	}
	bool g = 1;
	FOR (i, 0, n - 1) {
		FOR (j, 0, i - 1) l[i] -= val[j] > val[i];
		FOR (j, i + 1, n - 1) r[i] -= val[j] > val[i];
		g &= l[i] == 0 and r[i] == 0;
	}
	if (g) {
		cout << "YES\n";
		FOR (i, 0, n - 1) cout << val[i] << " ";
	} else {
		cout << "NO\n";
	}
	return 0;
}