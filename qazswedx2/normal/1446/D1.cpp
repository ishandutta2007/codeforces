#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n,a[200005],vis[200005],bl,b[600005],pn=3e5,mx,id,ans;
int c[200005];
vector<int> val[200005];
void solve1(int x)
{
	memset(b,0x3f,sizeof(b));
	int nw=0;
	b[pn]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==id) nw++;
		else if(a[i]==x) nw--;
		ans=max(ans,i-b[pn+nw]);
		if(b[pn+nw]>n) b[pn+nw]=i;
	}
}
int tmp1[200005],tmp2[200005],t1,t2;
void solve2(int x)
{
	int sz=val[x].size();
	t1=t2=0;
	for(int i=0;i<sz;i++)
	{
		int u=val[x][i];
		int l=lower_bound(c+1,c+mx+1,u)-c-1;
		for(int j=max(l-sz-1,1);j<=min(l+sz+1,mx);j++)
			if(!t1||tmp1[t1]<c[j]) tmp1[++t1]=c[j];
	}
	int nw1=1,nw2=0;
	while(nw1<=t1&&nw2<sz)
	{
		if(tmp1[nw1]<val[x][nw2])
		{
			tmp2[++t2]=tmp1[nw1];
			nw1++;
		}
		else
		{
			tmp2[++t2]=val[x][nw2];
			nw2++;
		}
	}
	while(nw1<=t1)
	{
		tmp2[++t2]=tmp1[nw1];
		nw1++;
	}
	while(nw2<sz)
	{
		tmp2[++t2]=val[x][nw2];
		nw2++;
	}
/*	printf("x=%d,t2=%d\n",x,t2);
	for(int i=1;i<=t2;i++)
		printf("%d ",tmp2[i]);
	printf("\n");
	for(int i=1;i<=t1;i++)
		printf("%d ",tmp1[i]);
	printf("\n");
	for(int i=0;i<sz;i++)
		printf("%d ",val[x][i]);
	printf("\n");*/
	for(int i=pn-t2;i<=pn+t2;i++) b[i]=1e9;
	int nw=0;
	b[pn]=0;
	tmp2[t2+1]=n+1;
	for(int i=1;i<=t2;i++)
	{
		int u=tmp2[i];
		if(a[u]==id) nw++;
		else if(a[u]==x) nw--;
		ans=max(ans,tmp2[i+1]-1-b[pn+nw]);
		if(b[pn+nw]>n) b[pn+nw]=u;
	}
}
int main()
{
	scanf("%d",&n);
	bl=sqrt(n);
//	bl=1e9;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		vis[a[i]]++;
		val[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if(mx<vis[i]) mx=vis[i],id=i;
	for(int i=0;i<mx;i++)
		c[i+1]=val[id][i];
	for(int i=1;i<=n;i++)
		if(mx==vis[i]&&id!=i)
		{
			printf("%d\n",n);
			return 0;
		}
	for(int i=1;i<=n;i++)
	{
		if(i==id) continue;
		if(vis[i]>bl)
			solve1(i);
		else solve2(i);
	}
	printf("%d\n",ans);
	return 0;
}