#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#define mp(a,b) make_pair((a),(b))
#define nextInt(n) scanf("%d",&(n))
#define F(i,n) for(int (i) = 0; (i) < n; (i)++)

using namespace std;

long long threeh(int x) {
	return (long long)(x + 1)*(x + 2) / 2;
}

long long solve(int a, int b, int c, int s) {
	int t = c - a - b;
	int lb = max(s - t, 0);
	lb = (lb + 1) / 2;
	s -= lb;
	if (s < 0) return 0;
	return threeh(s);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, l;
	nextInt(a);
	nextInt(b);
	nextInt(c);
	nextInt(l);
	long long tot = 0;
	for (int s = 0; s <= l; s++) {
		long long ans = (long long)(s + 2)*(s + 1) / 2;
		ans -= solve(a, b, c, s);
		swap(b, c);
		swap(a, b);

		ans -= solve(a, b, c, s);
		swap(b, c);
		swap(a, b);

		ans -= solve(a, b, c, s);
		swap(b, c);
		swap(a, b);

		tot += ans;
	}
	printf("%I64d", tot);

	return 0;
}