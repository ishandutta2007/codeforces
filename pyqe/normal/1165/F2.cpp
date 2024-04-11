#include <bits/stdc++.h>

using namespace std;

long long a[200069],d[200069],sz,aa[200069];
bool g;
vector<pair<long long,long long>> v;
pair<long long,long long> sl[200069];

int main()
{
	long long n,m,i,k,l,w,c,z=0,zzz,lh,rh,md,bbb=-1,zz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		z+=a[i];
		aa[i]=a[i];
	}
	zz=z;
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		sl[i]=make_pair(k,l);
	}
	sort(sl,sl+m);
	lh=0;
	rh=m;
	while(lh<=rh)
	{
		md=(lh+rh)/2;
		//cout<<md<<endl;
		z=zz;
		for(i=1;i<=n;i++)
		{
			d[i]=0;
			a[i]=aa[i];
		}
		for(i=0;i<md;i++)
		{
			d[sl[i].second]=max(d[sl[i].second],sl[i].first);
		}
		v.clear();
		v.push_back(make_pair(0,0));
		sz=1;
		for(i=1;i<=n;i++)
		{
			if(d[i]>0)
			{
				v.push_back(make_pair(d[i],i));
				//cout<<d[i]<<" "<<i<<endl;
				sz++;
			}
		}
		g=false;
		c=0;
		sort(v.begin(),v.end());
		for(i=1;i<sz;i++)
		{
			k=v[i].first;
			l=v[i].second;
			w=v[i-1].first;
			if(k-w>z*2-c)
			{
				zzz=z*2-c+w;
				g=true;
				break;
			}
			if(a[l]>=k-w+c)
			{
				z-=k-w+c;
				a[l]-=k-w+c;
				c=0;
			}
			else
			{
				c=k-w+c-a[l];
				z-=a[l];
				a[l]=0;
			}
		}
		if(g)
		{
			rh=md-1;
		}
		else
		{
			zzz=max(z*2-c,(long long)0)+v[sz-1].first;
			if(z*2-c<0)
			{
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		//cout<<"zzz = "<<zzz<<endl;
		if(bbb==-1||zzz<bbb)
		{
			bbb=zzz;
		}
	}
	printf("%lld\n",bbb);
}