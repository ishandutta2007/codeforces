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

const int lim = 1e6 + 5;

int d[lim];
vector<int> p;

void pre() {
	vector<bool> b(lim, true);
	int i;
	for (i = 2; i * i < lim; i++) {
		if (b[i]) {
			p.push_back(i);
			for (int j = i * i; j < lim; j += i) b[j] = false;
		}
	}
	for (; i < lim; i++) if (b[i]) p.push_back(i);

	for (int i = 0; i < lim; i++) d[i] = 1;
	for (const auto &i : p)
		for (int j = 2 * i; j < lim; j += i) d[j] = i;
}

int main() {
	fast;
	int x;
	cin >> x;

	pre();

	int mn = 2e9;
	for (int i = x - d[x] + 1; i <= x; i++) mn = min(mn, i - d[i] + 1);
	cout << mn << endl;
}