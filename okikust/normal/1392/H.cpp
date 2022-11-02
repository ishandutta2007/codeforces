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
#define MOD 998244353
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 2100000
long long r[N];
bool a[30];

int main() {
	long long n, m;
	long long x, y, z;
	long long s, ans;
	x = MOD - 2;
	f(i, 30) {
		if (x % 2 == 1)a[i] = true;
		else a[i] = false;
		x /= 2;
	}
	f(i, N) {
		x = 1;
		y = i;
		f(j, 30) {
			if (a[j])x = (x*y) % MOD;
			y = (y*y) % MOD;
		}
		r[i] = x;
	}

	scanf("%lld %lld", &n, &m);
	ans = 0;
	for (long long i = 1; i <= n; i++) {
		x = (m*r[i]) % MOD;
		ans = (ans + x) % MOD;
	}
	ans = (ans + 1) % MOD;
	s = (n*r[m + 1]) % MOD;
	s = (s + 1) % MOD;
	ans = (ans*s) % MOD;
	printf("%lld\n", ans);

	return 0;
}