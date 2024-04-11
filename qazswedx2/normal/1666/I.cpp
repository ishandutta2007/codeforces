#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m;
int query(int x,int y)
{
	printf("SCAN %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int check(int x,int y)
{
	printf("DIG %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		int v1=query(1,1)+4,v2=query(1,m)+2-2*m;
		int sx=(v1+v2)/2,sy=(v1-v2)/2;
		int q1=query(sx/2,1)-(sy-2);
		int x=sx/2-q1/2,xx=sx/2+(q1+1)/2;
		int q2=query(1,sy/2)-(sx-2);
		int y=sy/2-q2/2,yy=sy/2+(q2+1)/2;
		if(!check(x,y)) check(xx,y),check(x,yy);
		else check(xx,yy);
	}
	return 0;
}