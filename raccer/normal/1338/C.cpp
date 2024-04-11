#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;


struct ppp {
	long long a, b, c;
	ppp() {}
	ppp(long long x, long long y, long long z) {a = x, b = y, c = z;}
};

const long long one = 1;

long long B[4] = {0, 2, 3, 1}, C[4] = {0, 3, 1, 2};

ppp solve(long long x) {
//	cout << "      solve:" << x << endl;
	if (x == 0) return ppp(0, 0, 0);
	if (x == 1) return ppp(1, 2, 3);
	long long tmp = 0;
	while (x >= (one << 2 * tmp)) tmp++;
	long long high = x >> 2 * tmp - 2 & 3;
	ppp res = solve(x - (high << 2 * tmp - 2));
	res.a += high << 2 * tmp - 2;
	res.b += B[high] << 2 * tmp - 2;
	res.c += C[high] << 2 * tmp - 2;
	return res;
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		long long x; scanf("%I64d", &x);
		long long r = x % 3;
		long long dep = 1;
		while (x > (one << 2 * dep - 2) * 3) x -= (one << 2 * dep - 2) * 3, dep++;
		ppp tmp = solve((one << 2 * dep - 2) + (x + 2) / 3 - 1);
//		printf("                               ans:");
		if (r == 1) printf("%I64d\n", tmp.a);
		else if (r == 2) printf("%I64d\n", tmp.b);
		else printf("%I64d\n", tmp.c);
	}
	return 0;
}