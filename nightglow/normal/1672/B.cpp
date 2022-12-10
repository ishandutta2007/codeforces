#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

char c[N];

void Main()
{
	scanf("%s", c); 
	int n = strlen(c); int cnt = 0, flag = 0;	
	for (int i = 0; i < n; ++i)
	{
		if (c[i] == 'A') ++cnt;
		else --cnt;
		if (cnt < 0)
		{
			puts("NO");
			return; 
		}
		if (c[i] == 'B') flag = 1;
	}
	if (c[n - 1] == 'B')
	puts("YES");
	else puts("NO");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (;T--;) Main();
}