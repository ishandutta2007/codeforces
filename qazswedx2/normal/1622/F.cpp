#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
int n,pn=1e6,p[1000005],prime[1000005],pt,g[1000005],tans[15],tt,vis[1000005];
bitset<1000005> a,b;
vector<int> val[1000005];
void solve(bitset<1000005> f,int id)
{
	int ct=f.count();
//	printf("solve:id=%d,tt=%d,ct=%d\n",id,tt,ct);
	if(ct==0)
	{
		if(tt>(id!=0))
		{
			tt=0;
			if(id) tans[++tt]=id;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		int sz=val[i].size();
		for(int j=0;j<sz;j++)
		{
			int v=val[i][j];
			ct-=f[v];
			f[v]=f[v]^1;
			ct+=f[v];
		}
		if(!ct)
		{
			if(tt>(id!=0)+1)
			{
				tt=0;
				tans[++tt]=i;
				if(id) tans[++tt]=id;
			}
		}
	}
}
int main()
{
	for(int i=2;i<=pn;i++)
	{
		if(!p[i])
		{
			prime[++pt]=i;
			g[i]=pt;
		}
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			g[i*prime[j]]=j;
			if(i%prime[j]==0) break;
		}
	}
	for(int i=1;i<=pn;i++)
	{
		int u=i;
		while(u!=1)
		{
			int ct=0,q=g[u];
			while(u%prime[q]==0)
			{
				u/=prime[q];
				ct++;
			}
			if(ct%2) val[i].push_back(q);
		}
	}
	tt=1e9;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int sz=val[i].size();
		for(int j=0;j<sz;j++)
		{
			if((n-i)%2==0) a[val[i][j]]=a[val[i][j]]^1;
			b[val[i][j]]=b[val[i][j]]^1;
		//	printf("i=%d,val=%d\n",i,val[i][j]);
		}
	}
	solve(a,0);
	bitset<1000005> tmp=a;
	tmp[1]=tmp[1]^1;
	solve(tmp,2);
	for(int i=n;i>0;i--)
	{
		solve(a^b,i);
		int sz=val[i].size();
		for(int j=0;j<sz;j++)
			b[val[i][j]]=b[val[i][j]]^1;
		if(!p[i]) break;
	}
	if(tt>3)
	{
		tt=0;
		tans[++tt]=n;
		tans[++tt]=n/2;
		tans[++tt]=2;
	}
//	printf("tt=%d\n",tt);
	printf("%d\n",n-tt);
	for(int i=1;i<=tt;i++)
		vis[tans[i]]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			printf("%d ",i);
	printf("\n");
	return 0;
}