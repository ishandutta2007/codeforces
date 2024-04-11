#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,nn=0,sqn=100,ma=1e9,a[200069],fq[100069],ps[100069],cc[100069];
long long wg[10000069];
pair<int,int> as[200069];

int main()
{
	int t,rr,i,j,r,k,l,c,p;
	
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d",&n);
		nn=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",fq+i);
			ps[i]=ps[i-1]+fq[i];
			for(j=ps[i-1]+1;j<=ps[i];j++)
			{
				scanf("%d",a+j);
				a[j]--;
				as[j]={a[j],i};
			}
			sort(a+ps[i-1]+1,a+ps[i]+1);
			if(fq[i]<=sqn)
			{
				for(j=ps[i-1]+1;j<=ps[i];j++)
				{
					for(r=j+1;r<=ps[i];r++)
					{
						nn++;
						wg[nn]=(long long)a[j]*ma+a[r];
					}
				}
			}
		}
		sort(wg+1,wg+nn+1);
		sort(as+1,as+ps[n]+1);
		for(i=2;i<=nn;i++)
		{
			if(wg[i]==wg[i-1])
			{
				k=wg[i]/ma;
				l=wg[i]%ma;
				break;
			}
		}
		if(i<=nn)
		{
			p=0;
			for(i=1;i<=n;i++)
			{
				c=0;
				for(j=ps[i-1]+1;j<=ps[i];j++)
				{
					c+=a[j]==k||a[j]==l;
				}
				if(c==2)
				{
					if(!p)
					{
						p=i;
					}
					else
					{
						printf("%d %d\n",p,i);
						break;
					}
				}
			}
			continue;
		}
		for(i=1;i<=n&&i;i++)
		{
			if(fq[i]>sqn)
			{
				for(j=1;j<=n;j++)
				{
					cc[j]=0;
				}
				for(r=1,j=ps[i-1]+1;j<=ps[i];j++)
				{
					for(;r<=ps[n]&&as[r].fr<=a[j];r++)
					{
						cc[as[r].sc]+=as[r].fr==a[j];
					}
				}
				for(j=1;j<=n;j++)
				{
					if(j!=i&&cc[j]>=2)
					{
						printf("%d %d\n",i,j);
						i=-1;
						break;
					}
				}
			}
		}
		if(i)
		{
			printf("-1\n");
		}
	}
}