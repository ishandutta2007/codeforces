#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int n;
char c[N];

void Main()
{
	scanf("%s", c); n = strlen(c); 
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i) if (c[i] == 'N') ++cnt;
	if (c[n - 1] == 'E')
	{
		if (cnt != 1) puts("YES"); else puts("NO");
	}
	else if (c[n - 1] == 'N')
	{
		if (cnt > 0) puts("YES"); else puts("NO"); 
	}
}

int main()
{
	int T; scanf("%d", &T);
	for (;T--;) Main();
}