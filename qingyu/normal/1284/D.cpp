#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n;

struct hasher {
	uint64_t a, b, c;
	hasher(uint64_t a = 0, uint64_t b = 0, uint64_t c = 0) : a(a), b(b), c(c) {

	}
	inline hasher operator+(const hasher &rhs) const {
		return hasher(a ^ rhs.a, b ^ rhs.b, c ^ rhs.c);
	}
	inline hasher operator+=(const hasher &rhs) {
		a ^= rhs.a;
		b ^= rhs.b;
		c ^= rhs.c;
		return *this;
	}
	inline bool operator==(const hasher &rhs) const {
		return a == rhs.a && b == rhs.b && c == rhs.c;
	}
	inline bool operator!=(const hasher &rhs) const {
		return a != rhs.a || b != rhs.b || c != rhs.c;
	}
} v[N], va[N], vb[N], s[N];

struct event_t {
	int p, t, id;
	event_t(int p, int t, int id) : p(p), t(t), id(id) {

	}
	inline bool operator<(const event_t &rhs) const {
		if (p != rhs.p) return p < rhs.p;
		return t < rhs.t;
	}
};

std::vector<event_t> a, b;

std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		v[i].a = rnd();
		v[i].b = rnd();
		v[i].c = rnd();
		int l1, r1, l2, r2;
		std::cin >> l1 >> r1 >> l2 >> r2;
		a.emplace_back(l1, 0, i);
		a.emplace_back(r1, 1, i);
		b.emplace_back(l2, 0, i);
		b.emplace_back(r2, 1, i);
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	hasher cur(0, 0, 0);
	for (auto [p, t, id] : a) {
		if (t == 0) {
			va[id] += cur;
		}
		else {
			cur += v[id];
		}
	}
	std::reverse(a.begin(), a.end());
	cur = hasher(0, 0, 0);
	for (auto [p, t, id] : a) {
		if (t == 1) {
			va[id] += cur;
		}
		else {
			cur += v[id];
		}
	}
	cur = hasher(0, 0, 0);
	for (auto [p, t, id] : b) {
		if (t == 0) {
			vb[id] += cur;
		}
		else {
			cur += v[id];
		}
	}
	std::reverse(b.begin(), b.end());
	cur = hasher(0, 0, 0);
	for (auto [p, t, id] : b) {
		if (t == 1) {
			vb[id] += cur;
		}
		else {
			cur += v[id];
		}
	}
	for (int i = 1; i <= n; ++i)
		if (va[i] != vb[i]) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}