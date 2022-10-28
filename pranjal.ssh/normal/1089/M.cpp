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

	int n; cin >> n;
	vector<vi> g(n, vi(n));
	FOR (i, 0, n - 1) {
		FOR (j, 0, n - 1) {
			cin >> g[i][j];
		}
		g[i][i] = 1;
	}
	FOR (k, 0, n - 1) {
		FOR (i, 0, n - 1) {
			FOR (j, 0, n - 1) {
				g[i][j] |= (g[i][k] and g[k][j]);
			}
		}
	}
	vector<vector<string>> ans;
	vi par(n); iota(all(par), 0);
	FOR (i, 0, n - 1) {
		FOR (j, i + 1, n - 1) if (g[i][j] and g[j][i]) par[i] = par[j] = min({par[j], par[i], min(i, j)});
	}
	
	vector<vi> G(n);
	vi d(n);
	FOR (i, 0, n - 1) {
		FOR (j, 0, n - 1) if (g[i][j] and par[i] != par[j]) {
			G[par[j]].push_back(par[i]);
			d[par[i]]++;
		}
	}

	vi cons;
	FOR (i, 0, n - 1) if (par[i] == i and d[i] == 0) cons.push_back(i);

	map<int, int> mp;
	int bc = 0;
	int K = 500;
	
	while (!cons.empty()) {
		int x = cons.back();
		cons.pop_back();

		ans.emplace_back(vector<string>(5, string(K, '#')));
		ans.emplace_back(vector<string>(5, string(K, '.')));
		for (int y: G[x]) {
			--d[y];
			if (d[y] == 0) cons.push_back(y);
		}
		// pr(mp);
		mp[x] = sz(ans) - 1;
		FOR (y, 0, n - 1) if (par[y] == y and g[x][y] and x != y) {
			int lv = mp[y];
			FOR (it, 0, sz(ans) - 1) {
				ans[it][2][bc * 5 + 2] = (it == lv-1 ? '#' : '.');
				if (it != mp[x] and it % 4 == 1 and it != lv) {
					FOR (i, -1, 1) FOR (j, -1, 1) if ((i!=0) or (j!=0)) ans[it][2+i][bc * 5 + 2+j] = '#';
					FOR (i, -1, 1) FOR (j, -1, 1) if ((i!=0) or (j!=0)) ans[it+1][2+i][bc * 5 + 2+j] = '#';
				}
			}
			bc++;
		}
		
		ans.emplace_back(vector<string>(5, string(K, '.')));
		ans.emplace_back(vector<string>(5, string(K, '.')));
	}

	FOR (i, 0, n - 1) {
		int f = 0;
		for (auto &x: ans[mp[par[i]]]) {
			if (f) break;
			for (char &y: x) {
				if (y == '.') {
					y = '0' + i + 1;
					f = 1;
					break;
				}
			}
		}
	}

	cout << K << " " << 5 << " " << sz(ans) << "\n";
	NFOR (i, sz(ans)-1, 0) {
		FOR (j, 0, 4) {
			cout << ans[i][j] << "\n";
		}
		cout << "\n";
	}


	return 0;
}