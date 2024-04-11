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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main() {
	int n, t, ans;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		ans = (n + 2) / 2;
		printf("%d\n", ans);
	}

	return 0;
}