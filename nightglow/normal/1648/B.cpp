#include <bits/stdc++.h>

#define N 2000005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int vis[N], n, C, s[N], t;

void Main()
{
	scanf("%d%d", &n, &C);
	for (int i = 1; i <= 2 * C; ++i) vis[i] = s[i] = 0; 
	for (;n--;)
	{
		int x; scanf("%d", &x);
		vis[x]++; 
	} 
	for (int i = 1; i <= 2 * C; ++i) s[i] = s[i - 1] + vis[i]; 
	for (int i = 1; i <= C; ++i)
		if (vis[i])
		{
			for (int j = i; j <= C; j += i) 
				if (s[j + i - 1] - s[j - 1] > 0) 
				if (!vis[j / i]) 
				{ 
					puts("No"); return; 
				}
		}
	puts("Yes"); 
}

int main()
{
	scanf("%d", &t);
	for (;t--;) Main();
}