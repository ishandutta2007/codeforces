#include<bits/stdc++.h>
using namespace std;
long long n;
int len,q;
int main()
{
	scanf("%lld%d",&n,&q);
	for(len=1;(1ll<<(len+1))-1<n;len++);
	//printf("%d\n",len);
	for(int i=1;i<=q;i++)
	{
		long long x;
		scanf("%lld",&x);
		if(x&1)printf("%lld\n",x/2+1);
		else
		{
			x=n+x/2;
			int tlen=len;
			long long l=2*(n-(1ll<<len)+1),r=l+(1ll<<tlen)-1;
			for(;x&1^1;)
			{
				x=(x-l)/2+r;
				l=r+1;r=l+(1ll<<(--tlen))-1;
			}
			printf("%lld\n",x/2+1);
		}
	}
	return 0;
}