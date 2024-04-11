#include <bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

typedef long long LL;
const int MN = 300005;
const int INF = 0x3f3f3f3f;

int n, m, q, k;
int a[MN], b[MN];
int f[MN], g[MN];

int main() {
	scanf("%d", &n);
	int x;
	F(i,1,n) {
		scanf("%d", &x);
		F(j,3,360) if (j*x%180==0 && j*x/180 < j-1) {printf("%d\n", j); break;}
	}
	return 0;
}