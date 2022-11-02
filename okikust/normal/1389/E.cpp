#pragma GCC optimize("O3")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000

long long gcd(long long x, long long y) {
	if (x > y)swap(x, y);
	if (x == 0)return y;
	if (y%x == 0)return x;
	return gcd(y%x, x);
}


int main() {
	long long n, k, t;
	long long m, d, w, g;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%lld", &t);
	f(tt, t) {
		scanf("%lld %lld %lld", &m, &d, &w);
		if ((m == 1) || (d == 1)) {
			printf("0\n");
			continue;
		}
		g = gcd(d - 1, w);
		k = w / g;
		x = min(m, d);
		y = x % k;
		x = x / k;
		s = (x + 1)*x;
		s /= 2;
		ans = s * y;
		s = x * (x - 1);
		s /= 2;
		ans += (s*(k - y));
		printf("%lld\n", ans);
	}

	return 0;
}