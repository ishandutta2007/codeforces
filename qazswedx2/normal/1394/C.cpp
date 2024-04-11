#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){}
}p[500005];
int n,a[500005][2],b[500005][2],c[500005][2],pn=5e5;
int dx[24]={2,2,2,2,2,1,1,1,1,1,0,0,0,0,-1,-1,-1,-1,-1,-2,-2,-2,-2,-2};
int dy[24]={-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-2,-1,0,1,2,};
char s[500005];
void getans(int f[][2])
{
	for(int i=1;i<=pn;i++)
		f[i][0]=min(f[i][0],f[i-1][0]);
	for(int i=pn-1;i>=0;i--)
		f[i][1]=max(f[i][1],f[i+1][1]);
}
int F(pt q)
{
	int ans=0,x=q.x,y=q.y;
	ans=max(ans,y-a[x][0]);
	ans=max(ans,a[x][1]-y);
	ans=max(ans,x-b[y][0]);
	ans=max(ans,b[y][1]-x);
	ans=max(ans,(x-y)-c[x][0]);
	ans=max(ans,c[x][1]-(x-y));
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=pn;i++)
	{
		a[i][0]=b[i][0]=c[i][0]=1e9;
		a[i][1]=b[i][1]=c[i][1]=-1e9;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=0;s[j];j++)
			if(s[j]=='B') p[i].x++;
			else p[i].y++;
	}
//	for(int i=1;i<=n;i++)
//		printf("%d %d\n",p[i].x,p[i].y);
	for(int i=1;i<=n;i++)
	{
		int x=p[i].x,y=p[i].y;
		a[x][0]=min(a[x][0],y);
		a[x][1]=max(a[x][1],y);
		b[y][0]=min(b[y][0],x);
		b[y][1]=max(b[y][1],x);
		c[x][0]=min(c[x][0],x-y);
		c[x][1]=max(c[x][1],x-y);
	}
	getans(a);
	getans(b);
	getans(c);
	//for(int i=0;i<=3;i++)
	//	printf("i=%d,c=%d,%d\n",i,c[i][0],c[i][1]);
	/*for(int i=5;i<=28;i++)
	{
		for(int j=5;j<=28;j++)
			printf("%d ",F(pt(i,j)));
		printf("\n");
	}*/
	pt nw=pt(0,1);
	int ans=F(nw);
	while(1)
	{
	//	printf("ans=%d,nw=%d,%d\n",ans,nw.x,nw.y);
		int fl=0;
		for(int i=0;i<24;i++)
		{
			pt nww=pt(nw.x+dx[i],nw.y+dy[i]);
			if(nww.x<0||nww.y<0||nww.x+nww.y==0) continue;
			int q=F(nww);
			if(q<ans)
			{
				ans=q;
				nw=nww;
				fl=1;
				break;
			}
		}
		if(!fl) break;
	}
	printf("%d\n",ans);
	for(int i=1;i<=nw.x;i++)
		printf("B");
	for(int i=1;i<=nw.y;i++)
		printf("N");
	return 0;
}