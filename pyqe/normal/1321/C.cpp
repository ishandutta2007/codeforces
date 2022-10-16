#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],dsu[2][100069];
pair<long long,long long> as[100069];

long long fd(long long xx,long long x)
{
	if(dsu[xx][x]!=x)
	{
		dsu[xx][x]=fd(xx,dsu[xx][x]);
	}
	return dsu[xx][x];
}

int main()
{
	long long i,ii,iii,u,uu,p,tg,z=0;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<=n+1;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			dsu[ii][i]=i;
		}
	}
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
		as[i]={a[i],i};
	}
	sort(as+1,as+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		p=as[i].sc;
		for(ii=0;ii<2;ii++)
		{
			u=ii*2-1;
			for(;1;)
			{
				tg=fd(ii,p+u);
				if(!tg||tg>n||a[tg]!=a[p]+1)
				{
					break;
				}
				z++;
				for(iii=0;iii<2;iii++)
				{
					uu=iii*2-1;
					dsu[iii][fd(iii,tg)]=fd(iii,tg+uu);
				}
			}
		}
	}
	printf("%lld\n",z);
}