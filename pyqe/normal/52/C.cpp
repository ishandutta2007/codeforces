#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],lh,rh,w,sg[524288],lz[524288];

long long md(long long l,long long r)
{
	return (l+r)/2;
}

long long bd(long long l,long long r,long long p)
{
	if(l==r)
	{
		sg[p]=a[l];
	}
	else
	{
		sg[p]=min(bd(l,md(l,r),p*2),bd(md(l,r)+1,r,p*2+1));
	}
	return sg[p];
}

void ud(long long l,long long r,long long p,long long ls)
{
	sg[p]+=ls;
	ls+=lz[p];
	lz[p]=0;
	if(l>rh||r<lh)
	{
		lz[p]+=ls;
	}
	else if(l>=lh&&r<=rh)
	{
		sg[p]+=w;
		lz[p]+=w+ls;
	}
	else
	{
		ud(l,md(l,r),p*2,ls);
		ud(md(l,r)+1,r,p*2+1,ls);
		sg[p]=min(sg[p*2],sg[p*2+1]);
	}
}

long long sm(long long l,long long r,long long p,long long ls)
{
	sg[p]+=ls;
	ls+=lz[p];
	lz[p]=0;
	if(l>rh||r<lh)
	{
		lz[p]+=ls;
		return 1e16;
	}
	else if(l>=lh&&r<=rh)
	{
		lz[p]+=ls;
		return sg[p];
	}
	else
	{
		return min(sm(l,md(l,r),p*2,ls),sm(md(l,r)+1,r,p*2+1,ls));
	}
}

int main()
{
	long long i,t,rr,k,z;
	string s,tmp;
	stringstream ss,ss2;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	bd(0,n-1,1);
	scanf("%lld",&t);
	getline(cin,s);
	for(rr=0;rr<t;rr++)
	{
		getline(cin,s);
		ss.clear();
		ss<<s;
		ss>>tmp;
		ss2.clear();
		ss2<<tmp;
		ss2>>lh;
		ss>>tmp;
		ss2.clear();
		ss2<<tmp;
		ss2>>rh;
		if(ss>>tmp)
		{
			ss2.clear();
			ss2<<tmp;
			ss2>>w;
			if(lh<=rh)
			{
				ud(0,n-1,1,0);
			}
			else
			{
				k=rh;
				rh=n-1;
				ud(0,n-1,1,0);
				lh=0;
				rh=k;
				ud(0,n-1,1,0);
			}
		}
		else
		{
			if(lh<=rh)
			{
				printf("%lld\n",sm(0,n-1,1,0));
			}
			else
			{
				k=rh;
				rh=n-1;
				z=sm(0,n-1,1,0);
				lh=0;
				rh=k;
				z=min(z,sm(0,n-1,1,0));
				printf("%lld\n",z);
			}
		}
	}
}