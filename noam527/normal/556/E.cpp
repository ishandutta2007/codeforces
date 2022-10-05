#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, q, x, y;
char c;

struct shape {
	int l, r, h, w;
	shape(int l = 0, int r = 0, int h = 0, int w = 0) : l(l), r(r), h(h), w(w) {};
	pair<shape, shape> cut(int x, char d) {
		int l1 = l, r1 = x - 1, l2 = x + 1, r2 = r, h1, w1, h2, w2;
		w1 = w, h2 = h;
		if (d == 'U') {
			h1 = h + r - r1;
			w2 = 0;
		}
		else {
			h1 = 0;
			w2 = w + l2 - l;
		}
		if (l1 > r1)
			l1 = r1 = h1 = w1 = -1;
		if (l2 > r2)
			l2 = r2 = h2 = w2 = -1;
		return make_pair(shape(l1, r1, h1, w1), shape(l2, r2, h2, w2));
	}
};

void show(map<int, shape> &m) {
	for (auto i = m.begin(); i != m.end(); i++)
		cout << i->second.l << " " << i->second.r << " " << i->second.h << " " << i->second.w << endl;
	cout << endl;
}

int main() {
	fast;
	cin >> n >> q;
	map<int, shape> m;
	m[1] = shape(1, n, 0, 0);
	while (q--) {
		cin >> x >> y >> c;
		auto it = m.upper_bound(x);
		if (it == m.begin())
			cout << 0 << endl;
		else {
			it--;
			if (x > it->second.r)
				cout << 0 << endl;
			else {
				shape s = it->second;
				if (c == 'U')
					cout << s.h + s.r - x + 1 << endl;
				else
					cout << s.w + x - s.l + 1 << endl;
				pair<shape, shape> temp = s.cut(x, c);
				m.erase(it);
				if (temp.first.l != -1)
					m[temp.first.l] = temp.first;
				if (temp.second.l != -1)
					m[temp.second.l] = temp.second;
			}
		}
	}
	return 0;
}