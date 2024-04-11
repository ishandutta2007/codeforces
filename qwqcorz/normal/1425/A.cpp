#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int solve(int n)
{
	if (n==4) return 3;
	if (n==2) return 1;
	if (!n) return 0;
	int ret=0;
	if ((n/2)%2==0) ret=1,n-=2;
	return n/2+solve(n/2-1)+ret;
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read();
		print(n%2==0?solve(n):n-solve(n-1));
	}
	
	return 0;
}