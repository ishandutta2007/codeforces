#include<cstdio>
#include<algorithm>
using namespace std;
int f[5010],w[5010][5010],l[5010],r[5010],a[5010],n,ans,rmax,tans;
bool flag,vis[5010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(!l[a[i]])l[a[i]]=i;
		r[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	if(l[a[i]]==i)
	{
		rmax=r[a[i]];
		flag=1;
		for(int j=i+1;j<=rmax;j++)
		if(l[a[j]]<i)
		{
			flag=0;
			break;
		}
		else rmax=max(rmax,r[a[j]]);
		if(!flag)continue;
		tans=0;
		for(int j=i;j<=rmax;j++)
		if(!vis[a[j]])
		{
			vis[a[j]]=1;
			tans^=a[j];
		}
		w[i][rmax]=max(w[i][rmax],tans);
		for(int j=i;j<=rmax;j++)vis[a[j]]=0;
	}
	f[0]=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<i;j++)
	f[i]=max(f[i],f[j]+w[j+1][i]);
	ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}