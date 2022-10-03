#include <cstdio>
#include <algorithm>
#include <set>

typedef long long LL;
const int MN = 800005;

struct Point {
	LL x, y;
	LL val() const {
		return x + y;
	}
	bool operator < (const Point &q) const {
		return val() < q.val();
	}
};

int N;
Point p[MN];

std::multiset<LL> st1, st2;
LL val, tag;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	std::sort(p + 1, p + N + 1);
	st1.insert(p[1].x);
	st2.insert(p[1].x);
	val = 0, tag = 0;
	for (int i = 2; i <= N; ++i) {
		tag += p[i].val() - p[i - 1].val();
		LL lb = *st1.rbegin();
		LL rb = *st2.begin() + tag;
		LL pos = p[i].x;
		if (pos < lb) {
			val += lb - pos;
			st2.insert(lb - tag);
			st1.erase(--st1.end());
			st1.insert(pos);
			st1.insert(pos);
		} else if (rb < pos) {
			val += pos - rb;
			st1.insert(rb);
			st2.erase(st2.begin());
			st2.insert(pos - tag);
			st2.insert(pos - tag);
		} else {
			st1.insert(pos);
			st2.insert(pos - tag);
		}
	}
	printf("%lld\n", val);
	return 0;
}