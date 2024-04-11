#include <bits/stdc++.h>

using namespace std;

const long long mm=17,dv=998244353;
long long n,ttl=0,a[1069],pc[mm][1069],dp[mm][1ll<<mm];

int main()
{
	long long t,rr,i,j,r,k,l,mk,c,ln;
	char ch;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<mm;i++)
	{
		pc[i][0]=1;
	}
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		if(ch!='?')
		{
			a[i]=ch-'a';
		}
		else
		{
			a[i]=-1;
			ttl++;
		}
		for(j=0;j<mm;j++)
		{
			pc[j][i]=pc[j][i-1]*(j+1)%dv;
		}
	}
	for(i=2;i<=n*2;i++)
	{
		mk=0;
		c=ttl;
		for(j=0;1;j++)
		{
			k=i/2-j;
			l=(i+1)/2+j;
			if(k<1||l>n||(a[k]!=-1&&a[l]!=-1&&a[k]!=a[l]))
			{
				break;
			}
			if((a[k]==-1&&a[l]!=-1)||(a[k]!=-1&&a[l]==-1))
			{
				mk|=1ll<<max(a[k],a[l]);
				c--;
			}
			if(a[k]==-1&&a[l]==-1&&k!=l)
			{
				c--;
			}
			for(r=0;r<mm;r++)
			{
				dp[r][mk]=(dp[r][mk]+pc[r][c])%dv;
			}
		}
	}
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			for(mk=(1ll<<mm)-1;mk>=0;mk--)
			{
				dp[i][mk]=(dp[i][mk]+dp[i][mk^1ll<<j]*(mk>>j&1))%dv;
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		ln=s.length();
		mk=0;
		for(i=0;i<ln;i++)
		{
			k=s[i]-'a';
			mk|=1ll<<k;
		}
		printf("%lld\n",dp[ln-1][mk]);
	}
}