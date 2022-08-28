#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],vis[1000005],sum[1000005],tans1[1000005],tans2[1000005];
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
	//printf("modify:x=%d,v=%d\n",x,v);
	for(int i=x;i<=m;i+=lowbit(i))
		sum[i]+=v;
}
int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans+=sum[i];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		a[i]=n-i+1,tans1[i]=tans2[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i+n]);
	m+=n;
	for(int i=1;i<=m;i++)
	{
		if(vis[a[i]]) modify(vis[a[i]],-1);
		modify(i,1);
		if(i>n)
		{
			tans1[a[i]]=1;
			int q=query(i-1)-query(vis[a[i]]);
			//printf("i=%d,a=%d,q=%d\n",i,vis[a[i]],q);
			tans2[a[i]]=max(tans2[a[i]],q+1);
		}
		vis[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int q=query(m)-query(vis[i]);
		tans2[i]=max(tans2[i],q+1);
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",tans1[i],tans2[i]);
	return 0;
}