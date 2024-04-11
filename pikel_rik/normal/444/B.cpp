#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d, x;
	cin >> n >> d >> x;

	vector<int> a(n), b(n);

	auto getNextX = [&](void) -> int {
		x = (x * 37ll + 10007) % 1000000007;
		return x;
	};

	auto initAB = [&](void) -> void {
		for(int i = 0; i < n; i = i + 1){
			a[i] = i + 1;
		}
		for(int i = 0; i < n; i = i + 1){
			swap(a[i], a[getNextX() % (i + 1)]);
		}
		for(int i = 0; i < n; i = i + 1){
			if (i < d)
				b[i] = 1;
			else
				b[i] = 0;
		}
		for(int i = 0; i < n; i = i + 1){
			swap(b[i], b[getNextX() % (i + 1)]);
		}
	};

	initAB();

	vector<int> c(n), p(n + 1);
	iota(p.begin(), p.end(), 0);

	auto find = [&](int x, const auto &self) -> int {
		return x == p[x] ? x : p[x] = self(p[x], self);
	};

	vector<int> ones, pos(n + 1);
	ones.reserve(d);
	for (int i = 0; i < n; i++) {
		pos[a[i]] = i;
		if (b[i] == 1) {
			ones.push_back(i);
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < d && pos[i] + ones[j] < n;) {
			if (find(ones[j] + pos[i], find) == ones[j] + pos[i]) {
				c[ones[j] + pos[i]] = i;
				p[ones[j] + pos[i]] += 1;
				j += 1;
			} else {
				while (j < d && ones[j] + pos[i] < n && find(ones[j] + pos[i], find) != ones[j] + pos[i]) {
					int idx = find(ones[j] + pos[i], find);
					j = lower_bound(ones.begin() + j, ones.end(), idx - pos[i]) - ones.begin();
				}
			}
		}
	}

	for (auto &e : c) cout << e << '\n';
	return 0;
}