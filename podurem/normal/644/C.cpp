#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forq(i, q, n) for (int i = (int)q; i < (int)n; ++i)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define X first
#define Y second
#define TASK "triangles"

const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-6;

int kk;
vi ans;
vector <bool> used;
vector <vi> G;

bool comp(pair <set <string>, int> a, pair <set <string>, int> b) {
	if (a.X.size() != b.X.size()) {
		return a.X.size() < b.X.size();
	}
	return a.X < b.X;
}

void dfs(int x) {
	++kk;
	used[x] = 1;
	ans.psh(x);
	forn(i, G[x].size()) {
		if (!used[G[x][i]]) {
			dfs(G[x][i]);
		}
	}
}

int main() {
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string s, s1, s2;
	int kol;
	map <string, set <string> > mm;
	forn(i, n) {
		cin >> s;
		s1 = "";
		s2 = "";
		kol = 0;
		forn(i, s.size()) {
			if (s[i] == '/') {
				++kol;
				if (kol <= 2) {
					continue;
				}
			}
			if (kol < 2) {
				continue;
			}
			if (kol == 2) {
				s1 += s[i];
			}
			else {
				s2 += s[i];
			}
		}
		mm[s1].insert(s2);
	}
	vector <pair <set <string>, int> > ass(mm.size());
	vector <string> ind(mm.size());
	kol = 0;
	for (auto it = mm.begin(); it != mm.end(); it++) {
		ind[kol] = it->X;
		ass[kol] = mk(it->Y, kol);
		kol++;
	}
	sort(all(ass), comp);
	G.resize(mm.size());
	forn(i, mm.size() - 1) {
		if (ass[i].X == ass[i + 1].X) {
			G[ass[i].Y].psh(ass[i + 1].Y);
			G[ass[i + 1].Y].psh(ass[i].Y);
		}
	}
	vector <vector <string> > ans1;
	used.resize(mm.size(), 0);
	forn(i, mm.size()) {
		if (!used[i]) {
			kk = 0;
			ans = vi(0);
			dfs(i);
			if (kk > 1) {
				ans1.psh(vector <string>(0));
				forn(j, kk) {
					ans1[ans1.size() - 1].psh(ind[ans[j]]);
				}
			}
		}
	}
	cout << ans1.size() << "\n";
	forn(i, ans1.size()) {
		forn(j, ans1[i].size()) {
			cout << "http://" << ans1[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}