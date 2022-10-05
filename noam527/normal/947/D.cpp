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
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

const int maxn = 1e5 + 10;

int n, m;
string s, t;
int bcnt[2][maxn], acnt[2][maxn];

int main() {
	fast;
	cin >> s >> t;
	for (auto &i : s) if (i == 'C') i = 'B';
	for (auto &i : t) if (i == 'C') i = 'B';
	n = s.size(), m = t.size();

	bcnt[0][0] = bcnt[1][0] = 0;
	for (int i = 1; i <= n; i++)
		bcnt[0][i] = bcnt[0][i - 1] + (s[i - 1] == 'B' ? 1 : 0);
	for (int i = 1; i <= m; i++)
		bcnt[1][i] = bcnt[1][i - 1] + (t[i - 1] == 'B' ? 1 : 0);

	acnt[0][0] = acnt[1][0] = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == 'A') acnt[0][i] = 1 + acnt[0][i - 1];
		else acnt[0][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		if (t[i - 1] == 'A') acnt[1][i] = 1 + acnt[1][i - 1];
		else acnt[1][i] = 0;
	}

	int q, p[4], pa[4];
	cin >> q;
	while (q--) {
		cin >> p[0] >> p[1] >> p[2] >> p[3];
		pa[0] = bcnt[0][p[1]] - bcnt[0][p[0] - 1];
		pa[1] = min(acnt[0][p[1]], p[1] - p[0] + 1);

		pa[2] = bcnt[1][p[3]] - bcnt[1][p[2] - 1];
		pa[3] = min(acnt[1][p[3]], p[3] - p[2] + 1);

		if (pa[1] < pa[3] || pa[0] % 2 != pa[2] % 2) cout << 0;
		else {
			if (pa[0] == 0 && pa[0] < pa[2] && pa[1] <= pa[3]) cout << 0;
			else {
				if (pa[0] == 0 && pa[0] < pa[2]) pa[1]--, pa[0] += 2;
				else if (pa[1] % 3 != pa[3] % 3) pa[0] += 2;
				if (pa[0] > pa[2]) cout << 0;
				else cout << 1;
			}
		}
	}

}