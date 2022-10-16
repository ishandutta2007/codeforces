#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[3069],ps[3069],nr[3069][3069],inf=1e18;
queue<pair<long long,long long>> q;

int main()
{
	long long i,j,ii,iii,k,l,kk,ll,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=!!k+(k==100);
	}
	for(i=n;i;i--)
	{
		ps[i]=max(ps[i+1],a[i]);
	}
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			nr[i][j]=inf;
		}
	}
	q.push({0,1});
	nr[0][1]=0;
	for(;!q.empty();)
	{
		k=q.front().fr;
		l=q.front().sc;
		q.pop();
		z+=nr[k][l]<=d;
		for(ii=a[k+1]==2;ii<=!!a[k+1];ii++)
		{
			for(iii=ps[l+1]==2;iii<=!!ps[l+1];iii++)
			{
				kk=k;
				ll=l+ii;
				if(iii)
				{
					kk=ll;
					ll++;
				}
				if((kk==n||ll<=n)&&nr[k][l]+1<nr[kk][ll])
				{
					q.push({kk,ll});
					nr[kk][ll]=nr[k][l]+1;
				}
			}
		}
	}
	printf("%lld\n",z);
}