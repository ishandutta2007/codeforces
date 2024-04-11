#include <bits/stdc++.h>
#define MAXN 250007
using namespace std;
long long MOD,fkt[MAXN];
int main()
{
	long long res=0;
	fkt[0]=1;
	long long n; scanf("%lld%lld",&n,&MOD);
	for(int i=1;i<MAXN;i++) fkt[i]=(fkt[i-1]*((long long)i))%MOD;
	for(int i=1;i<=n;i++)
	{
		long long t=i;
		res=(res+(((fkt[n+1-i]*(n+1-t))%MOD)*fkt[i])%MOD)%MOD;
	}
	printf("%lld",res);
}