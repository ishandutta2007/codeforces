#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,aa[2069][2069],a[2069][2069],mn[27][2],mx[27][2],zs;
vector<pair<pair<long long,long long>,pair<long long,long long>>> sq;

int main()
{
	long long t,rr,i,j,ii,jj,k;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=26;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				mn[i][ii]=1e18;
				mx[i][ii]=-1e18;
			}
		}
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=1;j<=m;j++)
			{
				if(s[j-1]=='.')
				{
					k=0;
				}
				else
				{
					k=s[j-1]-'a'+1;
				}
				aa[i][j]=k;
				if(k)
				{
					mn[k][0]=min(mn[k][0],i);
					mx[k][0]=max(mx[k][0],i);
					mn[k][1]=min(mn[k][1],j);
					mx[k][1]=max(mx[k][1],j);
				}
				a[i][j]=0;
			}
		}
		sq.clear();
		zs=0;
		for(j=1,i=1;i<=26;i++)
		{
			if(mn[i][0]<1000000000000000000)
			{
				if(mn[i][0]<mx[i][0]&&mn[i][1]<mx[i][1])
				{
					i=-1;
					break;
				}
				for(;j<=i;j++)
				{
					if(j==i)
					{
						for(ii=mn[i][0];ii<=mx[i][0];ii++)
						{
							for(jj=mn[i][1];jj<=mx[i][1];jj++)
							{
								a[ii][jj]=i;
							}
						}
					}
					sq.push_back({{mn[i][0],mn[i][1]},{mx[i][0],mx[i][1]}});
					zs++;
				}
			}
		}
		if(i==-1)
		{
			printf("NO\n");
			continue;
		}
		bad=0;
		for(i=1;!bad&&i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]!=aa[i][j])
				{
					bad=1;
					break;
				}
			}
		}
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n%lld\n",zs);
			for(i=0;i<zs;i++)
			{
				printf("%lld %lld %lld %lld\n",sq[i].fr.fr,sq[i].fr.sc,sq[i].sc.fr,sq[i].sc.sc);
			}
		}
	}
}