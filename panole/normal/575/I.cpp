#include<bits/stdc++.h>
using namespace std;

int t[5010][10010];

void add(int x,int y,int v)
{
	for (int Y=y; x<=5000; x+=(x&-x))
		for (y=Y; y<=10000; y+=(y&-y)) t[x][y]+=v;
}

void cle(int x,int y)
{
	for (int Y=y; x<=5000; x+=(x&-x))
		for (y=Y; y<=10000; y+=(y&-y)) t[x][y]=0;
}

int query(int x,int y)
{
	int ans=0;
	for (int Y=y; x; x-=(x&-x))
		for (y=Y; y; y-=(y&-y)) ans+=t[x][y];
	return ans;
}

int ans[100010],n,Q,ord;
struct node{int x,y,dir,len;}q[100010]; 

int main()
{
	scanf("%d%d",&n,&Q);
	for (int i=1; i<=Q; i++)
	{
		scanf("%d",&ord);
		if (ord==1) scanf("%d%d%d%d",&q[i].dir,&q[i].x,&q[i].y,&q[i].len);
		else scanf("%d%d",&q[i].x,&q[i].y),q[i].dir=0;
	}
	for (int i=1; i<=Q; i++)
	{
		if (!q[i].dir) ans[i]+=query(q[i].x,q[i].x+q[i].y); else
		if (q[i].dir==1) add(q[i].x,q[i].x+q[i].y+q[i].len+1,-1),add(q[i].x+q[i].len+1,q[i].x+q[i].y+q[i].len+1,1); else
		if (q[i].dir==4) add(q[i].x-q[i].len,q[i].x+q[i].y-q[i].len,1),add(q[i].x+1,q[i].x+q[i].y-q[i].len,-1);
	}
	for (int i=1; i<=Q; i++)
	{
		if (q[i].dir==1) cle(q[i].x,q[i].x+q[i].y+q[i].len+1),cle(q[i].x+q[i].len+1,q[i].x+q[i].y+q[i].len+1); else
		if (q[i].dir==4) cle(q[i].x-q[i].len,q[i].x+q[i].y-q[i].len),cle(q[i].x+1,q[i].x+q[i].y-q[i].len);
	}
	for (int i=1; i<=Q; i++)
	{
		if (!q[i].dir) ans[i]+=query(q[i].x,q[i].y-q[i].x+5000); else
		if (q[i].dir==2) add(q[i].x,q[i].y-q[i].x-q[i].len+5000,1),add(q[i].x+q[i].len+1,q[i].y-q[i].x-q[i].len+5000,-1); else
		if (q[i].dir==3) add(q[i].x-q[i].len,q[i].y-q[i].x+q[i].len+5001,-1),add(q[i].x+1,q[i].y-q[i].x+q[i].len+5001,1);
	}
	for (int i=1; i<=Q; i++)
	{
		if (q[i].dir==2) cle(q[i].x,q[i].y-q[i].x-q[i].len+5000),cle(q[i].x+q[i].len+1,q[i].y-q[i].x-q[i].len+5000); else
		if (q[i].dir==3) cle(q[i].x-q[i].len,q[i].y-q[i].x+q[i].len+5001),cle(q[i].x+1,q[i].y-q[i].x+q[i].len+5001);
	}
	for (int i=1; i<=Q; i++)
	{
		if (!q[i].dir) ans[i]+=query(q[i].x,q[i].y); else
		if (q[i].dir==1) add(q[i].x,q[i].y,1),add(q[i].x+q[i].len+1,q[i].y,-1); else
		if (q[i].dir==2) add(q[i].x,q[i].y+1,-1),add(q[i].x+q[i].len+1,q[i].y+1,1); else
		if (q[i].dir==3) add(q[i].x-q[i].len,q[i].y,1),add(q[i].x+1,q[i].y,-1); else
		if (q[i].dir==4) add(q[i].x-q[i].len,q[i].y+1,-1),add(q[i].x+1,q[i].y+1,1);
	}
	for (int i=1; i<=Q; i++) if (!q[i].dir) printf("%d\n",ans[i]);
	return 0;
}