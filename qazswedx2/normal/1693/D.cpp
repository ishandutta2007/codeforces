#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
struct pt
{
	int l,r,v;
	pt(int l=0,int r=0,int v=0):l(l),r(r),v(v){} 
}q1[1000005],q2[1000005];
int n,a[1000005],head1,tail1,head2,tail2;
int getins(int x)
{
	int nwl=q1[tail1].r+1,nwr=nwl-1;
	while(head1<=tail1&&q1[tail1].v<=x)
	{
		nwl=q1[tail1].l;
		tail1--;
	}
	q1[++tail1]=pt(nwl,nwr,x);
	return nwl;
}
int getdes(int x)
{
	int nwl=q2[tail2].r+1,nwr=nwl-1;
	while(head2<=tail2&&q2[tail2].v>=x)
	{
		nwl=q2[tail2].l;
		tail2--;
	}
	q2[++tail2]=pt(nwl,nwr,x);
	return nwl;
}
void F(int lim)
{
	while(head1<=tail1)
	{
		if(q1[head1].l>lim) break;
		if(q1[head1].r>lim)
		{
			q1[head1].l=lim+1;
			break;
		}
		head1++;
	}
	while(head2<=tail2)
	{
		if(q2[head2].l>lim) break;
		if(q2[head2].r>lim)
		{
			q2[head2].l=lim+1;
			break;
		}
		head2++;
	}
}
void modifyins(int lim,int x)
{
	int d=0,nwl=q1[head1].l;
	if(nwl>lim) return;
	while(head1<=tail1)
	{
		if(q1[head1].l>lim) break;
		if(q1[head1].v>x)
			d=min(q1[head1].r,lim);
		if(q1[head1].r>lim)
		{
			q1[head1].l=lim+1;
			break;
		}
		head1++;
	}
	q1[--head1]=pt(nwl,lim,x);
	F(d);
}
void modifydes(int lim,int x)
{
	int d=0,nwl=q2[head2].l;
	if(nwl>lim) return;
	while(head2<=tail2)
	{
		if(q2[head2].l>lim) break;
		if(q2[head2].v<x)
			d=min(q2[head2].r,lim);
		if(q2[head2].r>lim)
		{
			q2[head2].l=lim+1;
			break;
		}
		head2++;
	}
	q2[--head2]=pt(nwl,lim,x);
	F(d);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); 
	}
	int nw=0;
	ll ans=0;
	head1=head2=5e5;
	tail1=tail2=head1-1;
	for(int i=1;i<n;i++)
	{
		q1[++tail1]=pt(i,i,-1e9);
		q2[++tail2]=pt(i,i,1e9);
		if(a[i]<a[i+1])
		{
			int u=getins(a[i]);
			modifydes(u-1,a[i]);
		}
		else
		{
			int u=getdes(a[i]);
			modifyins(u-1,a[i]);
		}
	/*	printf("i=%d,%d\n",i,q1[head1].l);
		for(int j=head1;j<=tail1;j++)
			printf("(%d,%d,%d) ",q1[j].l,q1[j].r,q1[j].v);
		printf("\n");
		for(int j=head2;j<=tail2;j++)
			printf("(%d,%d,%d) ",q2[j].l,q2[j].r,q2[j].v);
		printf("\n");*/
		ans+=i-q1[head1].l+1;
	}
	q1[++tail1]=pt(n,n,-1e9);
	q2[++tail2]=pt(n,n,1e9);
	while(head1<=tail1&&q1[head1].v>a[n]) head1++;
	while(head2<=tail2&&q2[head2].v<a[n]) head2++;
//	printf("min=%d,%d\n",q1[head1].l,q2[head2].l);
	ans+=n-min(q1[head1].l,q2[head2].l)+1;
	printf("%lld\n",ans);
	return 0; 
}