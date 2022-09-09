#include <cstdio>
#include <algorithm>
#include <set>

typedef long long ll;

ll b, c;

ll getCost(ll from, ll to) {
	ll diff = to - from;
	return diff / 5 * b + diff % 5 * c;
}

int const N = 200200;
int const SHIFT = 1e9 + 100;
ll const INFL = 1e18;

ll t[N];
ll BIG;

int main() {
	int n, k;
	scanf("%d%d%I64d%I64d", &n, &k, &b, &c);
	b = std::min(b, 5 * c);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		t[i] = x + SHIFT;
	}
	std::sort(t, t + n);
	ll ans = INFL;
	for (int rem = 0; rem < 5; ++rem) {
		BIG = SHIFT * 2 + rem;
		struct Comp {
			bool operator()(ll a, ll b) {
				ll ca = getCost(a, BIG);
				ll cb = getCost(b, BIG);
				if (ca != cb) return ca > cb;
				return a < b;
			}
		};
		std::multiset<ll, Comp> values;
		ll sumCost = 0;
		int cur = -1;
		while (cur < k - 1) {
			++cur;
			sumCost += getCost(t[cur], BIG);
			values.insert(t[cur]);
		}
		while (true) {
			ll realCost = sumCost - (ll) (BIG - t[cur]) / 5 * b * k;
			ans = std::min(ans, realCost);
			if (cur + 1 < n) {
				++cur;
				ll head = *values.begin();
				ll newSumCost = sumCost + getCost(t[cur], BIG) - getCost(head, BIG);
				if (newSumCost < sumCost) {
					sumCost = newSumCost;
					values.erase(values.begin());
					values.insert(t[cur]);
				}
			} else {
				break;
			}
		}
	}
	printf("%I64d\n", ans);
}