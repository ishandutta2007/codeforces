#include <bits/stdc++.h>

using namespace std;

long long n,ps[300069],zs;
bitset<300069> a;
vector<long long> vl[2][600069];

int main()
{
	long long tt,rrr,t,rr,i,ii,u,k,l,w,e,z[2];
	char ch;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		for(ii=0;ii<2;ii++)
		{
			for(i=-n;i<=n;i++)
			{
				vl[ii][n+i].clear();
			}
		}
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch=='+'^i%2==0;
			ps[i]=ps[i-1]+a[i]*2-1;
			vl[a[i]][n+ps[i]].push_back(i);
		}
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld%lld",&k,&l);
			for(ii=0;ii<2;ii++)
			{
				z[ii]=0;
			}
			zs=0;
			if(ps[l]!=ps[k-1])
			{
				if(l%2!=k%2)
				{
					z[1]=l;
					l--;
					zs++;
				}
				w=ps[l]-ps[k-1];
				e=w<0;
				w=abs(w);
				u=!e*2-1;
				z[0]=*lower_bound(vl[!e][n+ps[k-1]+(w/2+1)*u].begin(),vl[!e][n+ps[k-1]+(w/2+1)*u].end(),k);
				zs++;
			}
			printf("%lld\n",zs);
		}
	}
}