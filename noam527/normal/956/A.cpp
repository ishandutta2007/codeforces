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
const ldb eps = 1e-7, pi = acos(-1);
using namespace std;

int n, m;
char a[50][50];
bool r[50] = {}, c[50] = {};

int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	vector<int> pos;
	int cnt;
	for (int i = 0; i < n; i++) {
		pos.clear();
		for (int j = 0; j < m; j++) if (a[i][j] == '#') pos.push_back(j);
		if (pos.size()) {
			for (int k = i + 1; k < n; k++) {
				cnt = 0;
				for (const auto &x : pos) if (a[k][x] == '#') cnt++;
				if (cnt > 0 && cnt < pos.size()) finish("No");
				if (cnt > 0) {
					cnt = 0;
					for (int j = 0; j < m; j++) if (a[k][j] == '#') cnt++;
					if (cnt > pos.size()) finish("No");
				}
			}
		}
	}
	cout << "Yes" << endl;
}