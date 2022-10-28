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

vector<string> a;
int n, m;
int r, c, x, y;

bitset<4000000> get(bool bc) {
	vector<vector<ii>> d(n, vector<ii>(m, ii(inf, inf)));
	priority_queue<pair<ii, ii>, vector<pair<ii, ii>>, greater<pair<ii, ii>>> q;

	q.emplace(ii(0, 0), ii(r, c));
	d[r][c] = ii(0, 0);
	while (!q.empty()) {
		auto it = q.top();
		q.pop();
		int x, y;
		tie(x, y) = it.S;
		if (it.F != d[x][y]) continue;
		FOR (dx, -1, 1) {
			FOR (dy, -1, 1) {
				if (abs(dx) + abs(dy) == 1) {
					if (x + dx >= 0 and x + dx <= n - 1 and y + dy >= 0 and y + dy <= m - 1 and a[x+dx][y+dy] == '.') {
						ii nd = it.F;
						if (dy == -1) (bc ? nd.F : nd.S)++;
						if (dy == 1) (bc ? nd.S : nd.F)++;
						if (nd < d[x + dx][y + dy]) {
							d[x + dx][y + dy] = nd;
							q.emplace(nd, ii(x + dx, y + dy));
						}
					}
				}
			}
		}
	}
	bitset<4000000> bt;
	ii mc(x, y);
	if (!bc) swap(mc.F, mc.S);
	FOR (i, 0, n - 1) FOR (j, 0, m - 1) {
		if (d[i][j].F <= mc.F and d[i][j].S <= mc.S) {
			bt.set(i*m+j);
		}
	}
	return bt;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	cin >> r >> c;
	cin >> x >> y;
	--r, --c;
	a.resize(n);
	FOR (i, 0, n - 1) cin >> a[i];
	cout << (get(0)|get(1)).count() << "\n";

	return 0;
}