#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=2E9+1;
struct datas
{
	int l,r,cost;
}data[200010],data2[200010];
bool cmp1(datas a,datas b){return a.r>b.r;}
bool cmp2(datas a,datas b){return a.l>b.l;}
int mincost[200010],n,X,ans;
int main()
{
	scanf("%d%d",&n,&X);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&data[i].l,&data[i].r,&data[i].cost);
		data2[i]=data[i];
	}
	sort(data+1,data+n+1,cmp1);
	sort(data2+1,data2+n+1,cmp2);
	for(int i=1;i<X;i++)mincost[i]=1E9+1;
	ans=INF;
	for(int i=1,j=0;i<=n;i++)
	{
		for(;j<n&&data2[j+1].l>data[i].r;)
		{
			j++;
			int len=data2[j].r-data2[j].l+1;
			if(len<X)mincost[len]=min(mincost[len],data2[j].cost);
		}
		int len=data[i].r-data[i].l+1;
		if(len<X&&mincost[X-len]!=1E9+1)ans=min(ans,data[i].cost+mincost[X-len]);
	}
	printf("%d",ans!=INF?ans:-1);
	return 0;
}