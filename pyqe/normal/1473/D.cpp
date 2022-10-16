#include <bits/stdc++.h>

using namespace std;

long long n,ps[200069],pn[200069],px[200069],sn[200069],sx[200069];
bitset<200069> a;

int main()
{
	long long tt,rrr,t,rr,i,u,k,l;
	char ch;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch=='+';
			u=(long long)a[i]*2-1;
			ps[i]=ps[i-1]+u;
			pn[i]=min(pn[i-1],ps[i]);
			px[i]=max(px[i-1],ps[i]);
		}
		sn[n+1]=0;
		sx[n+1]=0;
		for(i=n;i;i--)
		{
			u=(long long)a[i]*2-1;
			sn[i]=min(sn[i+1]+u,0ll);
			sx[i]=max(sx[i+1]+u,0ll);
		}
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld%lld",&k,&l);
			printf("%lld\n",max(px[k-1],ps[k-1]+sx[l+1])-min(pn[k-1],ps[k-1]+sn[l+1])+1);
		}
	}
}