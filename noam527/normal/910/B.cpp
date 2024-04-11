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

int n, a, b, mn = 1e9;

void check(vector<int> &x, vector<bool> &took, int left = 0, int dis = 0) {
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (!took[i]) {
			cnt++, took[i] = true;
			if (x[i] <= left)
				check(x, took, left - x[i], dis);
			check(x, took, n - x[i], dis + 1);
			took[i] = false;
		}
	}
	if (!cnt) mn = min(mn, dis);
}

int main() {
	fast;
	cin >> n >> a >> b;
	vector<int> tot = { a,a,a,a,b,b };
	vector<bool> took(6, false);
	check(tot, took);
	cout << mn << endl;
}