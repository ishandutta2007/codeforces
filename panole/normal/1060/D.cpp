#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,h[100001],p[100001],len,x;
long long ans;

struct node
{
	int val,ord;
}a[100001];

void ins(int x,int po)
{
	h[++len]=x; p[len]=po;
	x=len; int y=(x>>1);
	while (y&&h[y]>h[x])
	{
		swap(h[x],h[y]); swap(p[x],p[y]);
		x=y; y=(x>>1);
	}
}

bool cmp(node a,node b) {return a.val<b.val;}

void pop()
{
	h[1]=h[len]; p[1]=p[len]; len--;
	int x=1,y=2;
	if (y<len&&h[y+1]<h[y]) y++;
	while (y<=len&&h[y]<h[x])
	{
		swap(h[x],h[y]);
		swap(p[x],p[y]);
		x=y; y=(x<<1);
		if (y<len&&h[y+1]<h[y]) y++;
	}
}

int main()
{
	scanf("%d",&n); len=0;
	ans=n;
	for (int i=1; i<=n; i++) scanf("%d%d",&x,&a[i].val),a[i].ord=i,ins(x,i),ans+=1ll*a[i].val;
	sort(a+1,a+1+n,cmp); 
	for (int i=1; i<=n; i++)
	{
		if (h[1]>a[i].val) ans+=1ll*(h[1]-a[i].val);
		pop();
	}
	printf("%I64d\n",ans);
	return 0;
}