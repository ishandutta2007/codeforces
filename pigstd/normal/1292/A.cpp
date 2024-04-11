#include<bits/stdc++.h>
using namespace std;
 
const int M=1e5+10;
int n,q,sum[3][M];
bool flag[3][M];
 
int d(int a)
{
	if (a==1)
		return 2;
	else
		return 1;
}
 
int f(int x,int y)
{
	return (x-1)*n+y;
}
 
struct node
{
	int tl,tr,sum;
}a[4*2*M];
 
void build(int k,int l,int r)
{
	a[k].tl=l,a[k].tr=r;
	if (l==r)
		return;
	int Mid=(l+r)>>1;
	build(k<<1,l,Mid);
	build(k<<1|1,Mid+1,r);
}
 
void add(int k,int l,int z)
{
	if (l>a[k].tr||l<a[k].tl)
		return;
	if (l==a[k].tl&&l==a[k].tr)
	{
		a[k].sum+=z;
		return;
	}
	add(k<<1,l,z),add(k<<1|1,l,z);
	a[k].sum=max(a[k<<1].sum,a[k<<1|1].sum);
}
 
int quary(int k,int l,int r)
{
	if (l>a[k].tr||r<a[k].tl)
		return 0;
	if (l<=a[k].tl&&r>=a[k].tr)
		return a[k].sum;
	return max(quary(k<<1,l,r),quary(k<<1|1,l,r));
}
 
int main()
{
	scanf("%d%d",&n,&q);
	build(1,1,n);
	for (int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int k=f(x,y);
		if (!flag[x][y])
		{
			flag[x][y]=1;
			if (flag[d(x)][y-1])
				add(1,f(d(x),y-1),1),add(1,k,1);
			if (flag[d(x)][y])
				add(1,f(d(x),y),1),add(1,k,1);
			if (flag[d(x)][y+1])
				add(1,f(d(x),y+1),1),add(1,k,1);
		}
		else
		{
			flag[x][y]=0;
			if (flag[d(x)][y-1])
				add(1,f(d(x),y-1),-1),add(1,k,-1);
			if (flag[d(x)][y])
				add(1,f(d(x),y),-1),add(1,k,-1);
			if (flag[d(x)][y+1])
				add(1,f(d(x),y+1),-1),add(1,k,-1);
		}
		int q=quary(1,1,f(2,n));
		if (q==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}