#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, w;

struct Fraction {
	int x, y;

	Fraction(int x = 0, int y = 1) {
		if (y < 0) {
			y = -y;
			x = -x;
		}
		this->x = x;
		this->y = y;
	}

	const bool operator < (const Fraction &u) const {
		return 1ll * x * u.y < 1ll * u.x * y;
	}

	const bool operator == (const Fraction &u) const {
		return 1ll * x * u.y == 1ll * u.x * y;
	}
};

struct BIT {
	int t[N];

	void add(int x, int v) {
		while (x < N) {
			t[x] += v;
			x += (x & -x);
		}
	}

	int get(int x) {
		int res = 0;
		while (x) {
			res += t[x];
			x -= (x & -x);
		}
		return res;
	}
} t;

pair<Fraction, Fraction> a[N];
Fraction val[N];

int main() {
	scanf("%d %d", &n, &w);
	for (int i = 1; i <= n; i++) {
		int x, v;
		scanf("%d %d", &x, &v);
		a[i].first = Fraction(x, v - w);
		a[i].second = Fraction(x, v + w);
		val[i] = a[i].second;
	}
	sort(a + 1, a + n + 1);
	sort(val + 1, val + n + 1);
	// cout << endl;
	// for (int i = 1; i <= n; i++) {
	// 	cout << a[i].first.x << " " << a[i].first.y << " " << a[i].second.x << " " << a[i].second.y << endl;
	// }
	long long res = 0;
	for (int start = 1, finish = 1; start <= n; start = finish) {
		while (a[start].first == a[finish].first && finish <= n) {
			finish++;
		}
		for (int i = start; i < finish; i++) {
			int pos = lower_bound(val + 1, val + n + 1, a[i].second) - val - 1;
			res += t.get(n) - t.get(pos);
		}
		res += 1ll * (finish - start) * (finish - start - 1) / 2;
		for (int i = start; i < finish; i++) {
			int pos = lower_bound(val + 1, val + n + 1, a[i].second) - val;
			t.add(pos, 1);
		}
		// cout << res << endl;
	}
	cout << res << endl;
	return 0;
}