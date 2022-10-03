#include <cstdio>
#include <algorithm>
#include <functional>
#include <set>

typedef long long LL;
typedef std::pair<int, int> pii;

std::multiset<pii> st1;
std::multiset<pii, std::greater<pii>> st2;
LL sum1, sum2;
int c, k;

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int t, d;
		scanf("%d%d", &t, &d);
		if (d < 0) {
			d = -d;
			if (!st1.empty() && *st1.begin() <= (pii){d, t}) st1.erase(st1.find({d, t})), c -= t, sum1 -= d;
			else st2.erase(st2.find({d, t})), sum2 -= d;
			k -= t;
		} else {
			if (!st2.empty() && *st2.begin() > (pii){d, t}) st2.insert({d, t}), sum2 += d;
			else st1.insert({d, t}), c += t, sum1 += d;
			k += t;
		}
		while ((int)st1.size() < k) {
			auto i = st2.begin();
			int v = i -> first;
			sum1 += v, sum2 -= v;
			c += i -> second;
			st1.insert(*i);
			st2.erase(i);
		}
		while ((int)st1.size() > k) {
			auto i = st1.begin();
			int v = i -> first;
			sum2 += v, sum1 -= v;
			c -= i -> second;
			st2.insert(*i);
			st1.erase(i);
		}
//		printf("st1 : ");
//		for (pii x : st1) printf("(%d, %d), ", x.second, x.first);
//		printf("sum1 = %lld\n", sum1);
//		printf("st2 : ");
//		for (pii x : st2) printf("(%d, %d), ", x.second, x.first);
//		printf("sum2 = %lld\n", sum2);
		if (k && c == k) printf("%lld\n", sum1 * 2 + sum2 - st1.begin() -> first + (st2.empty() ? 0 : st2.begin() -> first));
		else printf("%lld\n", sum1 * 2 + sum2);
	}
	return 0;
}