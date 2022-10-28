#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 998244353;
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


int expo(int a, int n) {
	int ans = 1;
	for (;n;n>>=1, a=(a*1LL*a)%inf) if (n&1) ans = (ans*1LL*a)%inf;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, a; cin >> n >> m >> a;
	vi b(m); FOR (i, 0, m - 1) cin >> b[i];

	int l = 2*(n/2.0 - b.back());
	int s = b[0];
	FOR (i, 1, m - 1) b[i] -= s, s += b[i];
	int ans = 1;
	int i2 = expo(2, inf-2);
	for (int k: b) {
		int x = expo(a, k);
		ans = (ans * 1LL * x) % inf;
		ans = (ans * 1LL * (x+1)) % inf;
		ans = (ans * 1LL * i2) % inf;
	}
	cout << (ans*1LL*expo(a, l)) % inf;
	
	return 0;
}