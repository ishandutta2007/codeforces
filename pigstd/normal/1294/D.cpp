#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=4*1e5+10;
int q,x;

struct node
{
	int tl,tr,minn;
	int minid;
}a[4*M];

void cz(int k,node aa,node b)
{
	if (aa.minn<=b.minn)
		a[k].minn=aa.minn,a[k].minid=aa.minid;
	else
		a[k].minn=b.minn,a[k].minid=b.minid;
}

void build(int k,int l,int r)
{
	a[k].tl=l,a[k].tr=r;
	if (l==r)
	{
		a[k].minn=0;
		a[k].minid=l;
		return;
	}
	int Mid=(l+r)>>1;
	build(k<<1,l,Mid);
	build(k<<1|1,Mid+1,r);
	a[k].minid=l;
}

void add(int k,int l,int z)
{
	if (l>a[k].tr||l<a[k].tl)
		return;
	if (l==a[k].tl&&l==a[k].tr)
	{
		a[k].minn+=1;
		return;
	}
	add(k<<1,l,z);
	add(k<<1|1,l,z);
	cz(k,a[k<<1],a[k<<1|1]);
}

signed main()
{
	scanf("%lld%lld",&q,&x);
	build(1,1,x);
	while(q--)
	{
		int b;
		scanf("%lld",&b);
		b%=x;b++;
		add(1,b,1);
		printf("%lld\n",a[1].minn*x+a[1].minid-1);
	}
}