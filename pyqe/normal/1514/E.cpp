#include <bits/stdc++.h>

using namespace std;

long long n,nn,as[169],tmp[169],fh[169],sk[169];
bitset<169> sq[169];

bool q1(long long x,long long y)
{
	long long k;
	
	printf("1 %lld %lld\n",x,y);
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

bool q2(long long x,vector<long long> v)
{
	long long i,k,sz=v.size();
	
	printf("2 %lld %lld",x,sz);
	for(i=0;i<sz;i++)
	{
		printf(" %lld",v[i]);
	}
	printf("\n");
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

void srt(long long lh,long long rh)
{
	if(lh<rh)
	{
		long long i,j,md=(lh+rh)/2,p=lh;
		
		srt(lh,md);
		srt(md+1,rh);
		for(j=md+1,i=lh;i<=md+1;i++)
		{
			for(;j<=rh&&(i==md+1||q1(as[j],as[i]));j++)
			{
				tmp[p]=as[j];
				p++;
			}
			if(i<=md)
			{
				tmp[p]=as[i];
				p++;
			}
		}
		for(i=lh;i<=rh;i++)
		{
			as[i]=tmp[i];
		}
	}
}

int main()
{
	long long t,rr,i,j,k;
	vector<long long> v;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			as[i]=i;
			fh[i]=i;
		}
		srt(0,n-1);
		nn=0;
		sk[0]=-1;
		for(i=0;i<n;i++)
		{
			for(;1;)
			{
				v.clear();
				for(j=0;j<=sk[nn];j++)
				{
					v.push_back(as[j]);
				}
				if(v.empty()||!q2(as[i],v))
				{
					break;
				}
				nn--;
			}
			fh[i]=sk[nn]+1;
			nn++;
			sk[nn]=i;
		}
		for(i=n-2;i+1;i--)
		{
			fh[i]=min(fh[i],fh[i+1]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				sq[as[i]][as[j]]=fh[i]<=fh[j];
			}
		}
		printf("3\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%lld",(long long)sq[i][j]);
			}
			printf("\n");
		}
		fflush(stdout);
		scanf("%lld",&k);
	}
}