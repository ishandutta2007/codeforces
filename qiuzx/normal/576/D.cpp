#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 160
using namespace std;
ll n,m,dist[N],ans=LINF+100;
vector<bitset<N> > arr,pos,lst,ALL;
vector<ll> vt[N];
vector<pair<ll,pair<ll,ll> > > ed;
queue<ll> q;
vector<bitset<N> > rev(vector<bitset<N> > a)
{
	vector<bitset<N> > ret;
	ret.resize(N);
	ll i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ret[j][i]=a[i][j];
		}
	}
	return ret;
}
vector<bitset<N> > mat_tim(vector<bitset<N> > a,vector<bitset<N> > b)
{
	ll i,j;
	b=rev(b);
	vector<bitset<N> > ret;
	ret.resize(N);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((a[i]&b[j]).any())
			{
				ret[i][j]=true;
			}
		}
	}
	return ret;
}
vector<bitset<N> > ksm(ll x)
{
	if(x==0)
	{
		return ALL;
	}
	if(x==1)
	{
		return arr;
	}
	vector<bitset<N> > res=ksm(x>>1);
	res=mat_tim(res,res);
	if(x&1)
	{
		res=mat_tim(res,arr);
	}
	return res;
}
int main(){
	ll i,j,x,y,d;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&d);
		x--;
		y--;
		ed.push_back(make_pair(d,make_pair(x,y)));
	}
	ALL.resize(N);
	ALL[0][0]=1;
	sort(ed.begin(),ed.end());
	d=0;
	arr.resize(N);
	pos.resize(N);
	lst.resize(N);
	for(i=0;i<ed.size();i++)
	{
		if(ed[i].F!=0)
		{
			break;
		}
		arr[ed[i].S.F][ed[i].S.S]=true;
		vt[ed[i].S.F].push_back(ed[i].S.S);
	}
	q.push(0);
	memset(dist,63,sizeof(dist));
	dist[0]=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(j=0;j<vt[x].size();j++)
		{
			if(dist[vt[x][j]]>dist[x]+1)
			{
				dist[vt[x][j]]=dist[x]+1;
				q.push(vt[x][j]);
			}
		}
	}
	ans=min(ans,dist[n-1]);
	for(;i<ed.size();)
	{
		pos=ksm(ed[i].F-d);
		if(i!=0&&ed[i-1].F!=0)
		{
			pos=mat_tim(lst,pos);
		}
		memset(dist,63,sizeof(dist));
		for(j=i;j<ed.size();j++)
		{
			if(ed[i].F!=ed[j].F)
			{
				break;
			}
			arr[ed[j].S.F][ed[j].S.S]=true;
			vt[ed[j].S.F].push_back(ed[j].S.S);
		}
		d=ed[i].F;
		i=j;
		for(j=0;j<n;j++)
		{
			if(pos[0][j])
			{
				dist[j]=ed[i-1].F;
				q.push(j);
			}
		}
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(j=0;j<vt[x].size();j++)
			{
				if(dist[vt[x][j]]>dist[x]+1)
				{
					dist[vt[x][j]]=dist[x]+1;
					q.push(vt[x][j]);
				}
			}
		}
		ans=min(ans,dist[n-1]);
		lst=pos;
	}
	if(ans<LINF)
	{
		printf("%lld\n",ans);
	}
	else
	{
		puts("Impossible");
	}
	return 0;
}