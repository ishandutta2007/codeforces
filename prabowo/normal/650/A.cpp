#include <cstdio>
#include <algorithm>
#include <utility>

const int N = 200000;

int n;
std :: pair <int, int> p[N];

int main () {
	scanf ("%d", &n);
	for (int i=0; i<n; i++) 
		scanf ("%d %d", &p[i].first, &p[i].second);
	
	std::sort (p, p + n);
	
	long long ans = 0;
	for (int i=0, nxt; i<n; i=nxt) {
		nxt = lower_bound (p + i, p + n, std::make_pair (p[i].first, 2000000000)) - p;		
		ans += (long long) (nxt - i) * (nxt - i - 1) >> 1;
	}
	
	for (int i=0; i<n; i++) std::swap (p[i].first, p[i].second);
		
	std::sort (p, p + n);
	
	for (int i=0, nxt; i<n; i=nxt) {
		nxt = lower_bound (p + i, p + n, std::make_pair (p[i].first, 2000000000)) - p;
		ans += (long long) (nxt - i) * (nxt - i - 1) >> 1;
	}
	
	for (int i=0, nxt; i<n; i=nxt) {
		nxt = upper_bound (p + i, p + n, p[i]) - p;
		ans -= (long long) (nxt - i) * (nxt - i - 1) >> 1;
	}
	
	printf ("%I64d\n", ans);
	
	return 0;
}