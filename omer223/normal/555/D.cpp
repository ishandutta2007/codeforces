#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (long long i = k; i < n; i++)
#define ford(i, k, n) for (long long i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pii;
typedef pair<ll, ll> pll;

const long long sz = 2e5 + 1;
pii x[sz];
long long xmap[sz];
long long n;

long long findRight(long long xi, long long len) {
	long long l = xi, r = n, mid, bst = -1;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (x[mid].first - x[xi].first <= len) {
			bst = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return bst;
}

long long findLeft(long long xi, long long len) {
	long long l = 1, r = xi, mid, bst = -1;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (x[xi].first - x[mid].first <= len) {
			bst = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return bst;
}

long long solve() {
	long long xi, len;
	scanf("%lld %lld", &xi, &len);
	xi = xmap[xi];
	len += (x[xi].first - x[1].first);
	xi = 1;
	long long nxt;
	bool isRight = 1;
	while (len) {
		nxt = (isRight ? findRight(xi, len) : findLeft(xi, len));
		if (nxt == xi)return x[xi].second;
		long long diff = abs(x[nxt].first - x[xi].first);
		long long changes = len / diff;
		if (changes & 1) {
			isRight = !isRight;
			xi = nxt;
		}
		len %= diff;
	}
	return x[xi].second;
}

int main() {
	//fast;
	long long q;
	scanf("%lld %lld", &n, &q);
	foru(i, 0, n) {
		scanf("%lld", &x[i + 1].first);
		x[i + 1].second = i + 1;
	}
	sort(x + 1, x + n + 1);
	for (long long i = 1; i <= n; i++) xmap[x[i].second] = i;
	while (q--)printf("%lld\n", solve());
	return 0;
}