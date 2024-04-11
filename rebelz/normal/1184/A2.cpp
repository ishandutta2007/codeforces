#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
char a[maxn];
int fl[maxn];
int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a% b);
}
int main()
{
	int n;
	cin>>n;
	scanf("%s", a + 1);
	for(int j = 1; j <= n; j++)
		if(n % j) continue;
		else
		{
			fl[j] = 1;
			for(int i = 1; i <= j; i++)
			{
				int ns = 0;
				for(int k = i; k <= n; k += j)
					ns ^= (a[k] - '0');
				if(ns) fl[j] = 0;
			}
		}
	int ans = 0;
	for(int j = 1; j <= n; j++)
		if(fl[gcd(n, j)]) ans++;
	cout<<ans<<endl;
	return 0;
}