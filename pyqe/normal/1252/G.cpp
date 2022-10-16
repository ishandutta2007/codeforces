#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,h,cl[200069],dd=0;
pair<long long,long long> a[200069],dp[200069][4];
pair<long long,array<long long,2>> pt[200069];

int main()
{
	long long i,ii,iii,mn,z=1e18;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&h);
	a[0]={1,1};
	for(i=1;i<=d;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	sort(a,a+d+1);
	for(i=1;i<=h;i++)
	{
		scanf("%lld",cl+i);
	}
	cl[h+1]=m+1;
	sort(cl,cl+h+2);
	pt[0]={1,{1,1}};
	for(i=0;i<=d;i++)
	{
		if(i==0||a[i].fr!=a[i-1].fr)
		{
			dd++;
			pt[dd]={a[i].fr,{a[i].sc,a[i].sc}};
		}
		else
		{
			pt[dd].sc[1]=a[i].sc;
		}
	}
	for(ii=0;ii<4;ii++)
	{
		dp[0][ii]={0,1};
	}
	for(i=1;i<=dd;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			mn=1e18;
			for(iii=0;iii<4;iii++)
			{
				mn=min(mn,dp[i-1][iii].fr+pt[i].fr-pt[i-1].fr+abs(dp[i-1][iii].sc-pt[i].sc[!ii])+pt[i].sc[1]-pt[i].sc[0]);
			}
			if(i==dd)
			{
				z=min(z,mn);
			}
			dp[i][ii*2].sc=cl[upper_bound(cl,cl+h+2,pt[i].sc[ii])-cl-1];
			dp[i][ii*2+1].sc=cl[lower_bound(cl,cl+h+2,pt[i].sc[ii])-cl];
			for(iii=0;iii<2;iii++)
			{
				if(dp[i][ii*2+iii].sc<1||dp[i][ii*2+iii].sc>m)
				{
					dp[i][ii*2+iii].fr=1e18;
				}
				else
				{
					dp[i][ii*2+iii].fr=mn+abs(pt[i].sc[ii]-dp[i][ii*2+iii].sc);
				}
			}
		}
	}
	printf("%lld\n",z);
}