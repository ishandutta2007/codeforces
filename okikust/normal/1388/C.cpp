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

long long h[N];
long long a[N];
vector<long long>e[N];
bool used[N];
bool v;

long long dfs(long long k) {
	used[k] = true;
	long long re = 0;
	long long s = 0;
	long long sz = e[k].size();
	f(i, sz) {
		if (!used[e[k][i]]) {
			re += dfs(e[k][i]);
			s += h[e[k][i]];
		}
	}
	re += a[k];
    s-=a[k];
	if (s > h[k])v = false;
	else if (re < h[k])v = false;
	else if ((re - h[k]) % 2 != 0)v = false;
	return re;
}


int main() {

	f(i, N) {
		a[i] = 0;
		h[i] = 0;
	}
	long long n, m,k, t;
	long long x, y, z;
	long long s, ans;
	ans = 0;
	scanf("%lld", &t);
	f(tt, t) {
		scanf("%lld %lld", &n, &m);
		f(i, n) {
			scanf("%lld", &a[i]);
		}
		f(i, n) {
			scanf("%lld", &h[i]);
		}
		f(i, n-1) {
			scanf("%lld %lld", &x, &y);
			x--;
			y--;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		v = true;
		f(i, n)used[i] = false;
		dfs(0);
		if (v)printf("YES\n");
		else printf("NO\n");
		f(i, n)e[i].clear();
	}

	return 0;
}