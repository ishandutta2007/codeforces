#include <cstdio>
#include <algorithm>
#include <utility>
#include <iterator>
#include <set>

// high ... [1111111] ... low
//          ^      ^
//          se     fi
std::set<std::pair<int, int>> st;

void ins(int x) {
	auto it = std::prev(st.lower_bound({x + 1, -9}));
	if (x >= it->second) {
		auto it2 = std::next(it);
		int lb = x, rb = x + 1;
		if (it->second == lb)
			lb = it->first,
			st.erase(it);
		if (it2 != st.end() && rb == it2->first)
			rb = it2->second,
			st.erase(it2);
		st.insert({lb, rb});
	} else {
		int lb = it->first, rb = it->second;
		st.erase(it);
		if (x > lb)
			st.insert({lb, x});
		ins(rb);
	}
}

void del(int x) {
	auto it = std::prev(st.lower_bound({x + 1, -9}));
	if (x < it->second) {
		int lb = it->first, rb = it->second;
		st.erase(it);
		if (x > lb)
			st.insert({lb, x});
		if (rb > x + 1)
			st.insert({x + 1, rb});
	} else {
		int lb = x, rb = std::next(it)->first;
		del(rb);
		if (lb == it->second)
			lb = it->first,
			st.erase(it);
		st.insert({lb, rb});
	}
}

int main() {
	st.insert({-2, -1});
	constexpr int MN = 200005;
	int n, q;
	static int a[MN];
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		ins(a[i]);
	}
	for (int i = 1; i <= q; ++i) {
		int p, x;
		scanf("%d%d", &p, &x);
		del(a[p]);
		ins(a[p] = x);
		auto it = std::prev(st.end());
		printf("%d\n", it->second - 1);
	}
	return 0;
}