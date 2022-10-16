#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069],zs;
bitset<100069> kd,a;
bitset<4> ca;

inline long long qr(long long x,long long x2,long long x3)
{
	long long k;
	
	printf("? %lld %lld %lld\n",x,x2,x3);
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

int main()
{
	long long t,rr,i,ii,k,p[2],p2[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n/3;i++)
		{
			kd[i]=qr(i*3-2,i*3-1,i*3);
			p[kd[i]]=i;
		}
		ca[0]=0;
		ca[1]=qr(p[0]*3-1,p[0]*3,p[1]*3-2);
		ca[2]=qr(p[0]*3,p[1]*3-2,p[1]*3-1);
		ca[3]=1;
		for(i=1;i<=3;i++)
		{
			if(!ca[i-1]&&ca[i])
			{
				for(ii=0;ii<2;ii++)
				{
					p2[ii]=(p[ii]-1)*3+i;
					a[p2[ii]]=ii;
				}
				break;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=3;i++)
			{
				k=(p[ii]-1)*3+i;
				if(k!=p2[ii])
				{
					a[k]=qr(p2[0],p2[1],k);
				}
			}
		}
		for(i=1;i<=n/3;i++)
		{
			if(i!=p[0]&&i!=p[1])
			{
				if(qr(p2[!kd[i]],i*3-2,i*3-1)==kd[i])
				{
					a[i*3-2]=kd[i];
					a[i*3-1]=kd[i];
					a[i*3]=qr(p2[0],p2[1],i*3);
				}
				else
				{
					a[i*3-2]=qr(p2[0],p2[1],i*3-2);
					a[i*3-1]=!a[i*3-2];
					a[i*3]=kd[i];
				}
			}
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(!a[i])
			{
				zs++;
				sq[zs]=i;
			}
		}
		printf("! %lld",zs);
		for(i=1;i<=zs;i++)
		{
			printf(" %lld",sq[i]);
		}
		printf("\n");
		fflush(stdout);
	}
}