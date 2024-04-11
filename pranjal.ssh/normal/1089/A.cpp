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


ii dp[5][5][211][211];
vector<ii> scores[5];

ii mx(ii x, ii y) {
	if (x.F == -2) return y;
	if (y.F == -2) return x;
	if (ii(x.F-x.S, x.F) > ii(y.F-y.S, y.F)) return x;
	return y;
}

ii f(int x, int y, int a, int b) {
	if (x == 3 or y == 3) return max(a,b) == 0 ? ii(x, y): ii(-2,-2);

	ii &ans = dp[x][y][a][b];
	if (ans.F != -1) return ans;
	ans = ii(-2, -2);
	int cur = x + y;
	for (auto it: scores[x + y]) {
		if (it.F <= a and it.S <= b) {
			ans = mx(ans, f(x + (it.F > it.S), y + (it.S > it.F), a - it.F, b - it.S));
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	FOR (it, 0, 4) {
		int x = it == 4 ? 15 : 25;
		FOR (i, 0, x-2) scores[it].emplace_back(x, i), scores[it].emplace_back(i, x);
		FOR (i, x-1, 200) scores[it].emplace_back(i+2, i), scores[it].emplace_back(i, i+2);
	}
	
	memset(dp, -1, sizeof dp);
	int m; cin >> m; while (m--) {
		int a, b; cin >> a >> b;
		ii ans = f(0, 0, a, b);
		if (ans.F == -2) {
			cout << "Impossible\n";
			continue;
		}
		cout << ans.F << ":" << ans.S << endl;
		int x = 0, y = 0;
		int it = 0;
		while (x < 3 and y < 3) {
			int cur = x + y;
			for (auto it: scores[x + y]) {
				if (it.F <= a and it.S <= b) {
					if (f(x + (it.F > it.S), y + (it.S > it.F), a - it.F, b - it.S) == f(x, y, a, b)) {
						cout << it.F << ":" << it.S << " ";
						x += (it.F > it.S);
						y += (it.S > it.F);
						a -= it.F, b -= it.S;
						break;
					}
				}
			}
		}
		cout << "\n";
	}


	return 0;
}