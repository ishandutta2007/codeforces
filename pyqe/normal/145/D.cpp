#include <bits/stdc++.h>

using namespace std;

long long on,n=0,a[1069],ds[1069],ps[1069];
vector<long long> vl[1069];
multiset<long long> ms;
multiset<long long>::iterator it;
bitset<1069> vtd;

long long lky(long long x)
{
	long long c=0,z=0;
	
	for(c=0;x;x/=10,c++)
	{
		if(x%10!=4&&x%10!=7)
		{
			return -1;
		}
		z=z*2+(x%10==7);
	}
	z+=(1ll<<c)-1;
	return z;
}

int main()
{
	long long i,j,r,k,l,w,sz,gd,sm,sm2,z=0;
	
	scanf("%lld",&on);
	for(i=0;i<on;i++)
	{
		scanf("%lld",&k);
		k=lky(k);
		ds[n+1]++;
		ps[n+1]++;
		if(k!=-1)
		{
			n++;
			a[n]=k;
			ps[n+1]=ps[n];
			vl[k].push_back(n);
		}
	}
	ds[n+1]++;
	ps[n+1]++;
	sm=0;
	for(i=1;i<=n+1;i++)
	{
		w=ds[i]*(ds[i]-1)/2;
		z+=sm*w;
		sm+=w;
		w=1;
		k=24;
		for(j=1;j>=-2;j--)
		{
			w*=ds[i]+j;
			gd=__gcd(w,k);
			w/=gd;
			k/=gd;
		}
		z+=w;
	}
	for(i=1;i<=n;i++)
	{
		sm=ps[n+1]*max(ps[n]-ps[i+1],0ll);
		for(j=i+2;j<=n;j++)
		{
			sm-=ps[j]*ds[j];
		}
		ms.clear();
		ms.insert(i+1);
		ms.insert(n+1);
		vtd.reset();
		sm2=0;
		for(j=1;j<=n+1;j++)
		{
			sm2+=ds[j]*(ds[j]-1)/2*(j!=i+1);
		}
		for(j=i;j;j--)
		{
			if(!vtd[a[j]])
			{
				sz=vl[a[j]].size();
				for(r=0;r<sz;r++)
				{
					l=vl[a[j]][r];
					if(l>=i+1)
					{
						it=ms.upper_bound(l);
						k=*it;
						it--;
						sm-=(ps[k]-ps[l])*(ps[l]-ps[*it]);
						ms.insert(l);
					}
				}
				vtd[a[j]]=1;
			}
			z+=sm*ds[j]*ds[i+1];
			it=ms.begin();
			it++;
			z+=(ps[*it]-ps[i+1])*ds[j]*(ds[i+1]*(ds[i+1]+1)/2);
			sm2-=ds[j]*(ds[j]-1)/2;
			z+=sm2*ds[j]*ds[i+1]+(ds[j]+1)*ds[j]*(ds[j]-1)/6*ds[i+1]+(ds[i+1]+1)*ds[i+1]*(ds[i+1]-1)/6*ds[j];
		}
	}
	printf("%lld\n",z);
}