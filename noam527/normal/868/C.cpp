#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-7, pi = acos(-1);
using namespace std;

bool good = false;
int n, k;
char c;
set<string> a;
vector<string> b;

void check(int t, vector<int> m, int i = 0) {
	if (i == b.size()) {
		if (t > 0) {
			for (int j = 0; j < m.size(); j++)
				if (m[j] * 2 > t) return;
			good = true;
		}
		return;
	}
	check(t, m, i + 1);
	for (int j = 0; j < b[i].size(); j++)
		if (b[i][j] == '1') m[j]++;
	check(t + 1, m, i + 1);
}

int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string temp = "";
		for (int j = 0; j < k; j++) cin >> c, temp.push_back(c);
		a.insert(temp);
	}
	for (auto &i : a) b.push_back(i);
	check(0, vector<int>(k, 0));
	if (good) cout << "YES" << endl;
	else cout << "NO" << endl;
}