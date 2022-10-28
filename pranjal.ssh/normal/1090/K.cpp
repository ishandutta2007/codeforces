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

int main() {
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<tuple<int, string, int>> ans;
	FOR (i, 0, n -1 ) {
		string s, t; cin >> s >> t;
		int mask = 0;
		for (char ch: t) mask |= (1 << (ch - 'a'));
		while (!s.empty() and (mask & (1 << (s.back() - 'a')))) s.pop_back();
		ans.emplace_back(mask, s, i + 1);
	}
	sort(all(ans));
	vector<vi> yo;
	FOR (i, 0, n - 1) {
		int x, y; string s; tie(x, s, y) = ans[i];
		int j = i;
		yo.emplace_back(); yo.back().push_back(y);
		while (j+1 < n and get<0>(ans[j+1]) == x and get<1>(ans[j+1]) == s) {
			yo.back().push_back(get<2>(ans[j+1]));
			++j;
		}
		i = j;
	}
	cout << sz(yo) << "\n";
	FOR (i, 0, sz(yo) -1 ) {
		cout << sz(yo[i]) << " ";
		for (int j: yo[i]) cout << j << " ";
			cout << "\n";
	}
}