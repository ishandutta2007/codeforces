#include <bits/stdc++.h>

using namespace std;

long long ln,n[3],aa[100069],pr[26][100069],a[3][269],dp[269][269][269];

int main()
{
	long long t,rr,i,j,ii,k,l,tg[3];
	string s;
	char ch;
	
	scanf("%lld%lld",&ln,&t);
	cin>>s;
	for(i=1;i<=ln;i++)
	{
		aa[i]=s[i-1]-'a';
	}
	for(i=0;i<26;i++)
	{
		pr[i][ln+1]=ln+1;
		for(j=ln;j+1;j--)
		{
			pr[i][j]=pr[i][j+1];
			if(aa[j+1]==i)
			{
				pr[i][j]=j+1;
			}
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf(" %c%lld",&ch,&k);
		k--;
		if(ch=='+')
		{
			scanf(" %c",&ch);
			l=ch-'a';
			n[k]++;
			a[k][n[k]]=l;
			for(i=0;i<=n[(k+1)%3];i++)
			{
				for(j=0;j<=n[(k+2)%3];j++)
				{
					tg[0]=n[k];
					tg[1]=i;
					tg[2]=j;
					for(ii=0;ii<k;ii++)
					{
						swap(tg[0],tg[1]);
						swap(tg[0],tg[2]);
					}
					dp[tg[0]][tg[1]][tg[2]]=1e18;
					for(ii=0;ii<3;ii++)
					{
						if(tg[ii])
						{
							dp[tg[0]][tg[1]][tg[2]]=min(dp[tg[0]][tg[1]][tg[2]],pr[a[ii][tg[ii]]][dp[tg[0]-!ii][tg[1]-(ii==1)][tg[2]-(ii==2)]]);
						}
					}
				}
			}
		}
		else if(ch=='-')
		{
			n[k]--;
		}
		if(dp[n[0]][n[1]][n[2]]<=ln)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}