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

const int lim = 2e6;

struct dsu {
	int n;
	vector<int> p;
	dsu(int size = 0) {
		n = size;
		p.resize(n);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	void erase(int val) {
		if (p[val] == val) p[val] = val + 1;
	}
	int find(int val) {
		if (val == p[val]) return val;
		p[val] = find(p[val]);
		return p[val];
	}
};

vector<int> p;
int divi[lim];
bool b[lim] = {}, did[lim] = {};

void sieve() {
	int i = 2;
	for (; i * i < lim; i++) {
		if (!b[i]) {
			p.push_back(i);
			for (int j = i * i; j < lim; j += i)
				b[j] = true, divi[j] = i;
		}
	}
	for (; i < lim; i++) if (!b[i]) p.push_back(i);
}

int n;
vector<int> a, ans;
dsu can;

vector<int> divisors(int val) {
	vector<int> rtn;
	while (val > 1) {
		if (!b[val]) rtn.push_back(val), val = 1;
		else {
			rtn.push_back(divi[val]);
			val /= divi[val];
		}
	}
	return rtn;
}

void update(int val) {
	static vector<int> tmp;
	tmp = divisors(val);
	for (const auto &i : tmp) {
		if (can.find(i) == i) {
			for (int j = i; j < lim; j += i) can.erase(j);
		}
	}
}

int main() {
	fast;
	sieve();

	cin >> n;
	a.resize(n);
	ans.resize(n);
	can = dsu(lim + 5);
	for (auto &i : a) cin >> i;

	bool exceed = false;
	int tmp;

	for (int i = 0; i < n; i++) {
		if (!exceed) {
			tmp = can.find(a[i]);
//			cout << "search " << a[i] << " found " << tmp << endl;
			ans[i] = tmp;
			if (tmp > a[i]) exceed = true;
		}
		else {
			tmp = can.find(2);
			ans[i] = tmp;
		}
		update(tmp);
	}
	for (const auto &i : ans) cout << i << " "; cout << endl;
}