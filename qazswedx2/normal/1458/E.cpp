#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct pt
{
	int x,y,id;
	pt(int x=0,int y=0):x(x),y(y){}
	bool operator<(const pt p) const
	{
		if(x!=p.x||y!=p.y) return x==p.x?y<p.y:x<p.x;
		return id<p.id;
	}
}a[1000005];
int n,m,at,k,qans[1000005];
set<int> st;
void getans(int x)
{
	while(!st.empty())
	{
		int u=*st.begin();
		if(u-k-1>=x)
		{
			k+=x;
			return;
		}
		x-=u-k-1;
		k=u;
		st.erase(st.begin());
	}
	k+=x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		at++;
		scanf("%d%d",&a[at].x,&a[at].y);
	}
	for(int i=1;i<=m;i++)
	{
		at++;
		scanf("%d%d",&a[at].x,&a[at].y);
		a[at].id=i;
	}
	sort(a+1,a+at+1);
	int las=-1;
	k=-1;
	for(int l=1,r;l<=at;l=r+1)
	{
		r=l;
		while(r<at&&a[r+1].x==a[l].x) r++;
		getans(a[l].x-las-1);
		getans(1);
		int q=k;
		int fl=0;
		for(int i=l;i<=r;i++)
			if(!a[i].id)
			{
				if(a[i].y<=q) fl=1;
				if(a[i].y>=q) st.insert(a[i].y);
			}
		if(fl) k--,q=-1;
		for(int i=l;i<=r;i++)
			if(a[i].id&&((i!=l&&a[i-1].y==a[i].y)||a[i].y==q))
				qans[a[i].id]=1;
		/*printf("l=%d,r=%d,k=%d,st=",l,r,k);
		for(set<int>::iterator it=st.begin();it!=st.end();it++)
			printf("%d ",*it);
		printf("\n");*/
		las=a[l].x;
	}
	for(int i=1;i<=m;i++)
		if(!qans[i]) printf("WIN\n");
		else printf("LOSE\n");
	return 0;
}