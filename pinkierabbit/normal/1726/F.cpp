#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <iterator>
using std::scanf, std::printf;

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) std::fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

void Solve();
int main() {
	int tests = 1;
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

typedef long long LL;
const int Mod = 998244353;

const int Inf = 0x3f3f3f3f;
const LL InfLL = 0x3f3f3f3f3f3f3f3f;

const int MN = 500005;

int n, t;
int g[MN], c[MN], d[MN];

void Solve() {
	scanf("%d%d", &n, &t);
	F(i, 1, n) scanf("%d%d", &g[i], &c[i]);
	LL sumd = 0;
	F(i, 1, n - 1) {
		scanf("%d", &d[i]);
		sumd += d[i];
		d[i] = (d[i - 1] + d[i]) % t;
		c[i + 1] = (c[i + 1] + d[i]) % t;
	}
	std::map<int, std::pair<int, LL>> dat;
	dat[0] = {t - 1, 0ll};
	auto sum = [&dat](int l, int r) -> LL {
		auto it1 = std::prev(dat.upper_bound(l));
		auto it2 = std::prev(dat.upper_bound(r));
		auto it = it1;
		LL ret = 0;
		while (true) {
			const auto [lb, se] = *it;
			const auto [rb, val] = se;
			int tlb = std::max(lb, l);
			int trb = std::min(rb, r);
			ret += val * (trb - tlb + 1);
			if (it == it2)
				break;
			++it;
		}
		return ret;
	};
	auto chto = [&dat](int lb, int rb, LL val) -> void {
		auto it1 = std::prev(dat.upper_bound(lb));
		auto it2 = std::prev(dat.upper_bound(rb));
		int l = 0, ll = 0, lr = 0; LL lv = 0;
		if (it1->first < lb) {
			l = 1;
			ll = it1->first;
			lr = lb - 1;
			lv = it1->second.second;
		}
		int r = 0, rl = 0, rr = 0; LL rv = 0;
		if (it2->second.first > rb) {
			r = 1;
			rl = rb + 1;
			rr = it2->second.first;
			rv = it2->second.second;
		}
		dat.erase(it1, std::next(it2));
		dat[lb] = {rb, val};
		if (l) dat[ll] = {lr, lv};
		if (r) dat[rl] = {rr, rv};
	};
	LL val0 = 0;
	dF(i, n, 1) {
//		printf("i = %d\n", i);
		int lb = -c[i];
		int rb = -c[i] + g[i];
		lb = ((lb % t) + t) % t;
		rb = ((rb % t) + t) % t;
//		printf("[%d -- %d)\n", lb, rb);
		if (rb == 0 || (lb < rb && lb > 0))
			val0 = (val0 + sum(1, lb)) + lb;
		int ql = (rb + 1) % t;
		int qr = lb;
		int len = (qr - ql + t) % t + 1;
		LL s = 0;
		if (ql <= qr) {
			s = sum(ql, qr);
		} else {
			s += sum(ql, t - 1);
			s += sum(0, qr);
		}
//		printf("sum[%d, %d] = %lld\n", ql, qr, s);
		LL delta = s + len;
		if (ql <= qr) {
			chto(ql, qr, -1ll);
		} else {
			chto(ql, t - 1, -1ll);
			chto(0, qr, -1ll);
		}
		chto(rb, rb, sum(rb, rb) + delta);
//		{
//			LL s = val0;
//			printf("%lld, ", s);
//			F(i, 1, t - 1) {
//				s += sum(i, i);
//				printf("%lld, ", s);
//			}
//			puts("");
//		}
	}
//	printf("%lld, ", val0);
//	F(i, 1, t - 1) {
//		val0 += sum(i, i);
//		printf("%lld, ", val0);
//	}
//	puts("");
	LL ans = val0, s = val0;
	int pos = 0;
	for (const auto &[lb, se] : dat) {
		const auto [rb, val] = se;
		s += val * (rb - pos);
		ans = std::min(ans, s);
		pos = rb;
	}
	printf("%lld\n", sumd + ans);
}