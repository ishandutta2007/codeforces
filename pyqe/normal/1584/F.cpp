#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=53;
long long n,fq[10],pst[ma][10][2],sq[100069],zs;
pair<long long,pair<long long,long long>> dp[ma][1ll<<10];

pair<long long,pair<long long,long long>> bf(long long x,long long mk)
{
	if(dp[x][mk].fr==-1)
	{
		long long i,j,mk2;

		dp[x][mk]={1,{-1,-1}};
		for(mk2=mk;mk2;mk2=mk2-1&mk)
		{
			dp[x][mk]=max(dp[x][mk],bf(x,mk^mk2));
		}
		for(i=0;i<ma;i++)
		{
			mk2=0;
			for(j=0;j<n;j++)
			{
				if(pst[i][j][0]>=pst[x][j][mk>>j&1])
				{
					break;
				}
				mk2|=(long long)(pst[i][j][1]<pst[x][j][mk>>j&1])<<j;
			}
			if(j>=n)
			{
				dp[x][mk]=max(dp[x][mk],{bf(i,mk2).fr+1,{i,mk2}});
			}
		}
	}
	return dp[x][mk];
}

int main()
{
	long long t,rr,i,j,ii,k,e,e2,mk,mk2;
	pair<long long,pair<long long,long long>> tmp;
	char ch;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			cin>>s;
			fq[i]=s.length();
			for(j=0;j<ma;j++)
			{
				for(ii=0;ii<2;ii++)
				{
					pst[j][i][ii]=fq[i]+1;
				}
			}
			for(j=1;j<=fq[i];j++)
			{
				if(s[j-1]>='a')
				{
					k=s[j-1]-'a';
				}
				else
				{
					k=26+s[j-1]-'A';
				}
				pst[k][i][pst[k][i][0]!=fq[i]+1]=j;
			}
		}
		for(i=0;i<ma;i++)
		{
			for(mk=0;mk<1ll<<n;mk++)
			{
				dp[i][mk].fr=-1;
			}
		}
		tmp=bf(ma-1,0);
		e=tmp.sc.fr;
		mk=tmp.sc.sc;
		zs=0;
		for(;e!=-1;e=e2,mk=mk2)
		{
			zs++;
			sq[zs]=e;
			e2=dp[e][mk].sc.fr;
			mk2=dp[e][mk].sc.sc;
		}
		printf("%lld\n",zs);
		for(i=zs;i;i--)
		{
			if(sq[i]<26)
			{
				ch=sq[i]+'a';
			}
			else
			{
				ch=sq[i]-26+'A';
			}
			printf("%c",ch);
		}
		printf("\n");
	}
}