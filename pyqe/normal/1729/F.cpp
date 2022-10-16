#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long d=9;
long long n,m,nn[d],a[200069],ps[200069],ex[d][2];

int main()
{
	long long tt,rrr,t,rr,i,k,l,w,e;
	string s;
	pair<long long,long long> z;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		cin>>s;
		n=s.length();
		scanf("%lld%lld",&m,&t);
		for(i=0;i<d;i++)
		{
			nn[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
			ps[i]=ps[i-1]+a[i];
			if(i>=m)
			{
				k=(ps[i]-ps[i-m])%d;
				if(nn[k]<2)
				{
					ex[k][nn[k]]=i-m+1;
					nn[k]++;
				}
			}
		}
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			z.fr=n+1;
			k=(ps[l]-ps[k-1])%d;
			for(i=0;i<d;i++)
			{
				l=(w+d-i*k%d)%d;
				e=l==i;
				if(nn[i]&&nn[l]>e)
				{
					z=min(z,{ex[i][0],ex[l][e]});
				}
			}
			if(z.fr>n)
			{
				z={-1,-1};
			}
			printf("%lld %lld\n",z.fr,z.sc);
		}
	}
}