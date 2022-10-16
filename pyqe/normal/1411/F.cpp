#include <bits/stdc++.h>

using namespace std;

long long n,wg[7][3]={{0,3,0},{0,1,1},{0,0,3},{0,2,0},{0,0,1},{0,1,0},{0,0,2}},ky[7]={0,0,0,2,2,1,1},pr[1000069],fqq[3],fq[3],rmm[3],rm[3],pm[5],dv=1e9+7,inf=1e18;
bitset<1000069> vtd;

int main()
{
	long long t,rr,i,j,ii,k,w,c,mn,z;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",pr+i);
			vtd[i]=0;
		}
		z=1;
		c=0;
		for(i=0;i<3;i++)
		{
			fqq[i]=0;
			rmm[i]=0;
		}
		for(k=n;k%3;k-=2,z=z*2%dv,c++,rmm[2]++);
		for(;k;k-=3,z=z*3%dv,c++,rmm[0]++);
		bad=1;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				c++;
				w=0;
				for(k=i;!vtd[k];k=pr[k])
				{
					vtd[k]=1;
					w++;
				}
				fqq[w%3]++;
				bad&=!(w%3==1&&w>=4);
			}
		}
		c-=fqq[0]*2;
		fqq[0]=0;
		mn=inf;
		for(ii=0;ii<=(n%3==1);ii++)
		{
			if(ii)
			{
				c--;
				rmm[2]-=2;
				rmm[1]++;
			}
			for(i=0;i<5;i++)
			{
				pm[i]=i+2ll*(i>=3&&ii);
			}
			for(;1;)
			{
				for(i=0;i<3;i++)
				{
					fq[i]=fqq[i];
					rm[i]=rmm[i];
				}
				w=0;
				for(i=0;i<5;i++)
				{
					k=rm[ky[pm[i]]];
					for(j=0;j<3;j++)
					{
						if(wg[pm[i]][j])
						{
							k=min(k,fq[j]/wg[pm[i]][j]);
						}
					}
					w+=k*(pm[i]!=5||!bad);
					rm[ky[pm[i]]]-=k;
					for(j=0;j<3;j++)
					{
						fq[j]-=k*wg[pm[i]][j];
					}
				}
				mn=min(mn,c-w*2);
				if(!next_permutation(pm,pm+5))
				{
					break;
				}
			}
		}
		printf("%lld %lld\n",z,mn);
	}
}