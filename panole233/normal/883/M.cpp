#if (__APPLE__)
#include "/Users/zhaofuqing/c++_head/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define x1 eorigoeoigjds
#define y1 hdovjsjdiovssda
#define x2 sdhvvkdjhjkvlshhv
#define y2 kjlvhsjdvklhdhkhv
#define N (1000010)
#define INF (2100000000)
using namespace std;
typedef long long ll;
int x1, x2, y1, y2;
int main() {
	#if (ONLINE_JUDGE) 
	#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int p = 0;
	if (x1 == x2 || y1 == y2) p = 3; else p = 2;
	printf("%d\n", ((int)fabs(x1 - x2) + (int)fabs(y1 - y2) + p) * 2);
	return 0;
}