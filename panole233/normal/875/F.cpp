#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int fa[200001],p,q,n,m;
long long ans;
bool bo[200001];

struct node
{
	int a1,a2;
	long long x;
}a[200001];

bool cmp(node a,node b) {return a.x>b.x;}

int ask(int x) {return fa[x]==x?x:fa[x]=ask(fa[x]);}

int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1; i<=n; i++) scanf("%d%d%I64d",&a[i].a1,&a[i].a2,&a[i].x);
	sort(a+1,a+1+n,cmp); ans=0;
	memset(bo,1,sizeof(bo));
	for (int i=1; i<=m; i++) fa[i]=i;
	for (int i=1; i<=n; i++)
	{
		p=ask(a[i].a1); q=ask(a[i].a2);
		if (p==q) {if (bo[p]) bo[p]=0,ans+=a[i].x;}
		else 
		{
			if (bo[p]&&bo[q]) {fa[p]=q; ans+=a[i].x;} else
			if (bo[p]) {bo[p]=0; ans+=a[i].x;} else 
			if (bo[q]) {bo[q]=0; ans+=a[i].x;}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}