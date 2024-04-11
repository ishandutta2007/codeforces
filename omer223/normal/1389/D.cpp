#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
ll k;

inline bool intersect(int a, int b, int c, int d) {
	return !(b < c || d < a);
}

inline ll intersectionArea(int a, int b, int c, int d) {
	if (!intersect(a, b, c, d))return 0;
	return min(b, d) - max(a, c);
}

inline ll remainArea(int a, int b, int c, int d) {
	return b - a + d - c - 2*intersectionArea(a, b, c, d);
}

inline pll distCalc(int a, int b, int c, int d) {
	if (b < c) return { c - b,d - a };
	else return { a - d,b - c };
}

void solve() {
	scanf("%d %lld", &n, &k);
	int l1, r1, l2, r2;
	scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
	if (intersect(l1, r1, l2, r2)) {
		ll totalready = intersectionArea(l1, r1, l2, r2)*n;
		if (totalready >= k)printf("0\n");
		else {
			k -= totalready;
			ll area = remainArea(l1, r1, l2, r2);
			if (area*n >= k)printf("%lld\n", k);
			else printf("%lld\n", 2 * (k - area * n) + area * n);
		}
	}
	else {
		ll bstCost = 1e15;
		pll x = distCalc(l1, r1, l2, r2);
		for (int i = 1; i <= n; i++) {
			ll tmp = 0, rem = k;
			if (x.second*i >= k) {
				tmp = x.first*i + k;
				bstCost = min(bstCost, tmp);
				break;
			}
			else {
				tmp += (x.first + x.second)*i;
				rem -= x.second*i;
				tmp += 2 * rem;
				bstCost = min(bstCost, tmp);
			}
		}
		printf("%lld\n", bstCost);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)solve();
	return 0;
}