// Apparentally Judgement failed.... resubmitting

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, m, a[200002], b[200002], p[200002];

int findset(int x) {
	if (x != p[x])
		p[x] = findset(p[x]);
	return p[x];
}

void unite(int x, int y) {
	x = findset(x), y = findset(y);
	if (x != y) p[x] = y;
}

void fill(int x, int v) {
	if (x == n || v == 0) return;
	if (x != findset(x)) fill(findset(x), v);
	else {
		if (a[x] - b[x] > v) b[x] += v;
		else {
			v -= (a[x] - b[x]);
			b[x] = a[x];
			unite(x, x + 1);
			fill(findset(x), v);
		}
	}
}

int query(int x) { return b[x]; }

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], p[i] = i, b[i] = 0;
	p[n] = n;
	cin >> m;

	int p1, p2, p3;
	while (m--) {
		cin >> p1;
		if (p1 == 1) {
			cin >> p2 >> p3;
			fill(p2 - 1, p3);
		}
		else {
			cin >> p2;
			cout << query(p2 - 1) << endl;
		}
	}
}