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
#include <fstream>
#include <random>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
vector<int> a = { 0, 1 }, b = { 1 }, c;

void upda() {
	vector<int> rtn = { 0 };
	for (auto &i : a) rtn.push_back(i);
	a = rtn;
}

int main() {
	fast;
	cin >> n;
	for (int x = 1; x < n; x++) {
		c = a;
		upda();

		bool good = true;
		for (int i = 0; i < b.size(); i++) if (a[i] + b[i] > 1 || a[i] + b[i] < -1) good = false;

		if (good) {
			for (int i = 0; i < b.size(); i++) a[i] += b[i];
		}
		else {
			good = true;
			for (int i = 0; i < b.size(); i++) if (a[i] - b[i] > 1 || a[i] - b[i] < -1) good = false;
			if (good) for (int i = 0; i < b.size(); i++) a[i] -= b[i];
			else {
				cout << "stuck. " << x << endl;
				return 0;
			}
		}
		b = c;
	}
	cout << a.size() - 1 << endl;
	for (auto &i : a) cout << i << " "; cout << endl;
	cout << b.size() - 1 << endl;
	for (auto &i : b) cout << i << " "; cout << endl;
}