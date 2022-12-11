#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

void Main()
{
	int n, x, s = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		(s += x) %= n; 
	}
	printf("%d\n", s > 0);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (;T--;) Main();
}