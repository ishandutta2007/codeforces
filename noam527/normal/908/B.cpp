#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, ans = 0;
string op;
pair<int, int> st;
char c[52][52];
vector<int> perm = { 0,1,2,3 }; // u,r,d,l

void chk() {
	for (auto &i : op) {
		if (perm[i - '0'] == 0) st.first--;
		if (perm[i - '0'] == 1) st.second++;
		if (perm[i - '0'] == 2) st.first++;
		if (perm[i - '0'] == 3) st.second--;

		if (c[st.first][st.second] == '#') return;
		if (c[st.first][st.second] == 'E') {
			ans++;
			return;
		}
	}
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++) c[i][0] = c[i][m + 1] = '#';
	for (int i = 0; i <= m + 1; i++) c[0][i] = c[n + 1][i] = '#';

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		cin >> c[i][j];
		if (c[i][j] == 'S') st = { i, j };
	}
	cin >> op;
	pair<int, int> t1;

	for (int i = 0; i < 24; i++) {
		t1 = { st.first, st.second };
		chk();
		st = { t1.first, t1.second };
		next_permutation(perm.begin(), perm.end());
	}
	cout << ans << endl;
}