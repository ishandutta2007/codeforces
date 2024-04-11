#include <bits/stdc++.h>

using namespace std;

long long n,m,nn[2],nk,a[300069],as[2][300069],sk[300069],sq[300069];
bitset<300069> kd;

bool cmp(long long x,long long y)
{
	return a[x]<a[y];
}

int main()
{
	long long t,rr,i,ii,k,e,p,p2;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			e=a[i]%2;
			nn[e]++;
			as[e][nn[e]]=i;
			sq[i]=-1;
		}
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			kd[i]=ch=='L';
		}
		for(ii=0;ii<2;ii++)
		{
			sort(as[ii]+1,as[ii]+nn[ii]+1,cmp);
			nk=0;
			for(i=1;i<=nn[ii];i++)
			{
				k=as[ii][i];
				if(kd[k]&&nk&&!kd[sk[nk]])
				{
					sq[k]=(a[k]-a[sk[nk]])/2;
					sq[sk[nk]]=sq[k];
					nk--;
				}
				else
				{
					nk++;
					sk[nk]=k;
				}
			}
			for(i=1;i+1<=nk&&kd[sk[i+1]];i+=2)
			{
				sq[sk[i]]=(a[sk[i]]+a[sk[i+1]])/2;
				sq[sk[i+1]]=sq[sk[i]];
			}
			p=-1;
			if(i<=nk&&kd[sk[i]])
			{
				p=i;
			}
			for(i=nk;i-1>0&&!kd[sk[i-1]];i-=2)
			{
				sq[sk[i]]=(m*2-a[sk[i]]-a[sk[i-1]])/2;
				sq[sk[i-1]]=sq[sk[i]];
			}
			p2=-1;
			if(i>0&&!kd[sk[i]])
			{
				p2=i;
			}
			if(p+1&&p2+1)
			{
				sq[sk[p]]=(m*2+a[sk[p]]-a[sk[p2]])/2;
				sq[sk[p2]]=sq[sk[p]];
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}