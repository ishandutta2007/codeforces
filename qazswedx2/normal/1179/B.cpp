#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){}
	bool operator <(const pt xx) const
	{
		return x==xx.x?y<xx.y:x<xx.x;
	}
};
set<pt> st;
int n,m,cnt=0,sx,sy,sw,ex,ey,ew,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1&&m==1)
	{
		printf("1 1");
		return 0;
	}
	printf("1 1\n%d %d\n",n,m);
	st.insert(pt(1,1));
	st.insert(pt(n,m));
	sx=sy=1;
	sw=1;
	ex=n,ey=m;
	ew=3;
	cnt=2;
	while(cnt<n*m)
	{
		int xx=sx+dx[sw],yy=sy+dy[sw];
		while(xx<1||xx>n||yy<1||yy>m||st.count(pt(xx,yy)))
		{
			sw=(sw+1)%4;
			xx=sx+dx[sw],yy=sy+dy[sw];
			//printf("xx=%d,yy=%d\n",xx,yy);
		}
		cnt++;
		sx=xx,sy=yy;
		st.insert(pt(sx,sy));
		printf("%d %d\n",sx,sy);
		xx=ex+dx[ew],yy=ey+dy[ew];
		if(cnt==n*m) return 0;
		while(xx<1||xx>n||yy<1||yy>m||st.count(pt(xx,yy)))
		{
			ew=(ew+1)%4;
			xx=ex+dx[ew],yy=ey+dy[ew];
		}
		cnt++;
		ex=xx,ey=yy;
		printf("%d %d\n",ex,ey);
		st.insert(pt(ex,ey));
		if(cnt==n*m) return 0;
	}
	return 0;
}