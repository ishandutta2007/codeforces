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
#define N 400000


int main() {
	long long a[N];
	long long b[N];
	long long c[N];
	long long d[N];
	bool used[N];
	vector<long long>e;
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
		d[i] = 0;
		used[i] = false;
	}
	long long n, k, ans;
	scanf("%lld", &n);
	f(i, n) {
		scanf("%lld", &a[i]);
	}
	f(i, n) {
		scanf("%lld", &b[i]);
		b[i]--;
		if (b[i] >= 0)c[b[i]]++;
	}
	ans = 0;
	k = 0;
	f(i, n) {
		if (c[i] == 0) {
			d[k] = i;
			k++;
		}
	}
	f(i, n) {
		ans += a[d[i]];
		if (b[d[i]] >= 0) {
			if (a[d[i]] > 0) {
				used[d[i]] = true;
				e.push_back(d[i]+1);
				a[b[d[i]]] += a[d[i]];
			}
			c[b[d[i]]]--;
			if (c[b[d[i]]] == 0) {
				d[k] = b[d[i]];
				k++;
			}
		}

	}
	for (int i = n - 1; i >= 0; i--) {
		if (!used[d[i]])e.push_back(d[i]+1);
	}
	printf("%lld\n", ans);
	f(i, n - 1)printf("%lld ", e[i]);
	printf("%lld\n", e[n - 1]);
	return 0;
}