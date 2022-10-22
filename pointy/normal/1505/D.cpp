#include<bits/stdc++.h>
using namespace std;
int x,y;
int used[100];
int main()
{
	cin >> x >> y;
	while (x)
	{
		int u=x%y;
		if (used[u])
		{
			puts("NO");
			return 0;
		}
		used[u]=1;
		x/=y;
	}
	puts("YES");
	return 0;
}