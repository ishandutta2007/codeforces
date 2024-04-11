#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <unordered_set>
#include <random>
#include <unordered_map>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
int n, h;
int l, r;
int qCount = 0;
vector<int> sons[sz];
random_device rd;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(int a, int b, int c) {
	cout << "? " << a << ' ' << b << ' ' << c << '\n';
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

int randomNoGenerator(int limit) {
	return uniform_int_distribution<int>(1, limit)(rng);
}

void findLR(int xBound, int bBound) {
	const int x = xBound, bound = bBound;
	while (true) {
		l = randomNoGenerator(n), r = randomNoGenerator(n);
		if (l == r)continue;
		int tx = x;
		unordered_map<int, int> mem;
		while (tx--) {
			int p = randomNoGenerator(n);
			if (p == l or p == r)continue;
			mem[ask(l, r, p)]++;
		}
		int mx = 0;
		for (auto pt : mem)mx = max(mx, pt.second);
		if (mx < bound)return;
	}
}

int getX() {
	if (h >= 5)return 30;
	else if (h > 3)return 51;
	else return 70;
}

int getB() {
	if (h >= 5)return 12;
	else if (h > 3)return 20;
	else return 30;
}


void solveSmall() {
	unordered_set<int> found;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			for (int k = 1; k <= n; k++) {
				if (i == k or j == k)continue;
				int ans = ask(i, j, k);
				found.insert(ans);
			}
		}
	}
	vector<int> v;
	for (int x : found)v.pb(x);
	int ret = ask(v[0], v[1], v[2]);
	cout << "! " << ret << '\n';
}


int main() {
	cin >> h;
	n = (1 << h) - 1;
	if (h == 3) {
		solveSmall();
		return 0;
	}
	int xBound = getX(), bBound = getB();
	findLR(xBound, bBound);
	vector<int> path;
	for (int i = 1; i <= n; i++) {
		if (i == l or i == r)continue;
		int q = ask(l, r, i);
		if (q == i)path.push_back(i);
		else sons[q].pb(i);
	}
	for (int x : path) {
		if (x != l and x != r and sons[x].empty()) {
			cout << "! " << x << '\n';
			return 0;
		}
	}
	return 0;
}