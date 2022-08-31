#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int v[3][3];
	pt(){memset(v,0x3f,sizeof(v));}
}sum[1000005];
pt operator*(const pt x,const pt y)
{
	pt z;
	for(int i=0;i<3;i++)
		for(int j=i;j<3;j++)
			for(int k=i;k<=j;k++)
				z.v[i][j]=min(z.v[i][j],x.v[i][k]+y.v[k][j]);
	return z;
}
pt F(int c)
{
	pt ans;
	for(int i=0;i<3;i++)
		for(int j=i;j<3;j++)
			if(i==c-'a')
				ans.v[i][j]=1;
			else ans.v[i][j]=0;
	return ans;
}
int n,m;
char a[1000005];
void pushup(int x)
{
	sum[x]=sum[x*2]*sum[x*2+1];
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=F(a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=F(v);
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int x;
		char ch;
		scanf("%d %c",&x,&ch);
		modify(1,1,n,x,ch);
		int ans=1e9;
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				ans=min(ans,sum[1].v[j][k]);
		printf("%d\n",ans);
	}
	return 0;
}