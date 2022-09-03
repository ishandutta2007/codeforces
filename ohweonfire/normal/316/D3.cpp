#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
typedef long long LL;
const LL mod=1000000007;
LL power(LL x,LL y)
{
	LL res=1;
	while(y!=0)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
LL fn,f1,id[maxn],c1;
int n;
int main()
{
	scanf("%d",&n);
	id[0]=id[1]=1;
	fn=f1=1;
	for(int i=2;i<=n;i++)
		id[i]=(id[i-1]+(i-1)*id[i-2])%mod;
	for(int i=1,v;i<=n;i++)
	{
		scanf("%d",&v);
		fn=fn*i%mod;
		if(v==1)
		{
			++c1;
			f1=f1*c1%mod;
		}
	}
	printf("%I64d\n",fn*id[c1]%mod*power(f1,mod-2)%mod);
	return 0;
}