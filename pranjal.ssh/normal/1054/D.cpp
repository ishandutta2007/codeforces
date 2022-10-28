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

	int n, k; cin >> n >> k;
	vi a(n + 1);
	FOR (i, 1, n) cin >> a[i];
	vi p(n + 1);
	map<int, int> mp; mp[0] = 1;
	int SAB = (1 << k) - 1;
	FOR (i, 1, n) {
		p[i] = p[i - 1] ^ a[i];
		if (mp[p[i]] > mp[SAB ^ p[i]]) {
			p[i] ^= SAB;
		}
		mp[p[i]]++;
	}
	ll ans = n*(n + 1LL) / 2;
	for (auto it: mp) ans -= it.S*(it.S-1LL)/2;
	cout << ans;
	
	return 0;
}