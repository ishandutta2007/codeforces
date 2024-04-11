#pragma warning(disable:4996)
#include <stdio.h>
#include <utility>
#define mp make_pair
using namespace std;
int n;
typedef pair<int, int> pii;
int& FI(pii& x) { return x.first; }
int& SC(pii& x) { return x.second; }
int query(const pii& a, const pii& b) {
	printf("? %d %d %d %d\n", a.first, a.second, b.first, b.second);
	int ret; scanf("%d", &ret); return ret;
}
template<typename A>
void bins(pii& a, pii& b, A FI, A SC) {
	int low = SC(a); int high = SC(b); int ret;
	while (low^high) {
		int mid = SC(b) = (low + high) / 2;
		ret = query(a, b);
		if (ret >= 1) high = mid;
		else low = mid + 1;
	}
	SC(b) = high;
	low = SC(a);
	while (low^high) {
		int mid = SC(a) = (low + high + 1) / 2;
		ret = query(a, b);
		if (ret >= 1) low = mid;
		else high = mid - 1;
	}
	SC(a) = high;
}
void find_one(pii& a, pii& b) {
	bins(a, b, FI, SC);
	bins(a, b, SC, FI);
}
int main() {
	setbuf(stdout, NULL);
	int n; scanf("%d", &n);
	pii a, b;
	a = mp(1, 1); b = mp(n, n);
	find_one(a, b);
	pii x, y;
	if (FI(a)>1 && query(mp(1, 1), mp(FI(a) - 1, n))) x = mp(1, 1), y = mp(FI(a) - 1, n);
	else if (SC(a)>1 && query(mp(1, 1), mp(n, SC(a) - 1))) x = mp(1, 1), y = mp(n, SC(a) - 1);
	else if (FI(b) < n && query(mp(FI(b) + 1, 1), mp(n, n))) x = mp(FI(b) + 1, 1), y = mp(n, n);
	else if (SC(b) < n && query(mp(1, SC(b)+1), mp(n, n))) x = mp(1, SC(b)+1), y = mp(n, n);
	find_one(x, y);
	printf("! %d %d %d %d %d %d %d %d\n", FI(a), SC(a), FI(b), SC(b), FI(x), SC(x), FI(y), SC(y));
	//while (1);
	return 0;
}