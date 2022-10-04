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
	int l, r;
	F(i,1,n) scanf("%d%d", &l, &r), printf("%d %d\n", l, l * 2);
	return 0;
}