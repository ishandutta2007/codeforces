/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	while (b > 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void norm(int &x, int &y) {
	int g = gcd(x, y);
	if (g != 1 && g != 0) {
		x /= g;
		y /= g;
	}
	if (x < 0 || (x == 0 && y < 0)) {
		x = -x;
		y = -y;
	}
}

struct point {
	int x, y, id;

	long long len() const {
		return (long long) x * x + (long long) y * y;
	}

	bool operator<(point const &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}

	bool operator==(point const &a) const {
		return x == a.x && y == a.y;
	}

	point norm() const {		
		int x = this->x;
		int y = this->y;
		::norm(x, y);
		return {x, y, -1};
	}
};


point add(point const &a, point const &b) {
	int x = a.x + b.x;
	int y = a.y + b.y;
	norm(x, y);
	return {x, y, -1};
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int q;
	cin >> q;
	unordered_map<long long, vector<point> > all;
	map<point, int> have;
	int n = 0;
	for (int cq = 0; cq < q; cq++) {
		int type, x, y;
		cin >> type >> x >> y;
		point p = {x, y, cq};
		if (type == 1) {
			auto &f = all[p.len()];
			for (auto &e : f) {
				have[add(e, p).norm()] += 2;
			}
			have[p.norm()]++;
			f.push_back(p);
			++n;
		} else if (type == 2) {
			auto &f = all[p.len()];
			int index = -1;
			for (int id = 0; id < (int) f.size(); id++) {
				if (f[id] == p) {
					index = id;
					break;
				}
			}
			swap(f[index], f.back());
			f.pop_back();
			for (auto &e : f) {
				point val = add(e, p).norm();
				int &z = have[val];
				z -= 2;
				if (z == 0) {
					have.erase(val);
				}
			}
			int &z = have[p.norm()];
			z--;
			if (z == 0) have.erase(p.norm());
			--n;
		} else {
			cout << n - have[p.norm()] << '\n';
		}
	}
}