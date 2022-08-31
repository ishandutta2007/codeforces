#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans0[1000005];
int lsum[1000005],rsum[1000005],ans[1000005],ans1[1000005],ans2[1000005],ans3[1000005];
char s[1000005];
void pushup(int x)
{
	int ls=x*2,rs=x*2+1;
	lsum[x]=lsum[ls]+max(lsum[rs]-rsum[ls],0);
	rsum[x]=rsum[rs]+max(rsum[ls]-lsum[rs],0);
	ans[x]=max(ans[ls],ans[rs]);
	ans[x]=max(ans[x],ans1[ls]+ans2[rs]);
	ans[x]=max(ans[x],ans3[ls]+ans0[rs]);
	ans0[x]=max(ans0[ls],lsum[ls]-rsum[ls]+ans0[rs]);
	ans0[x]=max(ans0[x],lsum[ls]+rsum[ls]+ans2[rs]);
	ans1[x]=max(ans1[rs],rsum[rs]-lsum[rs]+ans1[ls]);
	ans1[x]=max(ans1[x],rsum[rs]+lsum[rs]+ans3[ls]);
	ans2[x]=max(ans2[ls],rsum[ls]-lsum[ls]+ans2[rs]);
	ans3[x]=max(ans3[rs],lsum[rs]-rsum[rs]+ans3[ls]);
}
void col(int x,int v)
{
	if(v==0)
	{
		lsum[x]=0;
		rsum[x]=1;
		ans[x]=ans0[x]=ans1[x]=ans2[x]=1;
		ans3[x]=0;
	}
	else
	{
		lsum[x]=1;
		rsum[x]=0;
		ans[x]=ans0[x]=ans1[x]=ans3[x]=1;
		ans2[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		col(x,s[l]==')');
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int qx)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		col(x,s[l]==')');
		return;
	} 
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx);
	modify(x*2+1,mid+1,r,qx);
	pushup(x);
}
void print(int x,int l,int r)
{
	printf("x=%d,l=%d,r=%d,sum=%d,%d,ans=%d,%d,%d,%d,%d\n",x,l,r,lsum[x],rsum[x],ans[x],ans0[x],ans1[x],ans2[x],ans3[x]);
	if(l==r) return;
	int mid=(l+r)/2;
	print(x*2,l,mid);
	print(x*2+1,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	n=2*n-2;
	scanf("%s",s+1);
	build(1,1,n);
	//print(1,1,n);
	printf("%d\n",ans[1]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		swap(s[x],s[y]);
		modify(1,1,n,x);
		modify(1,1,n,y);
		printf("%d\n",ans[1]);
	}
	return 0;
}