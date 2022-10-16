#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],fw[200069],fi;
multiset<long long> ms;

long long tri(long long x)
{
	return x*(x+1)/2;
}

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[fi];
	}
	return z;
}

void ins(long long x)
{
	long long k,l;
	multiset<long long>::iterator it=ms.lower_bound(x);
	
	if(it!=ms.begin()&&it!=ms.end())
	{
		k=*prev(it);
		l=*it;
		ud(k,-tri(l-k));
	}
	if(it!=ms.begin())
	{
		k=*prev(it);
		ud(k,tri(x-k));
	}
	if(it!=ms.end())
	{
		k=*it;
		ud(x,tri(k-x));
	}
	ms.insert(x);
}

void ers(long long x)
{
	long long k,l;
	multiset<long long>::iterator it;
	
	ms.erase(x);
	it=ms.lower_bound(x);
	if(it!=ms.begin()&&it!=ms.end())
	{
		k=*prev(it);
		l=*it;
		ud(k,tri(l-k));
	}
	if(it!=ms.begin())
	{
		k=*prev(it);
		ud(k,-tri(x-k));
	}
	if(it!=ms.end())
	{
		k=*it;
		ud(x,-tri(k-x));
	}
}

int main()
{
	long long t,rr,i,ii,ky,k,l,k2,l2;
	multiset<long long>::iterator it;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(i-1&&a[i-1]>a[i])
		{
			ins(i-1);
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			for(ii=0;ii<2;ii++)
			{
				if(k+ii-1&&k+ii<=n)
				{
					if(a[k+ii-1]>a[k+ii])
					{
						ers(k+ii-1);
					}
				}
			}
			a[k]=l;
			for(ii=0;ii<2;ii++)
			{
				if(k+ii-1&&k+ii<=n)
				{
					if(a[k+ii-1]>a[k+ii])
					{
						ins(k+ii-1);
					}
				}
			}
		}
		else
		{
			it=ms.lower_bound(k);
			if(it==ms.end()||*it>=l)
			{
				printf("%lld\n",tri(l-k+1));
				continue;
			}
			k2=*it;
			l2=*prev(ms.upper_bound(l-1));
			printf("%lld\n",tri(k2-k+1)+qr(k2,l2-1)+tri(l-l2));
		}
	}
}