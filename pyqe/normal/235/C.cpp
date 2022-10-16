#include <bits/stdc++.h>

using namespace std;

const long long mm=26;
long long n,nn=1,cr=1,ln[2000069],pr[2000069],nx[2000069][mm],sbt[2000069],vi[2000069];
vector<long long> al[2000069];

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
}

int main()
{
	long long t,rr,i,k,sz,p,c,z;
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
	sbt[1]=0;
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		cin>>s;
		sz=s.length();
		z=0;
		p=1;
		c=0;
		for(i=1;i<=sz*2;i++)
		{
			k=s[(i-1)%sz]-'a';
			for(;p&&!nx[p][k];p=pr[p]);
			c=min(c,ln[p])+1;
			if(!p)
			{
				p=1;
			}
			else
			{
				p=nx[p][k];
			}
			for(;ln[pr[p]]>=sz;p=pr[p]);
			c=min(c,ln[p]);
			if(c>=sz)
			{
				z+=sbt[p]*(vi[p]<rr);
				vi[p]=rr;
			}
		}
		printf("%lld\n",z);
	}
}