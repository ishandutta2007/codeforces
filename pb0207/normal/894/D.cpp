#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int n,m;

ll w[N],ans[N];

struct Q{
	int x;
	ll v;
	int id;
	bool flag;
}q[N];

vector<ll>p[N],sum[N];

vector<Q>s[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%lld",&q[i].x,&q[i].v),q[i].id=i;
	for(int i=1;i<=m;i++)
	{
		int y=q[i].x;
		ll now=q[i].v;
		ans[i]+=now;
		bool last=y&1;
		Q tmp;
		tmp=q[i];
		q[i].flag=0;
		s[y].push_back(q[i]);
		q[i].flag=1;
		s[y].push_back(q[i]);
		while(now>=0&&y)
		{
			last=y&1;
			now-=w[y-1];
			if(now<0)
				break;
			tmp.x=q[i].x,tmp.v=now,tmp.id=q[i].id;
			tmp.flag=last;
			y>>=1;
			if(y==0)
				break;
			s[y].push_back(tmp);
			ans[i]+=now;
		}
	}
	for(int i=n;i>=1;i--)
	{
		int s1=i<<1,s2=i<<1|1;
		if(s1<=n)
			for(int j=0;j<p[s1].size();j++)
				p[i].push_back(p[s1][j]+w[s1-1]);
		if(s2<=n)
			for(int j=0;j<p[s2].size();j++)
				p[i].push_back(p[s2][j]+w[s2-1]);
		p[i].push_back(0);
		sort(p[i].begin(),p[i].end());
		ll ss=0;
		for(int j=0;j<p[i].size();j++)
			ss+=p[i][j],sum[i].push_back(ss);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s[i].size();j++)
		{
			int t=s[i][j].id;
			ll h=s[i][j].v;
			int zz;
			if(s[i][j].flag)
				zz=i<<1;
			else
				zz=i<<1|1;
			if(zz>n)
				continue;
			h-=w[zz-1];
			if(h<0)
				continue;
			int k=upper_bound(p[zz].begin(),p[zz].end(),h)-p[zz].begin();
			k--;
			ans[t]+=h*(k+1)-sum[zz][k];
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
}