#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[400069],inf=1e18;
vector<pair<long long,long long>> fz[200069];

long long sm(long long lh,long long rh)
{
	return (rh+1)/2*(rh+1)/2-(lh-1)/2*(lh-1)/2;
}

int main()
{
	long long i,j,k,l=1,p,tg;
	
	for(i=1;i<=200000;i++)
	{
		for(j=i;j<=200000;j+=i)
		{
			if(i%2==j/i%2&&i>=j/i)
			{
				fz[j].push_back({i-j/i+1,i+j/i-1});
			}
		}
	}
	scanf("%lld",&n);
	for(i=1;i<=n/2;i++)
	{
		scanf("%lld",&k);
		p=upper_bound(fz[k].begin(),fz[k].end(),mp(l,inf))-fz[k].begin();
		if(p==fz[k].size())
		{
			printf("No\n");
			return 0;
		}
		tg=fz[k][p].fr;
		sq[i*2-1]=sm(l,tg-2);
		sq[i*2]=k;
		l=fz[k][p].sc+2;
	}
	printf("Yes\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}