#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){} 
	inline pt rotate(int fl)
	{
		if(fl==1) return *this;
		if(fl==2) return pt(n-y+1,x);
		if(fl==3) return pt(y,n-x+1);
		return pt(n-x+1,n-y+1);
	}
};
int sum[5005][10005],sum2[10005][5005],sum3[10005],q[100005][5],qt;
int tans[100005],st[1000005][4],tp;
inline int lowbit(int x)
{
	return x&-x;
}
void modify3(int x,int v)
{
	for(int i=x;i<=2*n;i+=lowbit(i))
		sum3[i]+=v;
}
int query3(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans+=sum3[i];
	return ans;
}
void modify(int x,int y,int v,int fl,int fl2=1)
{
//	printf("modify:x=%d,y=%d,v=%d,fl=%d\n",x,y,v,fl);
	if(fl2)
	{
		st[++tp][0]=x;
		st[tp][1]=y;
		st[tp][2]=v;
		st[tp][3]=fl;
	}
	if(!fl)
	{
		for(int i=x;i<=n;i+=lowbit(i))
			for(int j=y;j<=2*n;j+=lowbit(j))
				sum[i][j]+=v;
	}
	else
	{
		for(int i=x;i<=2*n;i+=lowbit(i))
			for(int j=y;j<=n;j+=lowbit(j))
				sum2[i][j]+=v;
	}
}
int query(int x,int y,int fl)
{
//	printf("query:x=%d,y=%d,fl=%d\n",x,y,fl);
	int ans=0;
	if(!fl)
	{
		for(int i=x;i;i-=lowbit(i))
			for(int j=y;j;j-=lowbit(j))
				ans+=sum[i][j];
	}
	else
	{
		for(int i=x;i;i-=lowbit(i))
			for(int j=y;j;j-=lowbit(j))
				ans+=sum2[i][j];
	}
	return ans;
}
void tmodify(int x,int xx,int y,int yy,int v,int fl)
{
	if(x>xx||y>yy) return;
	modify(x,y,v,fl),modify(xx+1,yy+1,v,fl);
	modify(x,yy+1,-v,fl),modify(xx+1,y,-v,fl);
}
void getans(int fl)
{
	memset(sum3,0,sizeof(sum3));
	tp=0;
	for(int i=1;i<=m;i++)
	{
	//	printf("i=%d,fl=%d\n",i,fl);
		if(q[i][0]==1)
		{
			if(q[i][1]!=fl) continue;
			pt p=pt(q[i][2],q[i][3]).rotate(fl);
			modify3(p.x+p.y,1);
			modify3(p.x+p.y+q[i][4]+1,-1);
			tmodify(1,p.x-1,p.x+p.y,p.x+p.y+q[i][4],-1,0);
			tmodify(p.x+p.y,p.x+p.y+q[i][4],1,p.y-1,-1,1);
		}
		else
		{
			pt p=pt(q[i][1],q[i][2]).rotate(fl);
		//	printf("i=%d,fl=%d,q=%d,%d,%d\n",i,fl,query3(p.x+p.y),query(p.x,p.x+p.y,0),query(p.x+p.y,p.y,1));
			tans[q[i][3]]+=query3(p.x+p.y)+query(p.x,p.x+p.y,0)+query(p.x+p.y,p.y,1);
		}
	}
	//for(int i=1;i<=qt;i++)
	//	printf("i=%d,ans=%d\n",i,tans[i]);
//	printf("tp=%d\n",tp);
	for(int i=1;i<=tp;i++)
	{
	//	printf("i=%d,tp=%d\n",i,tp);
		modify(st[i][0],st[i][1],-st[i][2],st[i][3],0);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&q[i][0]);
		if(q[i][0]==1) scanf("%d%d%d%d",&q[i][1],&q[i][2],&q[i][3],&q[i][4]);
		else scanf("%d%d",&q[i][1],&q[i][2]),q[i][3]=++qt;
	}
	getans(1),getans(2),getans(3),getans(4);
	for(int i=1;i<=qt;i++)
		printf("%d\n",tans[i]);
	return 0;
}