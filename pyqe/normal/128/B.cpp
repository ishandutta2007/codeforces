#include <bits/stdc++.h>

using namespace std;

const long long mm=26;
long long n,d,nn=1,cr=1,ln[200069],pr[200069],nx[200069][mm],sbt[200069],dp[200069],sq[100069],zs=0;
vector<long long> al[200069];
bitset<200069> vtd;

void ins(long long x)
{
	long long i,l;
	
	nn++;
	ln[nn]=ln[cr]+1;
	sbt[nn]=1;
	for(;cr&&!nx[cr][x];cr=pr[cr])
	{
		nx[cr][x]=nn;
	}
	if(!cr)
	{
		pr[nn]=1;
		cr=nn;
	}
	else
	{
		l=nx[cr][x];
		if(ln[l]==ln[cr]+1)
		{
			pr[nn]=l;
			cr=nn;
		}
		else
		{
			nn++;
			ln[nn]=ln[cr]+1;
			pr[nn]=pr[l];
			for(i=0;i<mm;i++)
			{
				nx[nn][i]=nx[l][i];
			}
			pr[l]=nn;
			pr[nn-1]=nn;
			for(;cr&&nx[cr][x]==l;cr=pr[cr])
			{
				nx[cr][x]=nn;
			}
			cr=nn-1;
		}
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		sbt[x]+=sbt[l];
	}
	sbt[x]*=x!=1;
}

void dfs2(long long x)
{
	long long i,l;
	
	vtd[x]=1;
	dp[x]=sbt[x];
	for(i=0;i<mm;i++)
	{
		l=nx[x][i];
		if(l&&!vtd[l])
		{
			dfs2(l);
		}
		dp[x]+=dp[l];
	}
}

int main()
{
	long long i,k,l,p;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		ins(k);
	}
	for(i=2;i<=nn;i++)
	{
		al[pr[i]].push_back(i);
	}
	dfs(1);
	dfs2(1);
	scanf("%lld",&d);
	if(d>n*(n+1)/2)
	{
		printf("No such line.\n");
		return 0;
	}
	for(p=1;1;)
	{
		if(d<=sbt[p])
		{
			break;
		}
		d-=sbt[p];
		for(i=0;i<mm;i++)
		{
			l=nx[p][i];
			if(l)
			{
				if(d<=dp[l])
				{
					zs++;
					sq[zs]=i;
					p=l;
					break;
				}
				d-=dp[l];
			}
		}
	}
	for(i=1;i<=zs;i++)
	{
		printf("%c",(char)(sq[i]+'a'));
	}
	printf("\n");
}