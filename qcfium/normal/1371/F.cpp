#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
typedef enum {
	NONE,
	SINGLE,
	DOUBLE
} Type;

struct Payload {
	Type type = NONE;
	int left = 0;
	int right = 0;
	int max = 0;
	Payload () = default;
	Payload (bool flag) {
		type = SINGLE;
		max = 1;
		left = right = flag ? 1 : -1;
	}
	Payload (int type, int left, int right, int max) : type((Type) type), left(left), right(right), max(max) {}
	Payload operator * (const Payload &rhs) {
		if (type == NONE) return rhs;
		if (rhs.type == NONE) return *this;
		if ((right < 0) == (rhs.left < 0) || (right > 0 && rhs.left < 0)) {
			int added = std::abs(right) + std::abs(rhs.left);
			Type new_type = type == SINGLE && rhs.type == SINGLE ? SINGLE : DOUBLE;
			int new_left = type == SINGLE ? added * (left < 0 ? -1 : 1) : left;
			int new_right = rhs.type == SINGLE ? added * (rhs.right < 0 ? -1 : 1) : rhs.right;
			int new_max = std::max({max, rhs.max, added});
			return {new_type, new_left, new_right, new_max};
		} else return {DOUBLE, left, rhs.right, std::max(max, rhs.max)};
	}
};
struct Payload2 {
	Payload r0, r1;
	Payload2 () = default;
	Payload2 (bool flag) : r0(flag), r1(!flag) {}
	Payload2 (Payload r0, Payload r1) : r0(r0), r1(r1) {}
	Payload2 operator * (const Payload2 &rhs) {
		return {r0 * rhs.r0, r1 * rhs.r1};
	}
	void flip() { std::swap(r0, r1); }
};
struct SegTree {
	int n;
	std::vector<Payload2> data;
	std::vector<bool> flipped;
	SegTree (std::string s) {
		for (n = 1; n < (int) s.size(); n <<= 1);
		data.resize(n << 1);
		for (int i = 0; i < (int) s.size(); i++) data[i + n] = Payload2(s[i] == '>');
		for (int i = n; --i; ) data[i] = data[i << 1] * data[i << 1 | 1];
		flipped.resize(n << 1);
	}
	void flush(int i) {
		if (flipped[i]) {
			data[i].flip();
			if (i < n) flipped[i << 1].flip(), flipped[i << 1 | 1].flip();
			flipped[i] = false;
		}
	}
	template<class T> void dive(int l, int r, int node, int node_l, int node_r, const T &func) {
		flush(node);
		if (r <= node_l || l >= node_r) return;
		if (l <= node_l && r >= node_r) {
			func(node);
		} else {
			int mid = node_l + ((node_r - node_l) >> 1);
			dive(l, r, node << 1, node_l, mid, func);
			dive(l, r, node << 1 | 1, mid, node_r, func);
			data[node] = data[node << 1] * data[node << 1 | 1];
		}
	}
	void flip(int l, int r) {
		dive(l, r, 1, 0, n, [&] (int i) { flipped[i].flip(); flush(i); });
	}
	int max(int l, int r) {
		Payload2 res;
		dive(l, r, 1, 0, n, [&] (int i) { res = res * data[i]; });
		return res.r0.max;
	}
};

int main() {
	int n = ri();
	int q = ri();
	std::string s;
	std::cin >> s;
	SegTree tree(s);
	for (int i = 0; i < q; i++) {
		int l = ri() - 1;
		int r = ri();
		tree.flip(l, r);
		printf("%d\n", tree.max(l, r));
	}
	return 0;
}