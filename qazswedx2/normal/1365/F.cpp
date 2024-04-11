#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int x,y;
	pt(int xx=0,int yy=0)
	{
		if(xx>yy) swap(xx,yy);
		x=xx,y=yy;
	}
	bool operator<(const pt a) const
	{
		return x==a.x?y<a.y:x<a.x;
	} 
};
pt a[1005],b[1005];
int n,t,c[1005],d[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&d[i]);
		for(int i=1;i<=n/2;i++)
			a[i]=pt(c[i],c[n-i+1]);
		for(int i=1;i<=n/2;i++)
			b[i]=pt(d[i],d[n-i+1]);
		if(n%2==1&&c[n/2+1]!=d[n/2+1])
		{
			printf("No\n");
			continue;
		}
		sort(a+1,a+n/2+1);
		sort(b+1,b+n/2+1);
		int fl=1;
		for(int i=1;i<=n/2;i++)
			if(a[i].x!=b[i].x||a[i].y!=b[i].y)
				fl=0;
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}