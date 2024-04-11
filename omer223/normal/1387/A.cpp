
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>
#include <bitset>
#include <iomanip>
#include <vector>
#include <unordered_set>
#include <map>
#include <fstream>

using namespace std;
ifstream in("input.txt");
ofstream out("outbad.txt");
constexpr int sz = 1e5 + 1;
constexpr long double EPS = 1e-4;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unordered_set<int> us;
map<pii, int> mem;
us uv, cr, check;
int n, m;
list<pii> adj[sz];
ld ans[sz];
bool bad = 0;
pii dat[sz];
bitset<sz> checkedbs;
ld forcedX = 1e9;
inline bool eq(ld a, ld b) {
	return (abs(a - b) <= EPS);
}
void input() {
	cin >> n >> m;
	mem.clear();
	uv.clear();
	check.clear();
	cr.clear();
	bad = 0;
	checkedbs.reset();
	forcedX = 1e9;
	foru(i, 0, n) {
		adj[i].clear();
		ans[i] = 0;
		dat[i].first = 0;
		dat[i].second = 0;
	}
	int x, y, c;
	foru(i, 0, n)uv.insert(i);
	foru(i, 0, m) {
		cin >> x >> y >> c; x--; y--;
		if (x > y)swap(x, y);
		if (x == y) {
			if (check.find(x) == check.end()) {
				checkedbs[x] = 1;
				check.insert(x);
				ans[x] = (ld)c / 2;
			}
			else {
				if (!eq(2 * ans[x], c))bad = 1;
			}
		}
		else {
			pii ppp(x, y);
			if (mem.find(ppp) != mem.end()) {
				if (mem[ppp] != c)bad = 1;
			}
			else {
				mem.insert(mp(ppp, c));
				adj[x].pb(mp(y, c));
				adj[y].pb(mp(x, c));
			}
		}
	}
}

void dfscheck(int src, int prev) {
	uv.erase(src);
	check.erase(src);
	for (auto x : adj[src]) {
		int a = x.first, b = x.second;
		if (checkedbs[a]) {
			if (!eq(ans[a] + ans[src], b)) {
				bad = 1;
				return;
			}
			if (uv.find(a) != uv.end())dfscheck(a, src);
		}
		else {
			if (uv.find(a) != uv.end()) {
				ans[a] = b - ans[src];
				dfscheck(a, src);
			}
			else {
				if (!eq(ans[a] + ans[src], b)) {
					bad = 1;
					return;
				}
			}
		}
	}
}

void dfs(int src, int prev) {
	uv.erase(src);
	cr.insert(src);
	for (auto x : adj[src]) {
		int a = x.first, b = x.second;
		if (uv.find(a) != uv.end()) {
			dat[a].first = -dat[src].first;
			dat[a].second = b - dat[src].second;
			dfs(a, src);
		}
		else {
			if (dat[a].first == dat[src].first) {
				int rhs = b - (dat[a].second + dat[src].second);
				if (dat[a].first == -1)rhs = (-rhs);
				ld tmp = (ld)rhs / 2;//check neg
				if (forcedX >= 1e8)forcedX = tmp;
				else if (!eq(forcedX, tmp)) {
					bad = 1;
					return;
				}
			}
			else {
				if (!eq(dat[a].second + dat[src].second, b)) {
					bad = 1;
					return;
				}
			}
		}
	}
}

int main() {
	fast;
	int t=1;
	//in >> t;
	while (t--) {
		input();
		while (!check.empty()) {
			int x = *check.begin();
			dfscheck(x, -1);
		}
		while (!uv.empty()) {
			int x = *uv.begin();
			dat[x].first = 1;
			forcedX = 1e9;
			cr.clear();
			dfs(x, -1);
			if (forcedX >= 1e8) {
				vector<int> vec;
				for (int k : cr) {
					if (dat[k].first == 1)vec.pb(-dat[k].second);
					else vec.pb(dat[k].second);
				}
				sort(vec.begin(), vec.end());
				ld myx = vec[vec.size() / 2];
				for (int k : cr)ans[k] = dat[k].first * myx + dat[k].second;
			}
			else {
				for (int k : cr) ans[k] = dat[k].first * forcedX + dat[k].second;
			}
		}
		if (bad) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			foru(i, 0, n - 1)cout << fixed << setprecision(12) << ans[i] << " ";//-0.0
			cout << fixed << setprecision(12) << ans[n - 1] << endl;
		}
	}
	return 0;
}