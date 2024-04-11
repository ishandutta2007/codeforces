#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,fq[30],sp[17][100069],lg2[100069];
pair<pair<long long,long long>,long long> qq[100069];
pair<long long,long long> as[200069];

void spbd()
{
	long long i,j,k;
	
	for(i=1;1ll<<i<=n;i++)
	{
		for(j=1;j<=n-(1ll<<i)+1;j++)
		{
			sp[i][j]=sp[i-1][j]&sp[i-1][j+(1ll<<i-1)];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
}

long long qr(long long lh,long long rh)
{
	long long e=lg2[rh-lh+1];
	
	return sp[e][lh]&sp[e][rh-(1ll<<e)+1];
}

int main()
{
	long long i,j,r,u,k,l,w;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		qq[i]={{k,l},w};
		as[i*2-1]={k,w};
		as[i*2]={l+1,-w};
	}
	sort(as+1,as+m*2+1);
	for(j=1,i=1;i<=n;i++)
	{
		for(;j<=m*2&&as[j].fr<=i;j++)
		{
			w=as[j].sc;
			if(w)
			{
				u=w/abs(w);
				w=abs(w);
				for(r=0;w;w/=2,r++)
				{
					fq[r]+=w%2*u;
				}
			}
		}
		for(r=0;r<30;r++)
		{
			sp[0][i]|=!!fq[r]<<r;
		}
	}
	spbd();
	for(i=1;i<=m;i++)
	{
		k=qq[i].fr.fr;
		l=qq[i].fr.sc;
		w=qq[i].sc;
		if(qr(k,l)!=w)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sp[0][i]," \n"[i==n]);
	}
}