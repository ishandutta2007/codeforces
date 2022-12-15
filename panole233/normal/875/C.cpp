#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

using namespace std;

int head[100001],q[100001],ll,rr,cnt,in[100001],n,m,a[100001],l[100002],len[100001],x,cnt1,cnt2,e1[100001][2],e2[100001][2],ans[100001];
bool bo[100001];

int getmin(int a,int b) {return a<b?a:b;}

struct node
{
	int to,next;
}e[200001];

struct node2
{
	int x,y;
}aaa[200001];

void addedge(int x,int y)
{
	e[++cnt].next=head[x];
	head[x]=cnt;
	e[cnt].to=y; in[y]++;
}

bool cmp(node2 a,node2 b) {return a.y<b.y;}

int main()
{
	scanf("%d%d",&n,&m); l[0]=0; len[0]=1;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&len[i]); l[i]=l[i-1]+len[i-1];
		for (int j=l[i]; j<l[i]+len[i]; j++) scanf("%d",&a[j]);
	}
	cnt1=cnt2=0;
	for (int i=1; i<n; i++)
	{
		bool b=0;
		x=getmin(len[i],len[i+1]);
		for (int j=0; j<x; j++)
		{
			if (a[j+l[i]]<a[j+l[i+1]]) {b=1; e1[++cnt1][0]=a[j+l[i]]; e1[cnt1][1]=a[j+l[i+1]]; break;}
			else if (a[j+l[i]]>a[j+l[i+1]]) {b=1; e2[++cnt2][0]=a[j+l[i]]; e2[cnt2][1]=a[j+l[i+1]]; break;}
		}
		if (!b&&len[i]>len[i+1]) {printf("No\n"); return 0;}
	}
	cnt=0; memset(head,0,sizeof(head));
	memset(in,0,sizeof(in));
	for (int i=1; i<=cnt1; i++) addedge(e1[i][0],e1[i][1]);
	for (int i=1; i<=cnt2; i++) addedge(e2[i][0],e2[i][1]);
	ll=1; rr=0;
	for (int i=1; i<=m; i++)
		if (!in[i]) q[++rr]=i;
	while (ll<=rr)
	{
		x=q[ll];
		for (int i=head[x]; i; i=e[i].next)
		{
			in[e[i].to]--;
			if (!in[e[i].to]) q[++rr]=e[i].to;
		}
		ll++;
	}
	for (int i=1; i<=m; i++)
		if (in[i]) {printf("No\n"); return 0;}
	memset(bo,0,sizeof(bo));
	for (int i=1; i<=cnt2; i++) bo[e2[i][0]]=1;
	for (int i=1; i<=cnt1; i++) aaa[i].x=e1[i][0],aaa[i].y=e1[i][1];
	sort(aaa+1,aaa+1+cnt1,cmp);
	for (int i=cnt1; i>=1; i--)
		if (bo[aaa[i].y]) bo[aaa[i].x]=1;
	for (int i=1; i<=cnt2; i++)
		if (bo[e2[i][0]]&&bo[e2[i][1]]) {printf("No\n"); return 0;}
	ans[0]=0;
	for (int i=1; i<=m; i++)
		if (bo[i]) ans[++ans[0]]=i;
	printf("Yes\n%d\n",ans[0]);
	for (int i=1; i<=ans[0]; i++) printf("%d ",ans[i]); 
	return 0;
}