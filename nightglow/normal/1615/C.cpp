#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int Zero[2][2], n;

char c[N], s[N];

void Main()
{
	scanf("%d", &n);
	scanf("%s", c);
	scanf("%s", s);
	memset(Zero, 0, sizeof(Zero));
	for (int i = 0; i < n; ++i) if (c[i] == s[i]) Zero[0][c[i] - '0']++; else Zero[1][c[i] - '0']++;
	int ans = n + 1;
	if (Zero[0][1] == Zero[0][0] + 1) ans = min(ans, Zero[0][1] + Zero[0][0]);
	if (Zero[1][1] == Zero[1][0]) ans = min(ans, Zero[1][1] + Zero[1][0]);	
	if (ans == n + 1) puts("-1");
	else printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (;T--;) Main();
}