#include<bits/stdc++.h>
using namespace std;
struct shirts
{
	int id,p;
	friend bool operator <(shirts a,shirts b){return a.p<b.p;}
}shirt[4][200010];
int p[200010],a[200010],b[200010],tmp[4],len[4],n,m,x;
bool vis[200010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		shirt[a[i]][++len[a[i]]]=(shirts){i,p[i]};
		if(a[i]!=b[i])shirt[b[i]][++len[b[i]]]=(shirts){i,p[i]};
	}
	scanf("%d",&m);
	for(int i=1;i<=3;i++)sort(shirt[i]+1,shirt[i]+len[i]+1);
	for(int i=1;i<=3;i++)tmp[i]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		for(;tmp[x]<=len[x]&&vis[shirt[x][tmp[x]].id];tmp[x]++);
		if(tmp[x]<=len[x])
		{
			vis[shirt[x][tmp[x]].id]=1;
			printf("%d ",shirt[x][tmp[x]].p);
		}
		else printf("-1 ");
	}
	return 0;
}