#include <bits/stdc++.h>

using namespace std;

long long n[2],m,a[2][200069],fq[2][200069];
map<pair<long long,long long>,long long> fq2[2];

int main()
{
	long long t,rr,i,ii,y,x,z,p[2],e;
	bool bad[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",n,n+1,&m);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n[ii];i++)
			{
				scanf("%lld",&a[ii][i]);
				fq[ii][i]=0;
			}
			fq2[ii].clear();
		}
		z=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&y,&x);
			for(ii=0;ii<2;ii++)
			{
				p[ii]=lower_bound(a[ii]+1,a[ii]+n[ii]+1,y)-a[ii];
				bad[ii]=a[ii][p[ii]]==y;
				swap(y,x);
			}
			e=!bad[1];
			if(!bad[e])
			{
				z+=fq[e][p[e]]-fq2[e][{p[e],p[!e]}];
				fq[e][p[e]]++;
				fq2[e][{p[e],p[!e]}]++;
			}
		}
		printf("%lld\n",z);
	}
}