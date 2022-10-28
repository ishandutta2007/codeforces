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

ll get(ll n, ll x, ll y, ll k) {
	ll st = max(1LL, y - k);
	ll v1 = min(x, st - y + k + 1);
	// pr(st, v1);
	
	ll t = max(st, min(y, x+y -k-1));
	ll v2 = min(x, t - y + k + 1);
	// pr(t, v2);
	
	ll ans = v2*(v2+1)/2 - v1*(v1-1)/2;
	ans += x*max(0LL, y - t);
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	ll n, x, y, c; cin >> n >> x >> y >> c;
	ll st = 0, en = 2*n;
	
	while (st < en) {
		ll mid = (st + en) >> 1;
		
		ll val = get(n, x, y, mid) + get(n, n - x + 1, y, mid) + get(n, x, n - y + 1, mid) + get(n, n - x + 1, n - y + 1, mid);
		val -= min(n, x+mid) - max(1LL, x-mid) + 1;
		val -= min(n, y+mid) - max(1LL, y - mid) + 1;
		--val;
			
		if (val >= c) en = mid;
		else st = mid + 1;
	}
	cout << st;
	
	return 0;
}