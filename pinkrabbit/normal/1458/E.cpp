#include <cstdio>
#include <algorithm>
#include <set>

#define fi first
#define se second
typedef std::pair<int, int> pii;
const int MN = 100005, MQ = 100005;

int N, Q;
int gX[MN], gY[MN], per[MN];
int qX[MQ], qY[MQ];
std::set<pii> forbid0, interval;
std::set<std::pair<pii, int>> forbid1;

inline void Del(int x) {
	auto it = interval.lower_bound({x + 1, 0});
	if (it == interval.begin()) return ;
	pii p = *--it;
	if (p.se < x) return ;
	interval.erase(it);
	if (x > p.fi) interval.insert({p.fi, x - 1});
	if (x < p.se) interval.insert({x + 1, p.se});
}

inline void Add(int lb, int rb) {
	while (lb <= rb && !interval.empty()) {
		auto it = interval.begin();
		pii p = *it;
		interval.erase(it);
		if (rb - lb + 1 < p.se - p.fi + 1) {
			// (p.fi, lb) -> (?, rb)
//			printf("(%d, %d) -> (%d, %d) 1\n", p.fi, lb, p.fi + (rb - lb), rb);
			forbid1.insert({{lb, rb}, p.fi});
			interval.insert({p.fi + (rb - lb + 1), p.se});
			lb = rb + 1;
		} else {
			// (p.fi, lb) -> (p.se, ?)
//			printf("(%d, %d) -> (%d, %d) 2\n", p.fi, lb, p.se, lb + (p.se - p.fi));
			forbid1.insert({{lb, lb + (p.se - p.fi)}, p.fi});
			lb += p.se - p.fi + 1;
		}
	}
}

inline bool Check(int x, int y) {
	if (forbid0.count({x, y})) return 1;
	auto it = forbid1.lower_bound({{y + 1, 0}, 0});
	if (it == forbid1.begin()) return 0;
	auto p = *--it;
	if (p.fi.se < y) return 0;
	if (p.fi.fi - p.se == y - x) return 1;
	return 0;
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) scanf("%d%d", &gX[i], &gY[i]), per[i] = i;
	for (int i = 1; i <= N; ++i) forbid0.insert({gX[i], gY[i]});
	for (int i = 1; i <= Q; ++i) scanf("%d%d", &qX[i], &qY[i]);
	std::sort(per + 1, per + N + 1, [](int i, int j) { return gY[i] < gY[j]; });
	int lstyC = -1;
	interval.insert({0, 0x3f3f3f3f});
	for (int id = 1; id <= N; ) {
		int yC = gY[per[id]];
		if (yC - lstyC >= 2) Add(lstyC + 1, yC - 1);
		lstyC = yC;
		int mnx = 0x3f3f3f3f;
		while (id <= N && gY[per[id]] == yC)
			mnx = std::min(mnx, gX[per[id]]), Del(gX[per[id]]), ++id;
		if (interval.begin()->fi < mnx) {
			auto it = interval.begin();
			pii p = *it;
			interval.erase(it);
			forbid0.insert({p.fi, yC});
//			printf("(%d, %d)\n", p.fi, yC);
			if (p.fi < p.se) interval.insert({p.fi + 1, p.se});
		}
	}
	Add(lstyC + 1, 0x3f3f3f3f);
	for (int i = 1; i <= Q; ++i) puts(Check(qX[i], qY[i]) ? "LOSE" : "WIN");
	return 0;
}