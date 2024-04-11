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

	int n, m; cin >> n >> m;
	vector<vi> g(n);
	FOR (i, 1, m) {
		int x, y; cin >> x >> y; --x, --y;
		g[x].push_back(y), g[y].push_back(x);
	}
	if (m == n*(n-1LL)/2) {
		cout << "NO\n";
		return 0;
	}
	FOR (i, 0, n - 1) {
		sort(all(g[i]));
		FOR (j, 0, n - 1) if (j != i) {
			if (not binary_search(all(g[i]), j)) {
				vi ord(2), iord(n);
				ord[0] = i, ord[1] = j; iord[i] = 0, iord[j] = 1;
				FOR (k, 0, n - 1) if (k != i and k != j) ord.push_back(k), iord[k] = sz(ord)-1;

				cout << "YES\n";
				FOR (u, 0, n - 1) cout << iord[u] + 1 << " ";
				cout << "\n";
				FOR (u, 0, n - 1) {
					if (u == i) cout << iord[j] + 1 << " ";
					else cout << iord[u] + 1 << " ";
				}
				return 0;
			}
		}
	}
	assert(false);
}