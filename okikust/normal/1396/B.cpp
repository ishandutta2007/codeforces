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
	int n, m, s, t, x;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		s = 0;
		m = 0;
		f(i, n) {
			scanf("%d", &x);
			s += x;
			m = max(m, x);
		}
		if ((2 * m) > s) {
			printf("T\n");
		}
		else if (s % 2 == 1) {
			printf("T\n");
		}
		else {
			printf("HL\n");
		}
	}

	return 0;
}