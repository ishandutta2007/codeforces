#include <bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

typedef long long LL;
const int MN = 300005;
const int INF = 0x3f3f3f3f;

int n, m, q, k;
int a[MN], b[MN];
int f[MN], g[MN];
char str[MN];

int main() {
	scanf("%d%s", &n, str + 1);
	int c1 = 0, c2 = 0;
	for (int i = 1; i <= n; ++i)
		if (str[i] == str[1]) ++c1;
		else break;
	for (int i = n; i >= 1; --i)
		if (str[i] == str[n]) ++c2;
		else break;
	if (str[1] == str[n]) printf("%d\n", (c1 + 1ll) * (c2 + 1ll) % 998244353);
	else printf("%d\n", (c1 + c2 + 1) % 998244353);
	return 0;
}