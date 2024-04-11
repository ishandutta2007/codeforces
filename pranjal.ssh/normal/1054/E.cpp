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
// template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


vector<vector<deque<char>>> a, b;
vector<pair<ii, ii>> ans;
void Move(int x1, int y1, int x2, int y2) {
	a[x2][y2].push_front(a[x1][y1].back());
	a[x1][y1].pop_back();
	ans.emplace_back(ii(x1 + 1, y1 + 1), ii(x2 + 1, y2 + 1));
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	a.resize(n), b.resize(n);
	FOR (i, 0, n - 1) {
		FOR (j, 0, m - 1) {
			string x; cin >> x;
			a[i].push_back(deque<char>(all(x)));
		}
	}


	FOR (i, 0, n - 1) {
		FOR (j, 0, m - 1) {
			string x; cin >> x;
			b[i].push_back(deque<char>(all(x)));
		}
	}

	FOR (i, 0, m - 2) {
		while (!a[0][i].empty()) {
			Move(0, i, 1, i);
		}
	}

	FOR (i, 1, n - 1) {
		while (!a[i][m - 1].empty()) {
			Move(i, m - 1, i, m - 2);
		}
	}

	while (!a[0][m - 1].empty()) {
		if (a[0][m - 1].back() == '0') {
			Move(0, m - 1, 0, 0);
		} else {
			Move(0, m - 1, n - 1, m - 1);
		}
	}

	// s done

	FOR (i, 1, n - 1) {
		FOR (j, 0, m - 2) {
			while (!a[i][j].empty()) {
				if (a[i][j].back() == '0') {
					Move(i, j, 0, j);
				} else {
					Move(i, j, i, m - 1);
				}
			}
		}
	}

	// 2s done
	
	


	string yo(all(b[0][m - 1]));
	FOR (i, 0, m - 2) yo += string(all(b[0][i]));
	FOR (i, 1, n - 1) yo += string(all(b[i][m - 1]));
	int p1 = 0, p2 = n - 1;
	NFOR (it, sz(yo) - 1, 0) {
		if (yo[it] == '0') {
			while (a[0][p1].empty()) ++p1;
			Move(0, p1, 0, m - 1);
		} else {
			while (a[p2][m - 1].empty()) --p2;
			Move(p2, m - 1, 0, m - 1);
		}
	}

	p1 = 0;
	vi need(m);
	FOR (i, 0, m - 2) FOR (j, 1, n - 1) need[i] += count(all(b[j][i]), '0');
	FOR (i, 0, m - 2) {
		FOR (j, 0, m - 2) {
			while (need[i] > sz(a[0][i]) and need[j] < sz(a[0][j])) {
				Move(0, j, 0, i);
			}
		}
	}
	need = vi(n);
	FOR (i, 1, n - 1) FOR (j, 0, m - 2) need[i] += count(all(b[i][j]), '1');
	FOR (i, 1, n - 1) {
		FOR (j, 1, n - 1) {
			while (need[i] > sz(a[i][m - 1]) and need[j] < sz(a[j][m - 1])) {
				Move(j, m - 1, i, m - 1);
			}	
		}
	}
	// 3s done

	// FOR (i, 0, n - 1) {
	// 	FOR (j, 0, m - 1) {
	// 		cout << string(all(a[i][j])) << " ";
	// 	}
	// 	cout << "\n";
	// }

	

	FOR (i, 1, n - 1) {
		FOR (j, 0, m - 2) {
			FOR (it, b[i][j].rbegin(), --b[i][j].rend()) {
				if (*it == '0') {
					Move(0, j, i, j);
				} else {
					Move(i, m - 1, i, j);
				}
			}
		}
	}
	


	NFOR (i, n - 1, 1) {
		FOR (it, 1, sz(b[i][m - 1])) {
			Move(0, m - 1, i, m - 1);
		}
	}

	NFOR (i, m - 2, 0) {
		FOR (it, 1, sz(b[0][i])) {
			Move(0, m - 1, 0, i);
		}
	}

	// 4s done
	int len = 0;
	FOR (i, 0, n - 1) FOR (j, 0, m - 1) len += sz(a[i][j]);
	assert(a == b);
	if (sz(ans) > 4*len) {
		while (1);
	}
	cout << sz(ans) << "\n";
	for (auto it : ans) {
		cout << it.F.F << " " << it.F.S << " " << it.S.F << " " << it.S.S << "\n";
	}

	return 0;
}