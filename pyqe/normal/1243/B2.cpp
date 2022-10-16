#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[2][1069],zs;
vector<pair<long long,long long>> sq;

int main()
{
	long long t,rr,i,j,ii;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			for(i=1;i<=n;i++)
			{
				a[ii][i]=s[i-1]-'a';
			}
		}
		sq.clear();
		zs=0;
		bad=0;
		for(i=1;i<=n;i++)
		{
			if(a[0][i]!=a[1][i])
			{
				bad=1;
				for(j=i+1;bad&&j<=n;j++)
				{
					for(ii=0;ii<2;ii++)
					{
						if(a[ii][j]==a[0][i])
						{
							if(ii)
							{
								swap(a[0][j],a[1][j]);
								sq.push_back({j,j});
								zs++;
							}
							swap(a[0][j],a[1][i]);
							sq.push_back({j,i});
							zs++;
							bad=0;
							break;
						}
					}
				}
				if(bad)
				{
					break;
				}
			}
		}
		if(bad)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n%lld\n",zs);
			for(i=0;i<zs;i++)
			{
				printf("%lld %lld\n",sq[i].fr,sq[i].sc);
			}
		}
	}
}