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

	// FOR (n, 2, 63) {
	int n; cin >> n;
		int at = 0;
		vi e{1,2,3,4,5,6,0,7};
		vector<ii> ans;
		FOR (i, 0, 7) {
			vi a(8); iota(all(a), 0);
			swap(a[0], a[at]);
			swap(a[7], *find(all(a), e[i]));
			FOR (j, 0, 7) ans.emplace_back(i, a[j]);
			at = e[i];
		}
		
		ans.resize(n + 1);
		if (ans[n] == ii(7, 7)) {

		} else if (ans[n-1].F == 7 or ans[n-1].S == 7) {
			ans.pop_back();
			ans.emplace_back(7, 7);
		} else {
			ans.pop_back();
			ans.pop_back();
			if (ans.back().S == 7)  {
				ans.pop_back();
				ans.emplace_back(7, ans.back().S);
				ans.emplace_back(7, ans.back().S ? 0 : 1);
				ans.emplace_back(7, 7);
			} else {
				ans.emplace_back(7, ans.back().S);
				ans.emplace_back(7, 7);
			}
		}
		// FOR (i, 1, sz(ans)-1) assert(ans[i].F == ans[i-1].F or ans[i].S == ans[i-1].S);
		// assert(set<ii>(all(ans)).size() == n+1);
		// assert(ans.back() == ii(7,7));
	// }
	FOR (i, 0, sz(ans) - 1) {
		cout << char('a' + ans[i].S) << ans[i].F + 1 << " ";
	}

	return 0;
}