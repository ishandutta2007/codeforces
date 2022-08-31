#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int t,n[3],a[3][1000005],bt,vis[15];
ll tans;
pii b[1000005];
ll getlen(ll x,ll y,ll z)
{
	return (x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z);
}
void check(ll x,ll y,ll z)
{
	tans=min(tans,(x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z));
}
void tcheck(int x,int y,int id)
{
	int l=1,r=n[id];
	while(r-l>5)
	{
		int mid=(l+r)/2;
		if(getlen(x,y,a[id][mid])>getlen(x,y,a[id][mid+1])) l=mid+1;
		else r=mid;
	}
	for(int i=l;i<=r;i++)
		check(x,y,a[id][i]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		bt=0;
		tans=3e18;
		scanf("%d%d%d",&n[0],&n[1],&n[2]);
		for(int i=0;i<3;i++)
		{
			for(int j=1;j<=n[i];j++)
			{
				scanf("%d",&a[i][j]);
				b[++bt].first=a[i][j];
				b[bt].second=i;
			}
			sort(a[i]+1,a[i]+n[i]+1);
		}
		sort(b+1,b+bt+1);
		for(int i=1;i<bt;i++)
			if(b[i].second!=b[i+1].second)
			{
				vis[0]=vis[1]=vis[2]=0;
				vis[b[i].second]=vis[b[i+1].second]=1;
				int nw=b[i+1].first,id=0;
				for(int j=0;j<3;j++) if(!vis[j]) id=j;
				int tnw=lower_bound(a[id]+1,a[id]+n[id]+1,nw)-a[id];
				//if(tnw<n[id]) check(b[i].first,b[i+1].first,a[id][tnw+1]);
				if(tnw<=n[id]) tcheck(b[i].first,a[id][tnw],b[i+1].second);
				if(tnw>1) tcheck(a[id][tnw-1],b[i+1].first,b[i].second);
				//if(tnw>2) check(b[i].first,b[i+1].first,a[id][tnw-2]);
			}
		printf("%I64d\n",tans);
	}
	return 0;
}