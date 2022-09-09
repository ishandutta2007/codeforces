// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int SZ = 253;
int d[SZ][SZ][SZ];

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	vector<vector<int>> next(26, vector<int>(szof(s) + 1, INF));
	{
		vector<int> tmp(26, INF);
		for (int i = szof(s) - 1; i >= 0; --i) {
			tmp[s[i] - 'a'] = i;
			for (int j = 0; j < 26; ++j) {
				next[j][i] = tmp[j];
			}
		}
	}

	int sz[3] = {0, 0, 0};
	vector<string> arrt(3);
	d[0][0][0] = 0;
	for (int i = 0; i < q; ++i) {
		char t;
		int ind;
		cin >> t >> ind;
		--ind;
		if (t == '-') {
			sz[ind]--;
			arrt[ind].pop_back();
		} else {
			char c;
			cin >> c;
			sz[ind]++;
			arrt[ind].push_back(c);
			for (int x = 0; x <= sz[0]; ++x) {
				if (ind == 0 && x < sz[0]) {
					continue;
				}
				for (int y = 0; y <= sz[1]; ++y) {
					if (ind == 1 && y < sz[1]) {
						continue;
					}
					for (int z = 0; z <= sz[2]; ++z) {
						if (ind == 2 && z < sz[2]) {
							continue;
						}

						d[x][y][z] = INF;
						if (x && d[x - 1][y][z] < INF) {
							d[x][y][z] = min(d[x][y][z], next[arrt[0][x - 1] - 'a'][d[x - 1][y][z]] + 1);
						}

						if (y && d[x][y - 1][z] < INF) {
							d[x][y][z] = min(d[x][y][z], next[arrt[1][y - 1] - 'a'][d[x][y - 1][z]] + 1);
						}

						if (z && d[x][y][z - 1] < INF) {
							d[x][y][z] = min(d[x][y][z], next[arrt[2][z - 1] - 'a'][d[x][y][z - 1]] + 1);
						}
					}
				}
			}
		}
		// for (int x = 0; x <= sz[0]; ++x) {
		// 	for (int y = 0; y <= sz[1]; ++y) {
		// 		for (int z = 0; z <= sz[2]; ++z) {
		// 			cerr << d[x][y][z] << " ";
		// 		}
		// 		cerr << endl;
		// 	}
		// 	cerr << endl;
		// }
		if (d[sz[0]][sz[1]][sz[2]] <= n) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}