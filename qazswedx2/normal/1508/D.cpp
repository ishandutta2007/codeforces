#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y,id;
	pt(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
}a[100005];
int n,p[100005],f[100005],tans[1000005][2],t;
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
}
ll Cross(pt a,pt b)
{
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
bool operator<(const pt a,const pt b)
{
	if((a.y>0)!=(b.y>0)) return (a.y>0)>(b.y>0);
	return Cross(a,b)>0;
}
void modify(int x,int y)
{
	tans[++t][0]=x;
	tans[t][1]=y;
	swap(p[x],p[y]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&p[i]),a[i].id=i;
	int s=-1;
	for(int i=1;i<=n;i++)
		if(p[i]!=i)
		{
			s=i;
			break;
		}
	if(s==-1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=s+1;i<=n;i++)
		a[i].x-=a[s].x,a[i].y-=a[s].y;
	sort(a+s+1,a+n+1);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		link(i,p[i]);
	for(int i=s+1;i<=n;i++)
	{
		int j=i+1;
		if(i==n) j=s+1;
		if(Cross(a[i],a[j])<0||find(a[i].id)==find(a[j].id)) continue;
		link(a[i].id,a[j].id);
		modify(a[i].id,a[j].id);
	}
	while(p[s]!=s)
		modify(s,p[s]);
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d %d\n",tans[i][0],tans[i][1]);
	return 0;
}