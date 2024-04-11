#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],nans=-1,nans2=-1,tans=1,maxn,ncnt,vis[100005],cnt[100005];
/*void ins(int nw)
{
	if(nans==-1) nans=nw;
	else if(nans2==-1) nans2=nw;
}
void del(int nw)
{
	if(nans2==nw) nans2=-1;
	else if(nans==nw)
	{
		swap(nans,nans2);
		nans2=-1;
	}
}*/
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		cnt[vis[a[i]]]--;
		//if(!cnt[vis[a[i]]]) ncnt--,del(vis[a[i]]);
		vis[a[i]]++; 
		cnt[vis[a[i]]]++;
		maxn=max(maxn,vis[a[i]]);
		//if(cnt[vis[a[i]]]==1) ncnt++,ins(vis[a[i]]);
		if(maxn==1||i-1ll*maxn*cnt[maxn]==1)
		{
			tans=i;
		}
		int nw=maxn*cnt[maxn],nw2=(maxn-1)*cnt[maxn-1];
		if(nw+nw2==i&&(cnt[maxn]==1))
			tans=i;
	}
	printf("%d",tans);
	return 0;
}