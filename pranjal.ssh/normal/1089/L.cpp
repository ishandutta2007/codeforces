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

	int n, k; cin >> n >> k;
	vector<ii> a(n);
	FOR (i, 0, n - 1) cin >> a[i].F;
	FOR (i, 0, n - 1) cin >> a[i].S;
	vector<vi> b(k);
	FOR (i, 0, n - 1) b[a[i].F-1].push_back(a[i].S);
	multiset<int> s;
	FOR (i, 0, k - 1) if (sz(b[i])) {
		int x = *max_element(all(b[i]));
		b[i].erase(max_element(all(b[i])));
		for (int x: b[i]) s.insert(x);
		b[i].push_back(x);
	}
	ll ans = 0;
	FOR (i, 0, k - 1) if (b[i].empty()) {
		ans += *s.begin();
		s.erase(s.begin());
	}
	cout << ans;

	return 0;
}