#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int l,r,id;
}a[1000005],b[1000005];
bool cmp(const pt x,const pt y)
{
	return x.l>y.l;
}
int n,at,bt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		pt x;
		scanf("%d%d",&x.l,&x.r);
		x.id=i;
		if(x.l<x.r) a[++at]=x;
		else b[++bt]=x;
	}
	if(at>=bt)
	{
		printf("%d\n",at);
		sort(a+1,a+at+1,cmp);
		for(int i=1;i<=at;i++)
			printf("%d ",a[i].id);
	}
	else
	{
		printf("%d\n",bt);
		sort(b+1,b+bt+1,cmp);
		for(int i=bt;i>0;i--)
			printf("%d ",b[i].id); 
	}
}