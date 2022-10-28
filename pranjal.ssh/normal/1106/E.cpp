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

struct e {
	int s, t, d, w;
	e(int s=0, int t=0, int d=0, int w=0): s(s), t(t), d(d), w(w) {}
};

ll dp[201][100010];
vector<ii> at;
int n, m, k;

ll f(int i, int l) {
	if (i > n) return 0;
	ll &ans = dp[l][i];
	if (~ans) return ans;
	if (at[i].F) ans = f(at[i].S+1, l)+at[i].F;
	else ans = f(i+1, l);
	if (l) ans = min(ans, f(i+1, l-1));
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	vector<e> a;
	FOR (i, 0, k-1) {
		int s, t, d, w; cin >> s >> t >> d >> w;
		a.emplace_back(s, t, d, w);
	}
	vi ids(k), idt(k);
	iota(all(ids), 0), iota(all(idt), 0);
	sort(all(ids), [&](int x, int y) {
		if (a[x].s == a[y].s) return x < y;
		return a[x].s < a[y].s;
	});

	sort(all(idt), [&](int x, int y) {
		if (a[x].t == a[y].t) return x < y;
		return a[x].t < a[y].t;
	});


	at.resize(n+1);
	map<ii, int> mp;

	int x = 0, y = 0;
	FOR (i, 1, n) {
		while (x < k and a[ids[x]].s <= i) {
			mp[ii(a[ids[x]].w, a[ids[x]].d)]++;
			++x;
		}
		while (y < k and a[idt[y]].t < i) {
			mp[ii(a[idt[y]].w, a[idt[y]].d)]--;
			if (mp[ii(a[idt[y]].w, a[idt[y]].d)] == 0) mp.erase(ii(a[idt[y]].w, a[idt[y]].d));
			++y;
		}
		if (mp.empty()) {
			at[i] = ii(0, n);
		} else {
			at[i] = mp.rbegin()->F;
		}
	}
	memset(dp, -1, sizeof dp);
	// pr(f(2,0));
	cout << f(1, m);
	return 0;
}