#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,lm=2520,d[2569],tg[2569][2569],fq[1069],c=0,dp[2569][2569];
vector<pair<int,int>> cd[2569][2569];
pair<int,int> pr[2569][2569];
bitset<2569> vtd[2569],vtd2[2569];

pair<int,int> fd(pair<int,int> x)
{
	if(pr[x.fr][x.sc]!=x)
	{
		pr[x.fr][x.sc]=fd(pr[x.fr][x.sc]);
	}
	return pr[x.fr][x.sc];
}

void dfs(pair<int,int> x)
{
	int i,sz=cd[x.fr][x.sc].size();
	pair<int,int> l;
	
	vtd[x.fr][x.sc]=1;
	if(!fq[x.fr])
	{
		c++;
	}
	fq[x.fr]++;
	vtd2[x.fr][x.sc]=1;
	for(i=0;i<sz;i++)
	{
		l=cd[x.fr][x.sc][i];
		if(vtd2[l.fr][l.sc])
		{
			pair<int,int> tmp=fd(x);
			dp[tmp.fr][tmp.sc]=c;
		}
		if(!vtd[l.fr][l.sc])
		{
			dfs(l);
		}
	}
	vtd2[x.fr][x.sc]=0;
	fq[x.fr]--;
	if(!fq[x.fr])
	{
		c--;
	}
}

int main()
{
	int t,rr,i,k,l,mm,j,yy,xx;
	pair<int,int> tmp;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		d[i]=(k%lm+lm)%lm;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&mm);
		for(j=0;j<lm;j++)
		{
			if(j<mm)
			{
				scanf("%d",&tg[i][j]);
			}
			else
			{
				tg[i][j]=tg[i][j-mm];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<lm;j++)
		{
			pr[i][j]={i,j};
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<lm;j++)
		{
			xx=(j+d[i])%lm;
			yy=tg[i][xx];
			cd[yy][xx].push_back({i,j});
			tmp=fd({i,j});
			pr[tmp.fr][tmp.sc]=fd({yy,xx});
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<lm;j++)
		{
			if(!vtd[i][j])
			{
				dfs({i,j});
			}
		}
	}
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d",&k,&l);
		l=(l%lm+lm)%lm;
		tmp=fd({k,l});
		printf("%d\n",dp[tmp.fr][tmp.sc]);
	}
}