#include <cstdio>
#include <algorithm>
using namespace std;
struct ticket
{
	int ti,from,to,cost;
	friend bool operator <(ticket a,ticket b)
	{
		if(a.to==0&&b.to==0)
			return a.ti<b.ti;
		else if(a.from==0&&b.from==0)
			return a.ti<b.ti;
		else return a.to==0;
	}
}tkt[100010];
long long ans,gotoans,backans;
int gotomin[100010],backmin[100010],change[100010],n,m,k,pos,gotook;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&tkt[i].ti,&tkt[i].from,&tkt[i].to,&tkt[i].cost);
	sort(tkt+1,tkt+m+1);
	ans=-1;
	for(int i=1;i<=n;i++)
		backmin[i]=-1;
	for(int i=m;i>=1;i--)
		if(tkt[i].from==0)
		{
			change[i]=backmin[tkt[i].to];
			if(backmin[tkt[i].to]==-1||backmin[tkt[i].to]>tkt[i].cost)
				backmin[tkt[i].to]=tkt[i].cost;
		}
		else
		{
			pos=i;
			break;
		}
	backans=0;
	for(int i=1;i<=n;i++)
		if(backmin[i]!=-1)
			backans+=backmin[i];
		else
		{
			printf("-1\n");
			return 0;
		}
	gotoans=0;
	gotook=0;
	int j=pos+1;
	for(int i=1;i<=n;i++)
		gotomin[i]=-1;
	for(int i=1;i<=pos;i++)
	{
		for(;j<=m&&tkt[j].ti-tkt[i].ti<=k;j++)
		{
			backans+=change[j]-backmin[tkt[j].to];
			backmin[tkt[j].to]=change[j];
			if(backmin[tkt[j].to]==-1)
			{
				printf("%lld\n",ans);
				return 0;
			}
		}
		if(j>m)
			break;
		if(gotomin[tkt[i].from]==-1)
		{
			gotomin[tkt[i].from]=tkt[i].cost;
			gotoans+=tkt[i].cost;
			gotook++;
		}
		else if(gotomin[tkt[i].from]>tkt[i].cost)
		{
			gotoans-=gotomin[tkt[i].from]-tkt[i].cost;
			gotomin[tkt[i].from]=tkt[i].cost;
		}
		if(gotook==n)
		{
			if(ans==-1||gotoans+backans<ans)
				ans=gotoans+backans;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}