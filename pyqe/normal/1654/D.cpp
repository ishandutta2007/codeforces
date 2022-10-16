#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=2e5,dv=998244353;
long long n,ca[200069],mna[200069],pwk,z;
bitset<200069> ip,vtd;
vector<pair<long long,long long>> fz[200069];
vector<pair<long long,pair<long long,long long>>> al[200069];

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

void bd(long long x)
{
	long long i,j,ii,u,sz=al[x].size(),k,l,w,w2,sz2,c;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc.fr;
		w2=al[x][i].sc.sc;
		if(!vtd[l])
		{
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				sz2=fz[w2].size();
				for(j=0;j<sz2;j++)
				{
					k=fz[w2][j].fr;
					c=fz[w2][j].sc;
					ca[k]+=c*u;
					mna[k]=min(mna[k],ca[k]);
				}
				swap(w,w2);
			}
			bd(l);
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				sz2=fz[w].size();
				for(j=0;j<sz2;j++)
				{
					k=fz[w][j].fr;
					c=fz[w][j].sc;
					ca[k]+=c*u;
					mna[k]=min(mna[k],ca[k]);
				}
				swap(w,w2);
			}
		}
	}
}

void trv(long long x,long long cw)
{
	long long i,sz=al[x].size(),l,w,w2;
	
	vtd[x]=1;
	z=(z+cw)%dv;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc.fr;
		w2=al[x][i].sc.sc;
		if(!vtd[l])
		{
			trv(l,cw*pw(w,dv-2)%dv*w2%dv);
		}
	}
}

int main()
{
	long long t,rr,i,j,k,l,w,w2,c,ml;
	
	for(i=2;i<=ma;i++)
	{
		if(fz[i].empty())
		{
			ip[i]=1;
			for(j=i;j<=ma;j+=i)
			{
				for(c=0,k=j;k%i==0;k/=i,c++);
				fz[j].push_back({i,c});
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld%lld%lld",&k,&l,&w,&w2);
			al[k].push_back({l,{w,w2}});
			al[l].push_back({k,{w2,w}});
		}
		for(i=1;i<=n;i++)
		{
			ca[i]=0;
			mna[i]=0;
		}
		bd(1);
		ml=1;
		for(i=1;i<=n;i++)
		{
			if(ip[i])
			{
				ml=ml*pw(i,-mna[i])%dv;
			}
			vtd[i]=0;
		}
		z=0;
		trv(1,ml);
		printf("%lld\n",z);
	}
}