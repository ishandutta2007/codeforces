#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7,P=998244353;

vector<int>v[11];

int n,a[N],r1[N][2],r2[N][11][2],v1[N][2],v2[N][11][2];

ll split(int x,int fc)
{
	if(v1[x][fc])
		return r1[x][fc];
	ll v=a[x];
	ll ret=0,nvv=1,nv=10;
	while(v)
	{
		ll now=v%10;
		ret=(ret+now*(fc==0?nvv:nv)%P)%P;
		nv=nv*100%P;
		nvv=nvv*100%P;
		v/=10;
	}
	v1[x][fc]=1;
	return r1[x][fc]=ret;
}

ll change(int x,int b,int fc)
{
	if(v2[x][b][fc])
		return r2[x][b][fc];
	ll v=a[x];
	ll ret=0,nv=10,nvv=1;
	while(b)
	{
		ll now=v%10;
		ret=(ret+now*(fc==0?nvv:nv)%P)%P;
		nv=nv*100%P;
		nvv=nvv*100%P;
		v/=10;
		b--;
	}
	ret=(ret+nvv*v%P)%P;
	v2[x][b][fc]=1;
	return r2[x][b][fc]=ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int x=a[i],ct=0;
		while(x)
			x/=10,ct++;
		v[ct].push_back(i);
	}
	ll ans=0;
	for(int i=1;i<=10;i++)
	{
		for(int j=i;j<=10;j++)
		{
			for(int k=0;k<v[i].size();k++)
				ans=(ans+split(v[i][k],0)*v[j].size()%P)%P;
			for(int k=0;k<v[j].size();k++)
				ans=(ans+change(v[j][k],i,1)*v[i].size()%P)%P;
		}
		for(int j=1;j<i;j++)
		{
			for(int k=0;k<v[i].size();k++)
				ans=(ans+change(v[i][k],j,0)*v[j].size()%P)%P;
			for(int k=0;k<v[j].size();k++)
				ans=(ans+split(v[j][k],1)*v[i].size()%P)%P;
		}
	}
	printf("%lld",ans);
}