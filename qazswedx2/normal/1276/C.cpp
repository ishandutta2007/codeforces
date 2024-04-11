#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int ct,val;
	bool operator<(const pt x) const
	{
		return ct>x.ct;
	}
}b[1000005];
int n,a[1000005],bt,vis[1000005],mx,mp[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	bt=1;
	b[1].val=a[1];
	b[1].ct=1;
	for(int i=2;i<=n;i++)
		if(a[i]==b[bt].val)
			b[bt].ct++;
		else 
		{
			b[++bt].val=a[i];
			b[bt].ct=1;
		}
	int sum=0,nw=0,mx=0,id=0;
	for(int i=1;i<=bt;i++)
	{
		vis[b[i].ct]++;
		nw++;
	}
	sort(b+1,b+bt+1);
	for(int i=1;i*i<=n;i++)
	{
		sum+=vis[i]*i;
		nw-=vis[i];
		//printf("sum=%d,nw=%d,%d\n",sum,nw,(nw*i+sum)/i*i);
		if((nw*i+sum)/i<i) continue;
		if((nw*i+sum)/i*i>mx)
		{
			mx=(nw*i+sum)/i*i;
			id=i;
		}
	}
	printf("%d\n",mx);
	int nx=1,ny=1,mxx=id,mxy=mx/id;
	printf("%d %d\n",mxx,mxy);
	for(int i=1;i<=bt;i++)
	{
		int cnt=min(b[i].ct,id);
		while(cnt--)
		{
			mp[(nx-1)*mxy+ny]=b[i].val;
			nx=nx%mxx+1,ny=ny%mxy+1;
			if(mp[(nx-1)*mxy+ny]) ny=ny%mxy+1;
		}
	}
	for(int i=1;i<=mxx;i++)
	{
		for(int j=1;j<=mxy;j++)
			printf("%d ",mp[(i-1)*mxy+j]);
		printf("\n");
	}
	return 0;
}