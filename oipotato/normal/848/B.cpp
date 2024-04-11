#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct data
{
	int id,p,t;
	friend bool operator <(data a,data b)
	{
		if(a.t-a.p!=b.t-b.p)
			return a.t-a.p<b.t-b.p;
		else
			return a.p<b.p;
	}
	int key(){return t-p;}
}s1[100010],s2[100010];
queue<int> q;
int n,w,h,n1,n2,x,ansx[100010],ansy[100010];
void work(int l1,int r1,int l2,int r2)
{
	for(int i=r2;i>=l2;i--)
		q.push(s2[i].id);
	for(int i=l1;i<=r1;i++)
	{
		int u=q.front();
		q.pop();
		ansx[u]=s1[i].p;
		ansy[u]=h;
		q.push(s1[i].id);
	}
	for(int i=r2;i>=l2;i--)
	{
		int u=q.front();
		q.pop();
		ansx[u]=w;
		ansy[u]=s2[i].p;
	}
}
int get1(int x)
{
	int y=x;
	for(;y<=n1&&s1[y].key()==s1[x].key();y++);
	return y-1;
}
int get2(int x)
{
	int y=x;
	for(;y<=n2&&s2[y].key()==s2[x].key();y++);
	return y-1;
}
int main()
{
	scanf("%d%d%d",&n,&w,&h);
	n1=n2=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			n1++;
			scanf("%d%d",&s1[n1].p,&s1[n1].t);
			s1[n1].id=i;
		}
		else
		{
			n2++;
			scanf("%d%d",&s2[n2].p,&s2[n2].t);
			s2[n2].id=i;
		}
	}
	sort(s1+1,s1+n1+1);
	sort(s2+1,s2+n2+1);
	int p1=1,p2=1;
	for(;p1<=n1||p2<=n2;)
		if(p1<=n1&&p2<=n2&&s1[p1].key()==s2[p2].key())
		{
			int q1=get1(p1),q2=get2(p2);
			work(p1,q1,p2,q2);
			p1=q1+1;
			p2=q2+1;
		}
		else if((p1<=n1&&p2<=n2&&s1[p1].key()<s2[p2].key())||p2>n2)
		{
			ansx[s1[p1].id]=s1[p1].p;
			ansy[s1[p1].id]=h;
			p1++;
		}
		else
		{
			ansx[s2[p2].id]=w;
			ansy[s2[p2].id]=s2[p2].p;
			p2++;
		}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}