#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,mxn=1e6,pr[1000069],dsu[1000069],nr[1000069],z,c,yk[26],vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},dv;
bitset<1000069> a,vtd,spc;
vector<long long> al[1000069];
string ky={"URDL"};

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(!a[x])
	{
		c+=!spc[nr[x]%dv];
		spc[nr[x]%dv]=1;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			nr[l]=nr[x]+1;
			dfs(l);
		}
	}
}

int main()
{
	long long t,rr,i,j,p;
	string s;
	
	for(i=0;i<4;i++)
	{
		yk[ky[i]-'A']=i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			cin>>s;
			for(j=0;j<m;j++)
			{
				a[i*m+j]=s[j]-'0';
			}
		}
		for(i=0;i<n;i++)
		{
			cin>>s;
			for(j=0;j<m;j++)
			{
				pr[i*m+j]=yk[s[j]-'A'];
			}
		}
		for(i=0;i<n*m;i++)
		{
			al[i].clear();
			dsu[i]=i;
			vtd[i]=0;
		}
		for(i=0;i<n*m;i++)
		{
			pr[i]=i+vy[pr[i]]*m+vx[pr[i]];
			al[pr[i]].push_back(i);
			dsu[fd(i)]=fd(pr[i]);
		}
		z=0;
		c=0;
		for(i=0;i<n*m;i++)
		{
			if(fd(i)==i)
			{
				dv=0;
				for(p=i;!vtd[p];p=pr[p])
				{
					dv++;
					vtd[p]=1;
				}
				z+=dv;
				for(p=i;vtd[p];p=pr[p])
				{
					vtd[p]=0;
				}
				for(j=0;j<dv;j++)
				{
					spc[j]=0;
				}
				nr[i]=0;
				dfs(i);
			}
		}
		printf("%lld %lld\n",z,c);
	}
}